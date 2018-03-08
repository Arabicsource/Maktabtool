cmake_minimum_required(VERSION 3.10)
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

    ExternalProject_Add(mdbtools
	    GIT_REPOSITORY ${CMAKE_SOURCE_DIR}/mdbtools
	    GIT_TAG master
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


    add_dependencies(util mdbtools)
    include_directories(${install_dir}/src/util)
    target_link_libraries(matkabtool util)

    add_dependencies(mdb mdbtools)
    include_directories(${install_dir}/include)
    target_link_libraries(maktabtool mdb)
