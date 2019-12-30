cmake_minimum_required(VERSION 3.0)
project(pyRedshift)

set(CMAKE_CXX_STANDARD 14)
set(PYTHON_DIR C:/python27)
set(RS_SDK_DIR D:/CodeProject/RS_SDK/sdk)

include_directories(${PYTHON_DIR}/include)
include_directories(${RS_SDK_DIR}/include)
link_directories(${PYTHON_DIR}/libs)
link_directories(${RS_SDK_DIR}/lib/x64)

file(GLOB SOURCES src/*.h src/*.cpp)

add_library(pyRedshift SHARED ${SOURCES})
set_target_properties(pyRedshift PROPERTIES SUFFIX ".pyd")

target_link_libraries(pyRedshift
        redshift-core-vc100
        bz2
        pyexpat
        python27
        select
        unicodedata
        winsound
        _bsddb
        _ctypes
        _elementtree
        _hashlib
        _multiprocessing
        _socket
        _sqlite3
        _ssl)