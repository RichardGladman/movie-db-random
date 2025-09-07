//
// Created by richard on 28.08.2025 
//
#include "util/filehandler.h"
#include "model/movierecord.h"
#include <filesystem>
#include <string>

#include <iostream>

extern std::string database_name;

void FileHandler::create_directories(std::string path)
{
    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directories(path);
    }
}

void FileHandler::create_data_file(std::string filename)
{
    if (!std::filesystem::exists(filename)) {
        std::ofstream file {filename};
    }
}

void FileHandler::open(const std::string &filename)
{
    m_file.open(filename.data(), std::ios::binary | std::ios::in | std::ios::out);
}

void FileHandler::write(const char *data, int length, const char mode)
{
    if (mode == 'A') {
        m_file.seekp(0, std::ios::end);
    }

    m_file.write(data, length);
}

void FileHandler::write(const MovieRecord record)
{
    m_file.seekp(0, std::ios::end);
    m_file.write(reinterpret_cast<char*>(record.record_length), sizeof(int));
    m_file.write(reinterpret_cast<char*>(record.title_length), sizeof(int));
    m_file.write(record.title.c_str(), record.title_length);
    m_file.write(reinterpret_cast<char*>(record.format_length), sizeof(int));
    m_file.write(record.format.c_str(), record.format_length);
    m_file.write(reinterpret_cast<char*>(record.certificate_length), sizeof(int));
    m_file.write(record.certificate.c_str(), record.certificate_length);
    m_file.write(reinterpret_cast<char*>(record.rating), sizeof(int));
    m_file.write(reinterpret_cast<char*>(record.running_time), sizeof(int));
}

void FileHandler::read(char *data, int length)
{
    m_file.read(data, length);
}

MovieRecord FileHandler::read()
{
    int record_length;
    int title_length;
    std::string title;
    int format_length;
    std::string format;
    int certificate_length;
    std::string certificate;
    int rating;
    int running_time;

    m_file.read(reinterpret_cast<char*>(record_length), sizeof(int));
    m_file.read(reinterpret_cast<char*>(title_length), sizeof(int));
    m_file.read(title.data(), title_length);
    m_file.read(reinterpret_cast<char*>(format_length), sizeof(int));
    m_file.read(format.data(), format_length);
    m_file.read(reinterpret_cast<char*>(certificate_length), sizeof(int));
    m_file.read(certificate.data(), certificate_length);
    m_file.read(reinterpret_cast<char*>(rating), sizeof(int));
    m_file.read(reinterpret_cast<char*>(running_time), sizeof(int));

    return MovieRecord {title, format, certificate, rating, running_time};
}

MovieRecord FileHandler::find(std::string title)
{
    while (!m_file.eof()) {
        MovieRecord record = read();
        if (record.title.starts_with(title)) {
            return record;
        }
    }

    return MovieRecord {};
}

void FileHandler::remove(std::string title)
{
    FileHandler outfile;
    FileHandler infile;
    infile.open(database_name);
    outfile.open(database_name.erase(database_name.length() - 11) + "__temp");

    while (!infile.eof()) {
        MovieRecord record = infile.read();
        if (record.title.starts_with(title)) {
            continue;
        }

        outfile.write(record);
    }

    infile.close();
    outfile.close();

    std::remove(database_name.c_str());
    std::rename((database_name.erase(database_name.length() - 11) + "__temp").c_str(), database_name.c_str())

}

void FileHandler::close()
{
    m_file.close();
}

int FileHandler::get_pos()
{
    return m_file.tellp();
}

bool FileHandler::eof()
{
    return m_file.eof();
}
