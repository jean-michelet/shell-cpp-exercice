#include "./exit.hpp"
#include <iostream>

void exit(std::vector<std::string> args)
{
    if (args.size() != 2)
    {
        std::cout << "exit: command with invalid number of arguments" << std::endl;
        return;
    }

    try
    {
        int code = std::stoi(args[1]);
        std::exit(code);
    }
    catch (...)
    {
        std::cout << "exit: numeric argument required\n";
    }
}
