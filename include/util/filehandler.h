#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#pragma once

#include "model/movierecord.h"
#include <string>
#include <fstream>

class FileHandler
{
public:
    static void create_directories(std::string path);
    static void create_data_file(std::string filename);

    void open(const std::string &filename);
    void write(const MovieRecord record);
    void write(const char *data, int length, const char mode = 'A');
    void read(char *data, int length);
    void close();

    int get_pos();
    bool eof();


private:
    std::fstream m_file;
};

#endif