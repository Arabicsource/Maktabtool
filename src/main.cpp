#include<iostream>
#include "File.h"
#include<mdb/mdbtools.h>


int main(int argc, char* argv )
{

    // mdb file handle
    MdbHandle *mdb;



    mdb = mdb_open (argv[1], MDB_NOFLAGS);
    if (!mdb) {
	std::cout << "Could not open file" << std::endl;
	return 1;
    }


    
    return 0; 
}


