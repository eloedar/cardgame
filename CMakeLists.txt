cmake_minimum_required(VERSION 3.22)
project(cardgame)

set(CMAKE_CXX_STANDARD 14)

add_executable(cardgame main.cpp card.cpp player.cpp exchange_card.cpp exchange_card.h big_boss_card.cpp big_boss_card.h game_control.cpp game_control.h)
