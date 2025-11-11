// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repkai(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(){
  int h,b;
  cin >> h >> b;
  
  if(h <= b){
    cout << 0 << endl;
  }else{
    cout << h - b << endl;
  }
}
