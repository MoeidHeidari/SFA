
#include <iostream>
#include <stdlib.h>

#include "Foo.h"
int main()
{
  Foo d = Foo();
  std::cout<< d.doSomething()<<std::endl;
  std::cout<<"Test change";
  return 0;
}
