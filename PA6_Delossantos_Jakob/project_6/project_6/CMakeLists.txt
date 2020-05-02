cmake_minimum_required (VERSION 2.8.9)

project(proj6)

include_directories(include)

set(PARENTCHILD_SOURCES src/ParentChild/Vehicle.cpp
			src/ParentChild/Car.cpp)
			
add_library(ParentChild ${PARENTCHILD_SOURCES})

add_executable(proj6 src/proj6.cpp)

target_link_libraries(proj6 ParentChild)

install(TARGETS proj6 ParentChild
RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

