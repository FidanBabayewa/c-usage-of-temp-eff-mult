#include <iostream>
#include <string>
#include <algorithm>

std::ostream& double_space(std::ostream& os, const std::string& input) {
    for (char ch : input) {
        if (ch == ' ') {
            os << "  "; // Double the space
        } else {
            os << ch; // Print other characters as they are
        }
    }
    return os;
}

int main() {
    std::cout << double_space << "one space,  two  spaces" << std::endl;
    return 0;
}
