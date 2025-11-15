#include "args.hpp"
#include <iostream>

bool expect_arg_count(const std::vector<std::string> &args,
                      std::size_t expected,
                      const std::string &command_name)
{
    if (args.size() != expected)
    {
        std::cout << command_name
                  << ": invalid number of arguments (expected "
                  << expected - 1 << ", given " << args.size() - 1 << ")\n";
        return false;
    }
    return true;
}

bool expect_min_arg_count(const std::vector<std::string> &args,
                      std::size_t expected,
                      const std::string &command_name)
{
    if (args.size() < expected)
    {
        std::cout << command_name
                  << ": invalid number of arguments (expected at least "
                  << expected - 1 << ", given " << args.size() - 1 << ")\n";
        return false;
    }
    return true;
}

bool parse_int(const std::string &s, int &out_value)
{
    try
    {
        std::size_t pos = 0;
        int value = std::stol(s, &pos);

        if (pos != s.size())
        {

            std::cout << "exit: numeric argument required\n";
            return false;
        }

        out_value = value;
        return true;
    }
    catch (...)
    {
        std::cout << "exit: numeric argument required\n";
        return false;
    }
}
