cmake_minimum_required(VERSION 3.16)
set(This PenaItemGui)

set(SOURCES
    PaneItem.cpp
    PaneItem.h
)
set(CMAKE_CXX_STANDARD 11)
# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Make this a GUI application on Windows
# if(WIN32)   
#   set(CMAKE_WIN32_EXECUTABLE ON)
# endif()

set(CMAKE_PREFIX_PATH $ENV{Qt474Dir})
find_package(Qt4 REQUIRED QtCore QtGui)
include( ${QT_USE_FILE} )

add_library(${This} STATIC ${SOURCES})
# target_link_libraries(${This} Qt4::QtCore Qt4::QtGui)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
