cmake_minimum_required(VERSION 3.27)
project(ActorSystem)

set(CMAKE_CXX_STANDARD 20)
include(CMakeLists.macro.cmake)

DOWNLOAD_REPOSITORY_FROM_GIT("fmt" "master" "https://github.com/fmtlib/fmt.git")

BUILD_ALL_DOWNLOADED_LIBRARIES()

BUILD_LIBRARY_FROM_OWN_CODE("code" "code")


add_executable(main main.cpp)
target_link_libraries(main code log4cpp "${PROJECT_SOURCE_DIR}/libs/fmt/libfmt.a")
