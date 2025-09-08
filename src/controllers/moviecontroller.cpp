//
// Created by richard on 07.09.2025 
//
#include "controllers/moviecontroller.h"

#include <memory>
#include <string>

#include "model/moviemodel.h"
#include "view/input.h"
#include "view/output.h"

void MovieController::add()
{
    std::unique_ptr<MovieModel> model = std::make_unique<MovieModel>();

    model->title(Input::get_text("Enter the movie title"));
    model->format(Input::get_text("Enter the movie format"));
    model->certificate(Input::get_text("Enter the movie certificate"));
    model->rating(Input::get_integer("Enter the movie rating"));
    int running_time = Input::get_integer("Enter the movie running time");
    model->running_time(running_time);
    
    model->save();

    Output::success_message("Movie has been saved");

}

void MovieController::edit()
{
    std::string title = Input::get_text("Enter title to edit");
    MovieModel model = MovieModel::load(title);

    if (model.title() == "") {
        Output::error_message("That title was not found");
        return;
    }

    model.title(Input::get_text("Enter new title (blank for current) [" + model.title() + "]"));
    model.format(Input::get_text("Enter new format (blank for current) [" + model.format() + "]"));
    model.certificate(Input::get_text("Enter new certificate (blank for current) [" + model.certificate() + "]"));
    model.rating(Input::get_integer("Enter new rating (blank for current) [" + std::to_string(model.rating()) + "]"));
    model.running_time(Input::get_integer("Enter new running time (blank for current) [" + std::to_string(model.running_time()) + "]"));

    MovieModel::remove(title);
    model.save();

    Output::success_message("Movie has been updated");
}

void MovieController::remove()
{
    std::string title = Input::get_text("Enter title to delete");
    MovieModel model = MovieModel::load(title);

    if (model.title() == "") {
        Output::error_message("That title was not found");
        return;
    }

    MovieModel::remove(title);

    Output::success_message("Movie has been deleted");
}