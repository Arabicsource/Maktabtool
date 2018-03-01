cmake_minimum_required(VERSION 3.10)
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

    ExternalProject_Add(mdbtools
	    URL https://github.com/brianb/mdbtools
	    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/mdbtools
	    CONFIGURE_COMMAND "autoreconf -i -f" COMMAND "./configure --with-unixodbc=/usr/local --disable-man"
	    BUILD_COMMAND make
	    )
    ExternalProject_Get_Property(mdbtools install_dir)
    add_library(libmdb STATIC IMPORTED)

    add_executable(maktabtool main.cpp)

    add_dependencies(libmdb mdbtools)
    include_directories(${install_dir}/src/libmdb)
    target_link_libraries(maktabtool libmdb)
