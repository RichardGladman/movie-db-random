#include "model/moviemodel.h"
#include "model/movierecord.h"
#include "util/filehandler.h"
#include "util/text.h"
#include "view/output.h"
#include <string>

extern std::string database_name;

std::vector<MovieModel> MovieModel::all()
{
    std::vector<MovieModel> movies {};
    FileHandler file;

    file.open(database_name);

    while (!file.eof()) {
        MovieRecord record = file.read();
        if (!file.eof()) {
            MovieModel model {record.title, record.format, record.certificate, record.rating, record.running_time};
            movies.push_back(model);
        }
    }

    file.close();

    return movies;
}

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

MovieModel MovieModel::load(std::string title)
{
    FileHandler file {};
    MovieModel model {};

    file.open(database_name);

    MovieRecord record = file.find(title);
    if (record.title.starts_with(title)) {
        model.m_title = record.title;
        model.m_format = record.format;
        model.m_certificate = record.certificate;
        model.m_rating = record.rating;
        model.m_running_time = record.running_time;
    }

    return model;
}

void MovieModel::remove(std::string title)
{
    FileHandler file {};
    file.open(database_name);
    file.remove(title);
    file.close();
}

void MovieModel::print()
{
    std::string data {};

    data = m_title + Text::spaces(50, m_title.length());
    data += m_format + Text::spaces(10, m_format.length());
    data += m_certificate + Text::spaces(10, m_certificate.length());
    data += Text::spaces(4, 0) + std::to_string(m_rating);
    data += Text::spaces(3, 0) + std::to_string(m_running_time);

    Output::plain_text(data, true);
}