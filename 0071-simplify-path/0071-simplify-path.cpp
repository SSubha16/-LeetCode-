#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        std::stringstream ss(path);
        std::string segment;

        while (std::getline(ss, segment, '/')) {
            if (segment.empty() || segment == ".") {
                continue;
            }
            if (segment == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(segment);
            }
        }

        if (stack.empty()) {
            return "/";
        }

        std::string canonicalPath = "";
        for (const std::string& dir : stack) {
            canonicalPath += "/" + dir;
        }

        return canonicalPath;
    }
};