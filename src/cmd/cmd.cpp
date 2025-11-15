#include "cmd.hpp"
#include <unordered_map>

#include "./echo.hpp"
#include "./exit.hpp"
#include "./type.hpp"

static const std::unordered_map<std::string, Cmd> registry = {
    {"echo", {"echo", true, cmd_echo}},
    {"exit", {"exit", true, cmd_exit}},
    {"type", {"type", true, cmd_type}},
};

const Cmd *find_cmd(const std::string &name)
{
    auto it = registry.find(name);
    if (it != registry.end())
    {
        return &it->second;
    }

    return nullptr;
}
