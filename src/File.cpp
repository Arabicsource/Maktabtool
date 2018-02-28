#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<memory>
#include "File.h"


File::File() noexcept
{
    std::shared_ptr<std::fstream> m_file(nullptr);
    int m_size(0);
    std::string m_name("");
    std::vector<char> m_data(m_size); 
}

// open opens up a file and accessible through m_file member 
std::shared_ptr<File> File::open(std::string path, std::ios_base::openmode mode)
{
    std::shared_ptr<File> f = std::shared_ptr<File>(new File());

    f->m_file->open(path, mode);

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


// read reads the file's content into a buffer passed as a parameter
void File::read(std::unique_ptr<std::vector<char>> buffer)
{

    buffer->resize(this->m_size, 0);
    buffer->swap(this->m_data);

}

// size returns the size of the File
int File::size()
{
    return this->m_size;
}

// name returns the name of the file in string
std::string File::name()
{
    return this->m_name;
}

// data returns the data in a vector
std::vector<char> File::data()
{
    return this->m_data;
}
