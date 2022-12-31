cmake_minimum_required(VERSION 3.25)

# here we specify that the project is C language only, so the default
# C compiler on the system will be used
project(gtk-gui C)
# Create the compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

## Got these two lines from: https://stackoverflow.com/q/32507252
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED "gtk+-3.0")

## Needed to add the following to lines and the target_link_libraries found from
# https://forums.raspberrypi.com/viewtopic.php?t=191117#p1200001
include_directories(${GTK_INCLUDE_DIRS})
set(LIBS ${LIBS} ${GTK_LIBRARIES})

# Use glob for multiple files with this shortcut
# files(GLOB SOURCES "src/*.c")
# add_executable(gtk-gui ${SOURCES})

add_executable(gtk-gui src/main.c)
target_link_libraries(gtk-gui ${LIBS})
