#include <vector>
#include <string>

bool expect_arg_count(const std::vector<std::string> &args,
                      std::size_t expected,
                      const std::string &command_name);

bool expect_min_arg_count(const std::vector<std::string> &args,
                      std::size_t expected,
                      const std::string &command_name);

bool parse_int(const std::string &s, int &out_value);