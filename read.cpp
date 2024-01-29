#include <fstream>
#include <iostream>

#include "read.h"

template <typename T>
bool read_from_file(std::ifstream& file, T& value)
{
    // TODO: YOUR CODE HERE
    return true;
}

void read_game_entity(std::ifstream& file, float& x, float& y, float& z, std::string& name, int& health)
{
    x = read<float>(file);
    y = read<float>(file);
    z = read<float>(file);

    name = read_string_by_length(file, 40);

    health = read<int>(file);

    return;
}

std::string read_string_by_length(std::ifstream& file, size_t length)
{
    std::vector<char> bytes;

    for (int i = 0; i < length; i++)
    {
        char byte = read<char>(file);
        if (byte != 0x00)
        {
            bytes.push_back(byte);
        }        

        // NOTE: this consumes all null bytes until the limit is reached
    }

    return std::string(bytes.begin(), bytes.end());
}

std::string read_length_prefixed_string(std::ifstream& file)
{
    uint32_t length = read<uint32_t>(file);

    char* bytes = new char[length];
    read_n<char>(file, bytes, length);

    std::string str(bytes, length * sizeof(char));

    return str;
}

std::string read_null_terminated_string(std::ifstream& file)
{
    std::vector<char> bytes;

    while (true)
    {
        char byte = read<char>(file);
        if (byte == 0x00)
        {
            read<char>(file); // Consume null-term
            break; 
        } 

        bytes.push_back(byte);
    }

    return std::string(bytes.begin(), bytes.end());
}

int convert_to_int(char* bytes)
{
    return *(int*)bytes;
}

void convert_to_ints(char* bytes, int* int_array, size_t len)
{
    size_t num_of_ints = len / sizeof(int);
    for (size_t i = 0; i < num_of_ints; i++)
        int_array[i] = convert_to_int(bytes + (i * sizeof(int)));
    
    return;
}
