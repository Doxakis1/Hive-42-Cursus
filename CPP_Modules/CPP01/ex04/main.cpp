#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <exception>

int create_and_replace(const std::string& filename, const std::string& find, const std::string& replace) 
{
    if (find.empty())
        return (EXIT_FAILURE);
    std::ifstream in_filestream(filename, std::ios::in);
    if (!in_filestream.is_open()) {
        std::cout << "Error opening the input file: " << filename << std::endl;
        return EXIT_FAILURE;
    }
    std::string new_file_name = filename + ".replace";
    std::ofstream out_filestream(new_file_name, std::ios::out);
    if (!out_filestream.is_open()) {
        std::cout << "Error opening/creating the output file: " << new_file_name << std::endl;
        return EXIT_FAILURE;
    }
    out_filestream.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
    in_filestream.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
    std::stringstream buffer;
    try {
        buffer << in_filestream.rdbuf();
        std::string file_content = buffer.str();
        std::string holder;
        size_t pos = 0;
        size_t prev_pos = 0;
        while ((pos = file_content.find(find, prev_pos)) != std::string::npos) {
            holder  = file_content.substr(prev_pos, pos - prev_pos);
            out_filestream << holder;
            out_filestream << replace;
            prev_pos = pos + find.length();
        }
        holder  = file_content.substr(prev_pos, file_content.length());
        out_filestream << holder;
    } catch(const std::exception& e) {
        std::cout << "An error occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
        return 1;
    std::string array[3];
    for (int i = 0; i < 3 ; i++)
        array[i] = argv[i+1];
    return (create_and_replace(array[0],  array[1], array[2]));
}
