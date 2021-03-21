#include "JumpSearch.h"
#include <cmath>

JumpSearch::JumpSearch() {

}

int JumpSearch::jumpSearchFunc(int array[] , int input , int steps , int numberOfIterate , int length) {
  if(!numberOfIterate)
    steps = sqrtf(length);
  JumpSearch j = JumpSearch();
  static int foundedIndex = -1;
  //if we passed the length , then the steps will point to the last index in the array
  if(steps > length)
    steps = length;
  if(array[steps-1] < input)
  {
    steps = 2*steps;
    //On in here we are going to pass 1 in the parameters because this function is being called inside itself
    j.jumpSearchFunc(array , input , steps , 1 , length);
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
