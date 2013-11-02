project(tray)
cmake_minimum_required(VERSION 2.6)
find_package(Qt 4.5 REQUIRED)

find_package(X11)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ${X11_INCLUDE_DIR})

set(tray_SRCS extratrayicon.cpp main.cpp)
qt4_automoc(${tray_SRCS})
add_executable(fancytray ${tray_SRCS} ${moc_headers})
target_link_libraries(fancytray ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${X11_LIBRARIES})

install(TARGETS fancytray RUNTIME DESTINATION bin)
