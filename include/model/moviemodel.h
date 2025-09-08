#ifndef MOVIE_MODEL_H
#define MOVIE_MODEL_H

#pragma once

#include <string>

class MovieModel
{
public:
    MovieModel(std::string title, std::string format, std::string certificate, int rating, int running_time);
    MovieModel(std::string title);
    MovieModel();

    std::string title() const;
    std::string format() const;
    std::string certificate() const;
    int rating() const;
    int running_time() const;

    void title(std::string title);
    void format(std::string format);
    void certificate(std::string certificate);
    void rating(int rating);
    void running_time(int running_time);

    void save();

private:
    std::string m_title;
    std::string m_format;
    std::string m_certificate;
    int m_rating;
    int m_running_time;
};

#endif