#include <iostream>
#include "TestConfig.h"

int main(int argc, char *argv[]) {
    // report version
    std::cout << argv[0] << " Version " << Test_VERSION_MAJOR << "." << Test_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    std::cout << "Hello World!" << std::endl;
    if (argc > 1)
    const double inputValue = std::stod(argv[1]);
    return 0;
}