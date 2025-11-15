#include "./exit.hpp"
#include "../utils/args.hpp"
#include <iostream>

void cmd_echo(const std::vector<std::string> &args)
{
    if (!expect_min_arg_count(args, 2, "echo"))
        return;

    for (size_t i = 1; i < args.size(); ++i)
    {
        if (i > 1)
            std::cout << ' ';
        std::cout << args[i];
    }
    std::cout << std::endl;
}
