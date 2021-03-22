#include "LinearSearch.h"
#include <iostream>
LinearSearch::LinearSearch() {

}

int LinearSearch::linearSearchFunc(int array[] , int input , int length) {

  int foundedIndex = -1;
  for(int i =0 ; i<length ; i++)
  if(array[i] == input)
     foundedIndex = i;
  return foundedIndex;
}
