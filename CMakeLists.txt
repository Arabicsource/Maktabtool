cmake_minimum_required(VERSION 3.10)
    if(APPLE)
	add_subdirectory(mdbtools)
	add_executable(maktabtool main.cpp)
	target_link_libraries(maktabtool mdbsql.h)
	install(TARGETS maktabtool DESTINATION bin)
    endif()



    
