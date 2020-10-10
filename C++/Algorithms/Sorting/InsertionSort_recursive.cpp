/*
Title: InsertionSort_recursive.cpp
This program implement Insertion sort in recursive way on integer and string values.
Author: Sharmila
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

static void IntegerHelper(std::vector<int>& vec, int size){
  if(size <= 1){
    return ;
  }
  IntegerHelper(vec, size-1);    //recursive call
  int key = vec[size-1];
  int last = size-2;

  while(last >= 0 && vec[last] > key){
    vec[last+1] = vec[last];
    last--;
  }
  vec[last+1] = key;
}


void IntegerInsertionSort(std::vector<int>& vec){
  int size = vec.size();
  return IntegerHelper(vec, size);
}

static void StringHelper(std::vector<string>& vec, int size){
  if(size <= 1){
    return ;
  }
  StringHelper(vec, size-1);    //recursive call
  string key = vec[size-1];
  int last = size-2;

  while(last >= 0 && vec[last] > key){
    vec[last+1] = vec[last];
    last--;
  }
  vec[last+1] = key;
}

void StringInsertionSort(std::vector<string>& vec){
  int size = vec.size();
  return StringHelper(vec, size);
}


void print(std::vector<std::string> &v) {
  std::cout << "[";
  bool first = true;
  for (auto x : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << x;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}

void printNum(std::vector<int> &v) {
  std::cout << "[";
  bool first = true;
  for (auto x : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << x;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}

int main() {
  std::vector<int> numVector;
  std::vector<std::string> strVec;
  numVector = {10, 8, -1, 6, -9, 2, 0};
  strVec = {"watson", "emmalong", "jacob", "zarna", "zoya"};
  
  std::cout << "Case 1: Insertion Sort on integers "<<std::endl;
  IntegerInsertionSort(numVector);
  std::cout<<"output: ";
  printNum(numVector);
  std::cout << "Expected: [0, 1, 2, 6, 8, 9, 10]" << std::endl;
  std::cout << "Case 2: Insertion Sort on strings "<<std::endl;
  StringInsertionSort(strVec);
  std::cout<<"output: ";
  print(strVec);
  std::cout << "Expected: [emmalong, jacob, watson, zarna, zoya]" << std::endl;
  
  return 0;
}

/* output:
Case 1: Insertion Sort on integers                                                                                                                                   
output: [-9, -1, 0, 2, 6, 8, 10]                                                                                                                                     
Expected: [0, 1, 2, 6, 8, 9, 10]                                                                                                                                     
Case 2: Insertion Sort on strings                                                                                                                                    
output: [emmalong, jacob, watson, zarna, zoya]                                                                                                                       
Expected: [emmalong, jacob, watson, zarna, zoya]
*/
