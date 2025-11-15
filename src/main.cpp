#include <iostream>
#include "./utils/split_whitespace.hpp"
#include "./commands/exit.hpp"

int main()
{
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  for (;;)
  {
    std::cout << "$ ";

    std::string command;
    std::getline(std::cin, command);

    if (command.length() == 0)
    {
      continue;
    }

    auto args = split_whitespace(command);
    const std::string name = args[0];

    if (name == "exit")
    {
      exit(args);
    }
    else
    {
      std::cout << args[0] << ": command not found" << std::endl;
    }
  }
}
