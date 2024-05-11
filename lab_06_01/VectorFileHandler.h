#pragma once
#include<iostream>
#include<vector>
#include<math.h>
#include<fstream>
#include<string>


class VectorFileHandler
{
private:

	std::string vector_file_path;
	std::string buffer_string;
	std::fstream file_object;

public:

	VectorFileHandler(std::string);
	std::vector<int> read_vector_from_file();
	void reverse_vector_in_file();
	int find_min_val();
	void delete_item_from_vector(int);
	void insert_in_vector(int);
	int find_by_index(int);
};

