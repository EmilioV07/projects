#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char str[80] = "\0";
  cout << "Input: :" << endl;
  cin >> str;
  char temp1 = str[0];
  char temp2 = str[1];
  str[0] = temp2;
  str[1] = temp1;
  cout << str << endl;
}
