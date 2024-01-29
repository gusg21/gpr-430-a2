#include <fstream>
#include <string>

template <typename T>
T read(std::ifstream& file)
{
    T value = T();

    file.read((char*)&value, sizeof(value));

    return value;
}

template <typename T>
void read_n(std::ifstream& file, T* out_array, size_t len)
{
    file.read((char*)out_array, len * sizeof(T));
    return;
}

std::string read_string_by_length(std::ifstream& file, size_t length);
std::string read_length_prefixed_string(std::ifstream& file);
std::string read_null_terminated_string(std::ifstream& file);

int convert_to_int(char* bytes);
void convert_to_ints(char* bytes, int* int_array, size_t len);

void read_game_entity(std::ifstream& file,
		      float& x, float& y, float& z,
		      std::string& name,
		      int& health);

