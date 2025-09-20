cmake_minimum_required(VERSION 3.21)
project(pokemon)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(
        pokemon 
        ${SOURCES}        
        )
target_include_directories(pokemon PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}

    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)
target_link_libraries(
        pokemon
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)