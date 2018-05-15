cmake_minimum_required(VERSION 3.9)
project(project-pyros)

set(CMAKE_CXX_STANDARD 11)

add_executable(project-pyros main.cpp main.cpp Game.cpp Game.h MainMenu.cpp MainMenu.h Button.h Button.cpp SplashScreen.cpp SplashScreen.h)


<<<<<<< HEAD
=======
configure_file(Splashscreen.png Splashscreen.png COPYONLYPel)
>>>>>>> a49ded7547dbd5132c533c68a45bf7522c766416

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake-modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(project-pyros ${SFML_LIBRARIES})
endif()