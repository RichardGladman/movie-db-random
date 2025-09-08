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
