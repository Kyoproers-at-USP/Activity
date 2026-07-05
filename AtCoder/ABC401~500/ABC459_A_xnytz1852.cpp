#include <bits/stdc++.h>
using namespace std;

int main() {
  string str1 = "HelloWorld";
  int x;
  cin >> x;

  for(int i = 0;i < str1.length();i++){
    if(i==x-1)continue;
    cout << str1.at(i);
  }
}
