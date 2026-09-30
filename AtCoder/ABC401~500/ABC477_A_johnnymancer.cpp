#include <iostream>
#include <string>

using namespace std;

int main(){
  string color;
  cin >> color;
  if(color == "B"){
    cout << 'Y' << endl;
  }else if(color == "Y"){
    cout << 'R' << endl;
  }else{
    cout << 'B' << endl;
  }
}