#ifndef MOVIE_MODEL_H
#define MOVIE_MODEL_H

#pragma once

#include <istream>
#include <iostream>
#include <string>

class MovieModel
{
public:
    MovieModel(std::string title, std::string format, std::string certificate, int rating, int running_time);
    MovieModel(std::string title);
    MovieModel();

    std::string get_title() const;
    std::string get_format() const;
    std::string get_certificate() const;
    int get_rating() const;
    int get_running_time() const;

private:
    std::string title;
    std::string format;
    std::string certificate;
    int rating;
    int running_time;
};

#endif