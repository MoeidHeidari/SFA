#include "BinarySearch.h"
#include <iostream>
BinarySearch::BinarySearch() {

}

int BinarySearch::binarySearchFunc(int data[] ,int numElements, int searchKey , int index) {
  BinarySearch b = BinarySearch();
  int half = numElements / 2;
  if(index == -1)
    index = half;
  if(numElements % 2 == 0)
  {
    if(numElements == 0)
      std::cout<<"Not Founded"<<std::endl;
    else if(searchKey == data[half])
    {
      if(index == -1)
        index = half;

      std::cout<<index<<std::endl;
    }
    else
    {
      if(searchKey > data[half])
      {
        int length = numElements - half - 1;
        int* newList = new int[length];
        if(length > 1)
        {
          int x = length/2;
            index = index + x + 1;
        }
        else
          index += 1;
        for(int i=half+1 , j =0 ; i<=numElements - 1 && j<length ; i++ , j++)
          newList[j] = data[i];
        b.binarySearchFunc( newList, length , searchKey, index);
      }
      else //if(searchKey < data[half])
      {
        int length = numElements - half;
        int* newList = new int[length];
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
        for(int i=0 , j =0 ; i<numElements - half && j<numElements-half ; i++ , j++)
          newList[j] = data[i];
        b.binarySearchFunc( newList, length , searchKey, index);
      }
    }
  }
  else
  {
    if(numElements == 0)
       std::cout<<"Not Founded"<<std::endl;
    else if(searchKey == data[half])
    {
      if(index == -1)
        index = half;
      std::cout<<index<<std::endl;
    }
    else
    {
      if(searchKey > data[half])
      {
        int length = numElements - half - 1;
        int* newList = new int[length];
        if(length > 1)
        {
          int x = length/2;
          index = index + x + 1;
        }
        // else if(length == 2)
        // {
        //   int x = length/2;
        //   index = index + x - 1;
        // }
        else
          index = index + 1;
        for(int i=half+1 , j =0 ; i<=numElements - 1 && j<numElements-half-1 ; i++ , j++)
          newList[j] = data[i];
        b.binarySearchFunc( newList, length , searchKey , index);
      }
      else  //if(searchKey < data[half])
      {
        int length = numElements - half - 1;
        int* newList = new int[length];
        //calculating the index
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
        for(int i=0 , j =0 ; i<numElements - half -1  && j<numElements-half-1 ; i++ , j++)
          newList[j] = data[i];
        b.binarySearchFunc( newList, length , searchKey, index);
      }
    }
  }
return 0;
}
