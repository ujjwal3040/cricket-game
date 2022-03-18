cmake_minimum_required(VERSION 3.20)
project(cricket_game)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cricket_game
        "cricket game.dev"
        game-1[1].cpp
        game-1[1].h
        main[1].cpp
        player-1[1].cpp
        player-1[1].h
        Readme.txt.txt
        team-1[1].cpp
        team-1[1].h)
