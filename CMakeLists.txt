cmake_minimum_required(VERSION 3.5)
project(snaze VERSION 0.1 LANGUAGES CXX )


### Executável
# Diretório contendo os .hpp
include_directories( include )

# Cria um executável com nome "snaze", adiciona neste executável os .cpp
add_executable( snaze
                src/Snaze.cpp
                src/SnakeGame.cpp
                src/Snake.cpp
                src/Player.cpp
                src/Level.cpp )

# The end