#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool compare(int a, int b)
{
  return a <= b;
}

void readFromFile(std::vector<int>& outVec1, std::vector<int>& outVec2)
{
  std::ifstream myF;
  int firstNum;
  int secNum;
  myF.open("input.txt");
  if(!myF)
  {
    std::cout << "Cannot open file" << std::endl;
    exit(1);
  }
  while(myF >> firstNum >> secNum)
  {
    std::cout << firstNum << " FIRST & SECOND " << secNum << std::endl;
    outVec1.push_back(firstNum);
    outVec2.push_back(secNum);
  }
  std::sort(outVec1.begin(), outVec1.end(), compare);
  std::sort(outVec2.begin(), outVec2.end(), compare);
}

int main()
{
  std::vector<int>firstList;
  std::vector<int>secondList;
  std::vector<int>distances;
  readFromFile(firstList, secondList);
  std::vector<int>::const_iterator cIter1 = firstList.begin();
  std::vector<int>::const_iterator cIter2 = secondList.begin();
  for(;cIter1 != firstList.end() && cIter2 != secondList.end(); ++cIter1, ++cIter2)
  {
    std::cout << *cIter1 << " " << *cIter2 << std::endl;
    distances.push_back(*cIter1 > *cIter2 ? *cIter1 - *cIter2 : *cIter2 - *cIter1);
  }
  int totalDist = 0;
  for(int dist : distances)
  {
    std::cout << dist << std::endl;
    totalDist += dist;
  }
  std::cout << std::fixed;
  std::cout << "TOTAL DIST: " << totalDist << std::endl;
}
