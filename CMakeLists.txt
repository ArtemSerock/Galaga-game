cmake_minimum_required(VERSION 4.2.3)
project(Galaga LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

message(STATUS "Version CMAKE: ${CMAKE_VERSION}")

FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL
  GIT_TAG        main 
)
FetchContent_Declare(
    SDL3_image
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_image
  GIT_TAG        main 
)
FetchContent_MakeAvailable(SDL3 SDL3_image)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(Galaga ${SOURCES})

target_include_directories(Galaga PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Galaga PRIVATE SDL3::SDL3 SDL3_image)

add_custom_command(TARGET Galaga POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/assets
    ${CMAKE_CURRENT_BINARY_DIR}/assets
)
