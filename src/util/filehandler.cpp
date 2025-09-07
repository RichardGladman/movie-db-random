//
// Created by richard on 28.08.2025 
//
#include "util/filehandler.h"
#include "model/movierecord.h"
#include <filesystem>
#include <string>

#include <iostream>

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
