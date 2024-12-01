#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

template <typename TVal>
bool compare(const TVal& a, const TVal& b)
{
  return a <= b;
}

int similarity(const std::vector<int>& firstList, const std::vector<int>& secondList)
{
  int total = 0;
  for(int val : firstList)
  {
    int x = 0;
    for(int val2 : secondList)
    {
      x = val == val2 ? x + 1 : x;
    }
    x *= val;
    total += x;
  }
  return total;
}

void readFromFile()
{
  std::ifstream myF;
  int firstNum;
  int secNum;
  std::vector<int> firstList;
  std::vector<int> secondList;
  
  myF.open("input.txt");
  if(!myF)
  {
    std::cout << "Cannot open file" << std::endl;
    exit(1);
  
  }
  while(myF >> firstNum >> secNum)
  {
    firstList.push_back(firstNum);
    secondList.push_back(secNum);
  }
  
  std::sort(firstList.begin(), firstList.end(), compare<int>);
  std::sort(secondList.begin(), secondList.end(), compare<int>);
  
  int total = 0;
  
  for(int i = 0; i < firstList.size(); ++i)
  {
    total += firstList[i] > secondList[i] ? firstList[i] - secondList[i] : secondList[i] - firstList[i];
  }
  
  std::cout << std::fixed;
  std::cout << "Total Distance: " << total << std::endl;
  std::cout << "Total Similarity: " << similarity(firstList, secondList) << std::endl;
}

int main()
{
  readFromFile();
  return 0;
}
