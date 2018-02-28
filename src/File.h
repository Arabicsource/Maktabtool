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

class File {

    private:
	int				m_size;
	std::string			m_name;
	std::vector<char>		m_data;

    public:
	std::shared_ptr<std::fstream>	m_file;

	void read(std::unique_ptr<std::vector<char>> buffer);
	int size();
	std::string name();
	std::vector<char> data();
	static std::shared_ptr<File> open(std::string path, std::ios_base::openmode mode);


	File() noexcept;

};
#endif
