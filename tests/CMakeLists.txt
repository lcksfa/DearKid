cmake_minimum_required(VERSION 3.6)
set(ThisTest TddUnitTest)

set(SOURCES
  #  TddGuiTest.cpp
   TestSharedFolders.cpp)

include_directories(${PROJECT_SOURCE_DIR}/src)
add_executable(${ThisTest} ${SOURCES})

set(CMAKE_PREFIX_PATH $ENV{Qt474Dir})
find_package(Qt4 REQUIRED QtCore QtGui QtTest)
include( ${QT_USE_FILE} )


# Make this a GUI application on Windows
if(WIN32)   
  set(CMAKE_WIN32_EXECUTABLE ON)
endif()

target_link_libraries(${ThisTest} PUBLIC
    gtest_main
    # PenaItemGui 
    # Qt4::QtTest
    sharedfolder
    Qt4::QtCore
    Qt4::QtGui
   )

add_test(
    NAME ${ThisTest}
    COMMAND ${ThisTest}
)