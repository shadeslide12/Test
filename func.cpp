#include <iostream>
#include "func.h"

void printfunc1(){
#ifdef OPTION_1
         std::cout << "this is function1"<<std::endl;
#else
         std::cout << "Nothing"<< std::endl;
#endif

}
