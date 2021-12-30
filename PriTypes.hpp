#pragma once 
#include<stdint.h>

typedef int32_t i32;
typedef int32_t i64;

typedef uint32_t ui32;
typedef uint32_t ui64;

#define checkErr(i) if(!i) std::cout << "Error: " << SDL_GetError() << '\n';
