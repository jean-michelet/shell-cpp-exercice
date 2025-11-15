#include "find_exec.hpp"
#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <unistd.h>

std::string find_exec(const std::string &cmd_name)
{
    const char *raw = std::getenv("PATH");
    if (!raw)
    {
        return "";
    }

    std::string path = raw;
    std::string current;

    for (size_t i = 0; i <= path.size(); ++i)
    {
        if (i == path.size() || path[i] == ':')
        {
            if (!current.empty())
            {
                std::filesystem::path p = std::filesystem::path(current) / cmd_name;

                if (std::filesystem::exists(p) && ::access(p.c_str(), X_OK) == 0)
                {
                    return p.string();
                }
            }
            current.clear();
        }
        else
        {
            current += path[i];
        }
    }

    return "";
}
