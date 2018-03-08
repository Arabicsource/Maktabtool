/*
 * Copyright (c) 2018 Abdisamad Hashi. All rights reserved.
 */

#ifndef _FILE_H
#define _FILE_H
#include<string>
#include<vector>
#include<memory>


class Reader
{
    public:
	virtual bool read(std::shared_ptr<std::vector<char> > buffer) = 0;
};


class Writer
{
    public:
	virtual int write(std::shared_ptr<std::vector<char> > data) = 0;
};

class Closer
{
    public: 
	virtual void close() = 0;
};


class ReadWriter
{
    public:
	virtual bool read(std::shared_ptr<std::vector<char> > buffer) = 0;
	virtual int write(std::shared_ptr<std::vector<char> > data) = 0;
};

class ReadWriteCloser
{
    public:
	virtual bool read(std::shared_ptr<std::vector<char> > buffer) = 0;
	virtual int write(std::shared_ptr<std::vector<char> > data) = 0;
	virtual void close() = 0;
};

/*
 * File class represents an actual file we can read and write to.
 */

class File : public ReadWriteCloser {

    private:
	int				m_size;
	std::string			m_name;
	std::vector<char>		m_data;

    public:
	std::shared_ptr<std::fstream>	m_file;

	bool read(std::shared_ptr<std::vector<char> > buffer);
	int write(std::shared_ptr<std::vector<char> > data);
	void close(); 

	int size();
	std::string name();
	std::vector<char> data();
	static std::shared_ptr<File> open(std::string path, std::ios_base::openmode mode);


	File();

};
#endif
