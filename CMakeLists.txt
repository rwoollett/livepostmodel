cmake_minimum_required(VERSION 3.16)
project(
  LivePostsModelProject VERSION 1.0
  DESCRIPTION "Live Posting service model structures."
  LANGUAGES CXX C
)

# set everything up for c++ 20 features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(livepostsmodel)

