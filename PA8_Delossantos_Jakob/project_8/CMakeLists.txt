cmake_minimum_required (VERSION 2.8.9)

project(proj8)

include_directories(include)

set(CMAKE_CXX_STANDARD 11)

set(PROJ_SOURCES src/sourceFolder/DataType.cpp
	src/sourceFolder/ArrayList.cpp
	src/sourceFolder/NodeList.cpp)
			
add_library(libSource ${PROJ_SOURCES})

add_executable(proj8 src/proj8.cpp)

target_link_libraries(proj8 libSource)

install(TARGETS proj8 libSource
RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")


