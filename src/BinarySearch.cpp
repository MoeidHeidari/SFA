#include "BinarySearch.h"
#include <iostream>
BinarySearch::BinarySearch() {

}

int BinarySearch::binarySearchFunc(int data[] ,int numElements, int searchKey , int index) {
  static int foundedIndex = -1;
  BinarySearch b = BinarySearch();
  int half = numElements / 2;
  if(index == -1) // if index is equal to -1 , then this is the first time that we are calling the function and it is not a call back
    index = half;
  if(numElements % 2 == 0) //if the length of the array is even
  {
    if(numElements == 0) //this is the end of the array
      std::cout<<"Not Founded"<<std::endl;
    else if(searchKey == data[half]) //the middle element is equal to the value we are searching for, therefore we have found it
      foundedIndex = index;
    else
    {
      if(searchKey > data[half]) //if the value which we are looking for is in the right side of the middle element
      {
        int length = numElements - half - 1;
        int* newList = new int[length];
        //calculating the real index of the next middle element
        if(length > 1)
        {
          int x = length/2;
            index = index + x + 1;
        }
        else
          index += 1;
        //defining the new array
        for(int i=half+1 , j =0 ; i<=numElements - 1 && j<length ; i++ , j++)
          newList[j] = data[i];
        b.binarySearchFunc( newList, length , searchKey, index);
      }
      else //if the value which we are looking for is in the left side of the middle element
      {
        int length = numElements - half;
        int* newList = new int[length];
        //calculating the real index of the next middle element
        if(length > 2)
        {
          int x = length/2;
          index = index - x - 1;
        }
        else if(length == 2)
        {
          int x = length/2;
          index = index - x ;
        }
        else
        {
          index -= 1;
        }
        //defining the new array
        for(int i=0 , j =0 ; i<numElements - half && j<numElements-half ; i++ , j++)
          newList[j] = data[i];
        b.binarySearchFunc( newList, length , searchKey, index);
      }
    }
  }
  else  //if the length of the array is odd
  {
    if(numElements == 0) //this is the end of the array
       std::cout<<"Not Founded"<<std::endl;
    else if(searchKey == data[half]) //the middle element is equal to the value we are searching for, therefore we have found it
      foundedIndex = index;
    else
    {
      if(searchKey > data[half]) //if the value which we are looking for is in the right side of the middle element
      {
        int length = numElements - half - 1;
        int* newList = new int[length];
        //calculating the real index of the next middle element
        if(length > 1)
        {
          int x = length/2;
          index = index + x + 1;
        }
        else
          index = index + 1;
        //defining the new array
        for(int i=half+1 , j =0 ; i<=numElements - 1 && j<numElements-half-1 ; i++ , j++)
          newList[j] = data[i];
        b.binarySearchFunc( newList, length , searchKey , index);
      }
      else  //if the value which we are looking for is in the left side of the middle element
      {
        int length = numElements - half - 1;
        int* newList = new int[length];
        //calculating the real index of the next middle element
        if(length > 2)
        {
          int x = length/2;
          index = index - x - 1;
        }
        else if(length == 2)
        {
          int x = length/2;
          index = index - x ;
        }
        else
          index -= 1;
        //defining the new array
        for(int i=0 , j =0 ; i<numElements - half -1  && j<numElements-half-1 ; i++ , j++)
          newList[j] = data[i];
        b.binarySearchFunc( newList, length , searchKey, index);
      }
    }
  }
  return foundedIndex;
}
