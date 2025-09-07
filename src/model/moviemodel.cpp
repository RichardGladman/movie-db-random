//
// Created by richard on 07.09.2025 
//
#include "model/moviemodel.h"

MovieModel::MovieModel(std::string title, std::string format, std::string certificate, int rating, int running_time):
    title {title}, format {format}, certificate {certificate}, rating {rating}, running_time {running_time}
{

}

MovieModel::MovieModel(std::string title): MovieModel {title, "", "0""", 0, 0}
{

}

MovieModel::MovieModel(): MovieModel {"", "", "0""", 0, 0}
{

}

std::string MovieModel::get_title() const
{
    return title;
}

std::string MovieModel::get_format() const
{
    return format;
}

std::string MovieModel::get_certificate() const
{
    return certificate;
}

int MovieModel::get_rating() const
{
    return rating;
}

int MovieModel::get_running_time() const
{
    return running_time;
}

