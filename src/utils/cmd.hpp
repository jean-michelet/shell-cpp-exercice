#pragma once
#include <string>
#include <vector>
#include <functional>

struct Cmd
{
    std::string name;
    bool is_builtin;
    std::function<void(const std::vector<std::string> &)> exec;
    std::string full_path;
};

const Cmd *find_cmd(const std::string &name);

static void exec_external(const std::string path,
                          const std::vector<std::string> args);