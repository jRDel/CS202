cmake_minimum_required (VERSION 2.8.9)

project(proj7)

include_directories(include)

set(STRING_SOURCES src/String/MyString.cpp)
			
add_library(String ${STRING_SOURCES})

add_executable(proj7 src/proj7.cpp)

target_link_libraries(proj7 String)

install(TARGETS proj7 String
RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")


