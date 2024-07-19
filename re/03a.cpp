#include <iostream>
#include <stack>
using namespace std;

int main()
{
  stack<int> stack;

  char val;
  int lhs, rhs;
  while (!cin.eof())
  {
    cin >> val;
    switch (val)
    {
    case '+':
      rhs = stack.top();
      stack.pop();
      lhs = stack.top();
      cout << rhs;
      cout << lhs;
      stack.pop();
      stack.push(rhs + lhs);
    case '-':
      rhs = stack.top();
      stack.pop();
      lhs = stack.top();
      stack.pop();
      stack.push(rhs - lhs);
    case '*':
      rhs = stack.top();
      stack.pop();
      lhs = stack.top();
      stack.pop();
      stack.push(rhs * lhs);
    case '/':
      rhs = stack.top();
      stack.pop();
      lhs = stack.top();
      stack.pop();
      stack.push(rhs / lhs);
    default:
      stack.push(int(val));
    }
  }
  cout << stack.top();

  return 0;
}