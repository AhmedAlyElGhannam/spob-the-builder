cmake_minimum_required(VERSION 3.22)

project(SPOB)

file(GLOB_RECURSE ${PROJECT_NAME}_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} "${${PROJECT_NAME}_SRC_FILES}")

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address -fno-omit-frame-pointer -O3 -Wall)

target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address)

target_link_libraries(${PROJECT_NAME} PRIVATE spob_memory spob_string)

