#include <iostream>
#include "TestConfig.h"
#include  "functions.hpp"

int main(int argc, char *argv[]) {
    // report version
    std::cout << argv[0] << " Version " << Test_VERSION_MAJOR << "." << Test_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    std::cout << "Hello World!" << std::endl;
    if (argc > 1) {
        double inputValue = std::stod(argv[1]);
        double outputValue = functions::sqrt(inputValue);
        std::cout << "The square root of " << inputValue << " is " << outputValue << std::endl;
    }
    return 0;
}
