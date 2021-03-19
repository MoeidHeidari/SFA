
#include <iostream>
#include <stdlib.h>
#include <cmath>

int jumpingSearch(int array[] , int input , int steps , int numberOfIterate , int length)
{
  static int foundedIndex = -1;
  //if we passed the length , then the steps will point to the last index in the array
  if(steps > length)
    steps = length;
  if(array[steps-1] < input)
  {
    steps = 2*steps;
    //On in here we are going to pass 1 in the parameters because this function is being called inside itself
    jumpingSearch(array , input , steps , 1 , length);
  }
  else
  {
    //if this is the first time that we are calling the function
    if(!numberOfIterate)
    {
      for(int i = 0 ; i<=steps-1 ; i++)
      {
        if(array[i] == input)
        {
          foundedIndex = i;
          break;
        }
      }
    }
    //if this is not the first time that we are calling the function
    else
    {
      for(int i = (steps/2) ; i<=steps-1 ; i++)
      {
        if(array[i] == input)
        {
          foundedIndex = i;
          break;
        }
      }
    }

  }
  return foundedIndex;
}

int main()
{
  //the sorted array
  int array[9] ={1,12,56,93,294,300,400,534,600};
  //the value which we are searching for
  int input = 294;

  //the steps which we want to jump
  int steps = sqrtf(9);
  int length = sizeof(array);

  //the zero in the arguments is to check if this is the first time that the function is being called or not
  std::cout<<"founded index = "<< jumpingSearch(array , input , steps, 0 , length)<<std::endl;


  return 0;
}
