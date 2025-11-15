#include "./type.hpp"
#include "../utils/cmd.hpp"
#include "../utils/args.hpp"
#include <iostream>

void cmd_type(const std::vector<std::string>& args)
{
    if (!expect_arg_count(args, 2, "type"))
        return;

    const std::string cmd_name = args.at(1);

    const Cmd *cmd = find_cmd(cmd_name);
    if (!cmd)
    {
      std::cout << cmd_name << ": not found\n";
      return;
    }

    if (cmd->is_builtin) {
      std::cout << cmd_name << " is a shell builtin\n";
    } else {
      std::cout << cmd_name << " is " << cmd->full_path << std::endl;
    }

}

