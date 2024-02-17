#include "template_min.h"

#include <iostream>

// #define min(x, y) (x > y ? y : x)

int main() { std::cout << min<float>(5, 4.2) << std::endl; }
