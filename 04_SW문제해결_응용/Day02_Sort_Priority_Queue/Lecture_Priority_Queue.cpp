#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
  int num;
  char ch;
}

struct cmp
{
  bool operator() (Node& left, Node& right)
  {
    if(left.num % 2 == 1 && right.num % 2 == 0) return true;
    if(left.num % 2 == 0 && right.num % 2 == 1) return false;

    if (left.num > right.num) return true;
    if (left.num < right.num) return false;

    if(left.ch > right.ch) return true;
    if(left.ch < right.ch) return false;

    return false;
  }
};

int main()
{
  string str;
  cin >> str;

  priority_queue<char, vector<char>, less<char>> pq; // Max Heap

  for (int i = 0; i < str.size(); i++)
  {
    pq.push(str[i]);
  }
  while(!pq.empty())
  {
    cout << pq.top();
    pq.pop();
  }

  return 0;
}