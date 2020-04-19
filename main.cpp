#include <iostream>
#include "TestConfig.h"
#ifdef USE_FUNCTIONS
#include  "functions.hpp"
#endif
int main(int argc, char *argv[]) {
    // report version
    std::cout << argv[0] << " Version " << Test_VERSION_MAJOR << "." << Test_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    std::cout << "Hello World!" << std::endl;
    if (argc > 1) {
        float inputValue = std::stod(argv[1]);
        #ifdef USE_FUNCTIONS
        inputValue = sqr(inputValue);
        #endif
        std::cout << "Printing number: " << inputValue << std::endl;
    }
    return 0;
}
