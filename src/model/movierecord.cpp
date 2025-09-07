#include "model/movierecord.h"

MovieRecord::MovieRecord(std::string title, std::string format, std::string certificate, int rating, int running_time)
{
    this->title = title;
    this->title_length = title.length();

    this->format = format;
    this->format_length = format.length();

    this->certificate = certificate;
    this->certificate_length = certificate.length();

    this->rating = rating;
    this->running_time = running_time;

    this->record_length = sizeof(int) + sizeof(int) + title_length + sizeof(int) + format_length + sizeof(int) +
                    certificate_length + sizeof(int) + sizeof(int);
}

MovieModel MovieRecord::make_model()
{
    return MovieModel {title, format, certificate, rating, running_time};
}
