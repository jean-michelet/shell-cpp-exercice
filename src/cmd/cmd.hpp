#pragma once
#include <string>
#include <vector>

using CmdFunc = void (*)(const std::vector<std::string> &);

struct Cmd
{
    std::string name;
    bool is_builtin;
    CmdFunc exec;
};

const Cmd *find_cmd(const std::string &name);

