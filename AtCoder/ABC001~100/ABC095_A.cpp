#include <iostream>
#include <string>

using namespace std;

int main(){
  string s;
  cin >> s ;
  
  int azi,tya,negi;
  if(s.at(0) == 'o'){
    azi = 1;
  }else{
    azi = 0;
  }
  
  if(s.at(1) == 'o'){
    tya = 1;
  }else{
    tya = 0;
  }
  
  if(s.at(2) == 'o'){
    negi = 1;
  }else{
    negi = 0;
  }
  
  cout << 700 + 100 * (azi + tya + negi) << endl;
}
