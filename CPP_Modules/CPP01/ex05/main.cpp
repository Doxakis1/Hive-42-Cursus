#include "Harl.hpp"

int main()
{
    Harl    harl;

    std::cout << "trying with DEBUG:" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl << std::endl;

    std::cout << "trying with INFO:" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl << std::endl;

    std::cout << "trying with WARNING:" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl << std::endl;

    std::cout << "trying with ERROR:" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl << std::endl;

    std::cout << "trying with not_real:" << std::endl;
    harl.complain("not_real");
    std::cout << std::endl << std::endl;

    return EXIT_SUCCESS;
}
