cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(cpp-course)

find_package(Freetype REQUIRED)
find_package(JPEG REQUIRED)
find_package(SFML 2 COMPONENTS window graphics system REQUIRED)

add_subdirectory(cpp1.1)
add_subdirectory(cpp1.3)
add_subdirectory(cpp1.4)

add_subdirectory(sfml1.1)
add_subdirectory(sfml1.2)

add_subdirectory(sfml2.1)
add_subdirectory(sfml2.2)

add_subdirectory(sfml3.1)