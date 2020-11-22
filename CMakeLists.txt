cmake_minimum_required(VERSION 3.16)
set(ProjectName DearKid)
project(${ProjectName})
set(CMAKE_CXX_STANDARD 11)
add_definitions(-DUNICODE -D_UNICODE)

add_subdirectory(3rd_party)
add_subdirectory(src)
add_subdirectory(tests)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
