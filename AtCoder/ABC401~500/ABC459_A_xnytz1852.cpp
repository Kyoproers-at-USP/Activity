#include <bits/stdc++.h>
using namespace std;

int main() {
  string str1;
  int x;
  cin >> x;
  str1 = "HelloWorld";

  for(int i=0;i<10;i++){
    if(i==x-1)continue;
    cout << str1.at(i);
  }
}
