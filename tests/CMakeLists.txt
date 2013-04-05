
include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})
set(trayTest_SRCS trayTest.cpp)
qt4_automoc(${trayTest_SRCS})
add_executable(trayTest ${trayTest_SRCS})
add_test(trayTest trayTest)
target_link_libraries(trayTest ${QT_QTTEST_LIBRARY})
