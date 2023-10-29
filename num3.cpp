#include <iostream>
#include <iomanip>
#include <string>

std::ostream& quote(std::ostream& os) {
    return os << "\"";
}

int main() {
    std::cout << quote << " text " << quote << std::endl;
    std::cout << quote << "\" text \"" << quote << std::endl;
    std::cout << quote << " \" text \" " << quote << std::endl;

    return 0;
}


