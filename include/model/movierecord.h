#ifndef MOVIE_RECORD_H
#define MOVIE_RECORD_H

#pragma once

#include <string>

#include "model/moviemodel.h"

struct MovieRecord
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

    MovieRecord(std::string title, std::string format, std::string certificate, int rating, int running_time);
    MovieRecord();

    MovieModel make_model();
};

#endif
