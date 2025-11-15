#include "cmd.hpp"
#include <unordered_map>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

#include "../cmd/echo.hpp"
#include "../cmd/exit.hpp"
#include "../cmd/type.hpp"
#include "./find_exec.hpp"

static const std::unordered_map<std::string, Cmd> builtin_registry = {
    {"echo", {"echo", true, cmd_echo}},
    {"exit", {"exit", true, cmd_exit}},
    {"type", {"type", true, cmd_type}},
};

static std::unordered_map<std::string, Cmd> external_cache;

const Cmd *find_cmd(const std::string &name)
{
    if (auto it = builtin_registry.find(name); it != builtin_registry.end())
    {
        return &it->second;
    }

    if (auto it = external_cache.find(name); it != external_cache.end())
    {
        return &it->second;
    }

    std::string resolved = find_exec(name);
    if (resolved.empty())
    {
        return nullptr;
    }

    Cmd ext;
    ext.name = name;
    ext.is_builtin = false;
    ext.full_path = resolved;
    ext.exec = [resolved](const std::vector<std::string> &args)
    {
        exec_external(resolved, args);
    };

    auto [pos, _] = external_cache.emplace(name, std::move(ext));
    return &pos->second;
}

static void exec_external(const std::string &path,
                          const std::vector<std::string> &args)
{
    if (args.empty())
    {
        return;
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        std::vector<char *> argv;
        argv.reserve(args.size() + 2);

        argv.push_back(const_cast<char *>(path.c_str()));

        for (auto &s : args)
        {
            argv.push_back(const_cast<char *>(s.c_str()));
        }

        argv.push_back(nullptr);

        execv(path.c_str(), argv.data());

        perror("execv");

        _exit(127);
    }

    int status;

    waitpid(pid, &status, 0);
}
