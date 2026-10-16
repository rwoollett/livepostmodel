cmake_minimum_required(VERSION 3.16)

# LivePostsModel services model structures (to enable using model structures in other applications)
add_library(LivePostsModel
  LivePosts.cpp
  LivePosts.h
  Events.h
  events/Actions.h
  events/json.h
  events/Subjects.h
  PostStatus.h
  json.h
  pq.cpp
  pq.h
)

target_include_directories(
  LivePostsModel PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/..
  $<INSTALL_INTERFACE:include>
  PRIVATE $<BUILD_INTERFACE:${LIBPQ_INCLUDE_DIRS}>
)

target_link_libraries(
  LivePostsModel 
  PRIVATE Timestamp
  ${LIBPQ_LIBRARIES}
)


