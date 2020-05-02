cmake_minimum_required (VERSION 2.8.9)

project(proj9)

include_directories(include)

set(CMAKE_CXX_STANDARD 11)

set(PROJ_SOURCES src/sourceFolder/DataType.cpp
	src/sourceFolder/ArrayQueue.cpp
	src/sourceFolder/NodeQueue.cpp)
			
add_library(libSource ${PROJ_SOURCES})

add_executable(proj9 src/proj9.cpp)

target_link_libraries(proj9 libSource)

install(TARGETS proj9 libSource
RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")


