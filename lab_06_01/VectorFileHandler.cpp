#include "VectorFileHandler.h"


VectorFileHandler::VectorFileHandler(std::string _vector_file_path)
{
	vector_file_path = _vector_file_path;
}


std::vector<int> VectorFileHandler::read_vector_from_file()
{
	file_object.open(vector_file_path, std::ios::in);
	getline(file_object, buffer_string);
	std::vector<int> tmp_vector;

	int curent_separator;
	for (int string_index = 0; string_index < buffer_string.size(); string_index++)
	{

		if (buffer_string[string_index] == '\t')
		{
			std::vector<char> tmp_string;
			int sub_string_index = string_index + 1;
			int iterator_tmp = 0;
			while (buffer_string[sub_string_index] != '\t')
			{
				if (buffer_string[sub_string_index] == '\n')
				{
					break;
				}

				tmp_string.push_back(char(buffer_string[sub_string_index]));
				sub_string_index += 1;
			}

			char* tmp_char_string = new char[tmp_string.size()];
			tmp_char_string[0] = tmp_string.at(0);
			tmp_char_string[1] = tmp_string.at(1);

			tmp_vector[curent_separator] = std::atol(tmp_char_string);
			curent_separator += 1;
		}
	}

	file_object.close();
	return tmp_vector;
}

void VectorFileHandler::delete_item_from_vector(int item_index)
{
	std::vector<int> tmp_vector = read_vector_from_file();
	file_object.open(vector_file_path, std::ios::out | std::ios::trunc);
	for (int curent_vector_iterator = 0; curent_vector_iterator < tmp_vector.size(); curent_vector_iterator++)
	{
		file_object << "\t" << tmp_vector[curent_vector_iterator];
	}
	file_object.close();

}

void VectorFileHandler::insert_in_vector(int item_to_insert)
{
	file_object.open(vector_file_path, std::ios::in);
	getline(file_object, buffer_string);
	std::vector<int> tmp_vector = read_vector_from_file();

	std::vector<int> result_tmp_vector;
	result_tmp_vector.resize(tmp_vector.size() + 1);
	int log_gate = 1;

	file_object.open(vector_file_path, std::ios::in | std::ios::trunc);

	for (int vector_iterator = 0; vector_iterator < tmp_vector.size(); vector_iterator++)
	{
		
		if ((item_to_insert < tmp_vector[vector_iterator]) and (item_to_insert > tmp_vector[vector_iterator]))
		{
			result_tmp_vector[vector_iterator] = item_to_insert;
			result_tmp_vector[vector_iterator + 1] = tmp_vector[vector_iterator];
			log_gate = 0;
		}
		
		if (log_gate == 1)
		{
			result_tmp_vector[vector_iterator] = tmp_vector[vector_iterator];
		}

		else if (log_gate == 0)
		{
			result_tmp_vector[vector_iterator] = tmp_vector[vector_iterator + 1];
		}

	}

	for (int iterator = 0; iterator < result_tmp_vector.size(); iterator++)
	{
		file_object << "\t" << result_tmp_vector[iterator];
	}
	file_object.close();
}

int VectorFileHandler::find_by_index(int index) 
{
	std::vector<int> tmp_vector = read_vector_from_file();
	int result_item = tmp_vector.at(index);

	return result_item;
}

int VectorFileHandler::find_min_val()
{
	std::vector<int> tmp_vector = read_vector_from_file();
	int min_value = 999999999999;
	for (int curent_value_number = 0; curent_value_number < tmp_vector.size(); curent_value_number++)
	{
		if (min_value > tmp_vector[curent_value_number])
		{
			min_value = tmp_vector[curent_value_number];
		}
	}

	return min_value;
}

void VectorFileHandler::reverse_vector_in_file()
{
	std::vector<int> tmp_vector = read_vector_from_file();
	std::vector<int> reversed_vector;
	reversed_vector.resize(tmp_vector.size());

	for (int curent_item_number = 0; curent_item_number < tmp_vector.size(); curent_item_number++)
	{
		reversed_vector[curent_item_number] = tmp_vector[tmp_vector.size() - curent_item_number];
	}

	file_object.open(vector_file_path, std::ios::in | std::ios::trunc);
	for (int iterator = 0; iterator < reversed_vector.size(); iterator++)
	{
		file_object << reversed_vector[iterator];
	}
	file_object.close();

}

