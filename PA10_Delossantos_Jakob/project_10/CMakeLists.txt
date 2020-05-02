cmake_minimum_required (VERSION 2.8.9)

project(proj10)

include_directories(include)

set(CMAKE_CXX_STANDARD 11)

add_executable(proj10 src/proj10.cpp)

target_link_libraries(proj10)

install(TARGETS proj10
RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")


