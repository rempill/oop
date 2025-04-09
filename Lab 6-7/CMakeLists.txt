cmake_minimum_required(VERSION 3.28)
project(Lab_6_7)

set(CMAKE_CXX_STANDARD 20)
file(GLOB_RECURSE HEADER_DIRS RELATIVE ${CMAKE_SOURCE_DIR} *.h)
foreach(HEADER_FILE ${HEADER_DIRS})
    get_filename_component(HEADER_DIR ${HEADER_FILE} PATH)
    include_directories(${HEADER_DIR})
endforeach()
add_executable(Lab_6_7 main.cpp
        Domain/locatar.cpp
        Domain/locatar.h
        Repository/repo.cpp
        Repository/repo.h
        Validator/validator.cpp
        Validator/validator.h
        Controller/service.cpp
        Controller/service.h
        Errors/errors.h
        UI/console.cpp
        UI/console.h
        Utils/tools.cpp
        Utils/tools.h
        Tests/tests.cpp
        Tests/tests.h
        Domain/linked_list.h
)
