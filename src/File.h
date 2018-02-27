/*
 * Copyright (c) 2018 Abdisamad Hashi. All rights reserved.
 */

#ifndef _FILE_H
#define _FILE_H
#include<string>
#include<vector>
#include<memory>



/*
 * File class represents an actual file we can read and write to.
 */

class File{

    private:
	std::ifstream*		m_file;
	int			m_size;
	std::string		m_name;
	std::vector<char>	m_data;

    public:
	File() noexcept;
	void read(std::unique_ptr<std::vector<char>> buffer);
	static std::unique_ptr<File> Open(std::string path);

};

#endif
