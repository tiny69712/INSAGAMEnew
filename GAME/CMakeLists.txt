cmake_minimum_required(VERSION 3.17)
project(INSAGAME C)


set(CMAKE_C_STANDARD 90)

if (WIN32)
    message ([STATUS]" os Windows")
    include_directories(include)

    set(SDL2_INCLUDE_DIR C:/TDM-GCC-64/x86_64-w64-mingw32/include)
    set(SDL2_LIB_DIR C:/TDM-GCC-64/x86_64-w64-mingw32/lib)

    file(GLOB_RECURSE SOURCES "src/*c" main.c)
    add_executable(INSAGAME ${SOURCES})
    target_link_libraries(${PROJECT_NAME} mingw32 SDL2main SDL2 SDL2_image)


else(APPLE)
    message([STATUS] "os Mac")

    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

    find_package( SDL2 REQUIRED )


    include_directories( ${SDL2_INCLUDE_DIRS} "/usr/local/Cellar/sdl2_image/2.0.5/include/SDL2" "include" )

    file(GLOB_RECURSE SOURCES "src/*c" main.c)
    add_executable(INSAGAME ${SOURCES} include/GAME.c include/GAME.h)
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} "-L/usr/local/Cellar/sdl2_image/2.0.5/lib  -lSDL2")




endif()




