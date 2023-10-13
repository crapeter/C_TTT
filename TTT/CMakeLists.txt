cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

include_directories(/home/crapeter/c_projects/TTT/include)

add_executable(ttt main.c logic.c ui.c)
