cmake_minimum_required(VERSION 3.5)
project(Tetris)

find_package(FreeGLUT REQUIRED)
link_directories(Libraries/FreeGLUT/lib)

include_directories(Libraries/FreeGLUT/include)
include_directories(Source/Includes)

add_executable(App Source/App.cpp Source/Includes/game.cpp Source/Includes/engine.cpp)
# add_executable(App Source/App.cpp)
# add_executable(Test Tests/test.cpp)
target_link_libraries(App FreeGLUT::freeglut)
# target_link_libraries(Test FreeGLUT::freeglut)

