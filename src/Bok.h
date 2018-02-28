#ifndef _BOK_H
#define _BOK_H
#include<iostream>
#include<memory>
#include<vector>
#include "File.h"


class Bok : public File
{
    private:
	std::vector<char>	m_data;
	int			m_data_size;
	std::vector<char>	m_buffer;
	int			m_buffer_size;

    public:

	Bok();
	
};
#endif
