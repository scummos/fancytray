project(tray)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)
enable_testing()

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(tray_SRCS tray.cpp main.cpp)
qt4_automoc(${tray_SRCS})
add_executable(tray ${tray_SRCS})
target_link_libraries(tray ${QT_QTCORE_LIBRARY})

add_subdirectory(tests)
