cmake_minimum_required(VERSION 3.20)
project(docker_monitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json CONFIG REQUIRED)
find_package(httplib CONFIG REQUIRED)

add_executable(docker_monitor main.cpp)

target_link_libraries(docker_monitor
    PRIVATE
    nlohmann_json::nlohmann_json
    httplib::httplib
)
