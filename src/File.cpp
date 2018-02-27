#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<memory>
#include "File.h"


File::File() noexcept
{
   int m_size = 0;
   std::string m_name = "";
   std::vector<char> m_data; 
}

std::unique_ptr<File> File::Open(std::string path)
{
    std::unique_ptr<File> f;

    f->m_file->open(path, std::ios::binary);

    if(f->m_file->fail())
    {
	std::cout<< "can not open file: " << path << std::endl;

    } else {

	f->m_size = f->m_file->tellg();
	f->m_data.resize(f->m_size, 0);
	f->m_file->read(&f->m_data[0], f->m_size);
    }


    f->m_file->close();

    return f;
    
}


void File::read(std::unique_ptr<std::vector<char>> buffer)
{

    buffer->resize(this->m_size, 0);
    buffer->swap(this->m_data);

}

