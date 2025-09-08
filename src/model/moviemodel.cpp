//
// Created by richard on 07.09.2025 
//
#include "model/moviemodel.h"
#include "model/movierecord.h"
#include "util/filehandler.h"

extern std::string database_name;

MovieModel::MovieModel(std::string title, std::string format, std::string certificate, int rating, int running_time):
    m_title {title}, m_format {format}, m_certificate {certificate}, m_rating {rating}, m_running_time {running_time}
{

}

MovieModel::MovieModel(std::string title): MovieModel {title, "", "", 0, 0}
{

}

MovieModel::MovieModel(): MovieModel {"", "", "", 0, 0}
{

}

std::string MovieModel::title() const
{
    return m_title;
}

std::string MovieModel::format() const
{
    return m_format;
}

std::string MovieModel::certificate() const
{
    return m_certificate;
}

int MovieModel::rating() const
{
    return m_rating;
}

int MovieModel::running_time() const
{
    return m_running_time;
}

void MovieModel::title(std::string title)
{
    m_title = title;
}

void MovieModel::format(std::string format)
{
    m_format = format;
}

void MovieModel::certificate(std::string certificate)
{
    m_certificate = certificate;
}

void MovieModel::rating(int rating)
{
    m_rating = rating;
}

void MovieModel::running_time(int running_time)
{
    m_running_time = running_time;
}

void MovieModel::save()
{
    FileHandler file {};
    file.open(database_name);

    MovieRecord record {m_title, m_format, m_certificate, m_rating, m_running_time};

    file.write(record);
    file.close();
}
