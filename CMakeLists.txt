cmake_minimum_required(VERSION 3.25)

project(learning_demo)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third_party/boost)

add_subdirectory(DynamicObject)
add_subdirectory(ReflectionFunction)