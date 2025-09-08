//
// Created by richard on 28.08.2025 
//
#include "util/filehandler.h"
#include "model/movierecord.h"
#include <filesystem>
#include <string>

#include <iostream>

#include "view/output.h"

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
    m_file.write(reinterpret_cast<const char*>(&record.record_length), sizeof(int));
    m_file.write(reinterpret_cast<const char*>(&record.title_length), sizeof(int));
    m_file.write(record.title.c_str(), record.title_length);
    m_file.write(reinterpret_cast<const char*>(&record.format_length), sizeof(int));
    m_file.write(record.format.c_str(), record.format_length);
    m_file.write(reinterpret_cast<const char*>(&record.certificate_length), sizeof(int));
    m_file.write(record.certificate.c_str(), record.certificate_length);
    m_file.write(reinterpret_cast<const char*>(&record.rating), sizeof(int));
    m_file.write(reinterpret_cast<const char*>(&record.running_time), sizeof(int));
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

    m_file.read(reinterpret_cast<char*>(&record_length), sizeof(int));
    if (!m_file.eof()) {
        m_file.read(reinterpret_cast<char*>(&title_length), sizeof(int));

        char t[title_length + 1];
        m_file.read(reinterpret_cast<char*>(&t), title_length);
        t[title_length] = '\0';
        title = t;

        m_file.read(reinterpret_cast<char*>(&format_length), sizeof(int));

        char f[format_length+1];
        m_file.read(reinterpret_cast<char*>(&f), format_length);
        f[format_length] = '\0';
        format = f;

        m_file.read(reinterpret_cast<char*>(&certificate_length), sizeof(int));
        char c[certificate_length + 1];
        m_file.read(reinterpret_cast<char*>(&c), certificate_length);
        c[certificate_length] = '\0';
        certificate = c;

        m_file.read(reinterpret_cast<char*>(&rating), sizeof(int));
        m_file.read(reinterpret_cast<char*>(&running_time), sizeof(int));

        return MovieRecord {title, format, certificate, rating, running_time};
    }

    return MovieRecord { "", "", "", 0, 0 };
}

MovieRecord FileHandler::find(std::string title)
{
    m_file.seekg(0, std::ios::beg);
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
    FileHandler::create_data_file(database_name + "__temp");
    outfile.open(database_name + "__temp");
    
    while (!infile.eof()) {
        MovieRecord record = infile.read();
        if (!infile.eof()) {
            if (record.title.starts_with(title)) {
                continue;
            }
            
            outfile.write(record);
        }
    }
    
    outfile.close();
    infile.close();
    
    std::remove(database_name.c_str());
    std::filesystem::rename((database_name + "__temp").c_str(), database_name.c_str());

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
