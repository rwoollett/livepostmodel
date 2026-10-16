cmake_minimum_required(VERSION 3.16)
project(
  LivePostsModelProject VERSION 1.0
  DESCRIPTION "Live Posting service model structures."
  LANGUAGES CXX C
)

# set everything up for c++ 20 features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBPQ REQUIRED libpq)
if(LIBPQ_FOUND)
  message("-- libpq found via pkg-config")
  message("-- Include dirs: ${LIBPQ_INCLUDE_DIRS}")
  message("-- Libraries: ${LIBPQ_LIBRARIES}")
  add_compile_definitions(LIBPQ_FOUND)
else()
  message(FATAL_ERROR "libpq not found via pkg-config")
endif()

include(FetchContent)

FetchContent_Declare(
  Timestamp
  GIT_REPOSITORY https://github.com/rwoollett/timestamp.git
  GIT_TAG master
)
FetchContent_MakeAvailable(Timestamp)

get_target_property(TS_INCLUDES Timestamp INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "Timestamp includes: ${TS_INCLUDES}")

add_subdirectory(livepostsmodel)

get_target_property(
    LP_INCLUDES
    LivePostsModel
    INCLUDE_DIRECTORIES
)

message(STATUS "LivePostsModel includes: ${LP_INCLUDES}")
