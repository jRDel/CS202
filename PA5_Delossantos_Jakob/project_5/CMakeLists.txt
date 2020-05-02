cmake_minimum_required (VERSION 2.8.9)

project(proj5)

include_directories(include)

set(PARENTCHILD_SOURCES src/ParentChild/Vehicle.cpp
			src/ParentChild/Car.cpp)
			
add_library(ParentChild ${PARENTCHILD_SOURCES})

add_executable(proj5 src/proj5.cpp)

target_link_libraries(proj5 ParentChild)

install(TARGETS proj5 ParentChild
RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

