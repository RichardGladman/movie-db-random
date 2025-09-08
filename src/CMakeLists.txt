find_package(ansicodes REQUIRED)

add_executable(moviedb main.cpp
                view/input.cpp view/output.cpp
                menu/option.cpp menu/menu.cpp
               util/filehandler.cpp model/moviemodel.cpp
               model/movierecord.cpp controllers/moviecontroller.cpp)

target_include_directories(moviedb PUBLIC ${CMAKE_SOURCE_DIR}/include /usr/local/include/ansicodes)

target_link_libraries(moviedb PRIVATE ansicodes::ansicodes_lib)
