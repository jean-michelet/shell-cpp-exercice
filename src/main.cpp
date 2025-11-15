#include <iostream>
#include "./utils/split_whitespace.hpp"
#include "./cmd/type.hpp"
#include "./utils/cmd.hpp"

int main()
{
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  for (;;)
  {
    std::cout << "$ ";

    std::string command;
    std::getline(std::cin, command);

    if (command.empty())
    {
      continue;
    }

    auto args = split_whitespace(command);
    const std::string name = args.front();

    const Cmd *cmd = find_cmd(name);
    if (!cmd)
    {
      std::cout << name << ": command not found\n";
      continue;
    }

    cmd->exec(args);
  }
}
