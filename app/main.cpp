
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "JumpSearch.h"
#include "BinarySearch.h"

int main()
{
  JumpSearch j = JumpSearch();
  BinarySearch b = BinarySearch();
  //the sorted array
  int array[17] ={1,12,56,93,294,300,400,534,600,900};
  //the value which we are searching for
  int input = 400;

  // int length = sizeof(array);
  int length = 10;

  //the second zero in the arguments is to check if this is the first time that the function is being called or not
  //the first zero in the arguments is the value of the steps to jump => on in here because we will initials it inside the jumpSearchFunc therefore we are passing zero here.
  std::cout<<"founded index by jump_Search_algorithm = "<< j.jumpSearchFunc(array , input , 0, 0 , length)<<std::endl;

  //the zero in the arguments is for calculating the number of calling function
  std::cout<<"founded index by binary_Search_algorithm = "<< b.binarySearchFunc(array, length, input , -1)<<std::endl;


  return 0;
}
