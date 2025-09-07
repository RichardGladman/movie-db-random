find_package(ansicodes REQUIRED)

add_executable(ProjectName main.cpp
                view/input.cpp view/output.cpp
                menu/option.cpp menu/menu.cpp
               util/filehandler.cpp)

target_include_directories(ProjectName PUBLIC ${CMAKE_SOURCE_DIR}/include /usr/local/include/ansicodes)

target_link_libraries(ProjectName PRIVATE ansicodes::ansicodes_lib)
