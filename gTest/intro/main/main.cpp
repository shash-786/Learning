#include "LibraryCode.hpp"
#include <iostream>

int main (int argc, char **argv) {
    int ans = sum(3, 4);
    std::cout << "The sum is: " << ans << std::endl;
    std::cout << "Main application" << std::endl;
    return 0;
}