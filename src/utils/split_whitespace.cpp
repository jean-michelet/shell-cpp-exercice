#include <sstream>
#include "split_whitespace.hpp"

std::vector<std::string> split_whitespace(const std::string& s) {
    std::istringstream stream(s);
    std::vector<std::string> result;
    std::string word;

    while (stream >> word) {   // automatically splits on any whitespace
        result.push_back(word);
    }

    return result;
}
