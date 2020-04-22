
#include "functions.hpp"

#include <cmath>

#ifdef USE_MYMATH
#  include "sqrt.hpp"
#endif

namespace functions {
double sqrt(double x)
{
#ifdef USE_MYMATH
  return detail::mysqrt(x);
#else
  return std::sqrt(x);
#endif
}
}
