cmake_minimum_required(VERSION 3.10)

project(HyperScratch)

include_directories(${PROJECT_SOURCE_DIR})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu17 -g") #-fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g") #-fsanitize=address")


set(SRC_FILES
    "src/blocks/control.cpp"
    "src/blocks/sensing.cpp"
    "src/blocks/motion.cpp"
    "src/blocks/looks.cpp"
    "src/main.cpp"
    "src/render.cpp"
    "src/main_unix.cpp"
)

include_directories("include/")

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} 
    SDL2
    SDL2_image
    SDL2_mixer
)
