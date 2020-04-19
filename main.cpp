#include <iostream>
#include "TestConfig.h"
#ifdef USE_FUNCTIONS
#include  "functions.hpp"
#endif
#include <cmath>
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
    #if defined(HAVE_LOG) && defined(HAVE_EXP)
    std::cout << "Platform has log and exp" << std::endl;
    #endif
    return 0;
}
