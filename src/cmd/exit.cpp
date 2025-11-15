#include "./exit.hpp"
#include "../utils/args.hpp"
#include <iostream>

void cmd_exit(const std::vector<std::string>& args)
{
    if (!expect_arg_count(args, 2, "exit"))
        return;

    int code;
    if (!parse_int(args[1], code))
        return;

    std::exit(code);
}
