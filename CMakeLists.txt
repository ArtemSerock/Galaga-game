cmake_minimum_required(VERSION 4.2.3)
project(Galaga LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

message(STATUS "Version CMAKE: ${CMAKE_VERSION}")

FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL
  GIT_TAG release-3.4.x  
)
FetchContent_Declare(
    SDL3_image
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_image
  GIT_TAG        main 
)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG master
)

FetchContent_MakeAvailable(SDL3 SDL3_image json)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(Galaga ${SOURCES})

target_include_directories(Galaga PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Galaga PRIVATE SDL3::SDL3 SDL3_image nlohmann_json::nlohmann_json)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/src/configs" 
     DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/assets" 
     DESTINATION "${CMAKE_BINARY_DIR}")


