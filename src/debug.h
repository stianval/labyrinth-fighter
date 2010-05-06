#ifndef DEBUG_H
#define DEBUG_H

#if  (defined(_DEBUG) || defined(DEBUG))
#include <iostream>
#define PRINTD(x) if (1) { std::cout << (x) << std::endl; } else (void) 0
#define PRINTV(x) if (1) { std::cout << #x << " = " << (x) << std::endl; } else (void) 0
#else
#define PRINTD(x)
#define PRINTV(x)
#endif

#endif