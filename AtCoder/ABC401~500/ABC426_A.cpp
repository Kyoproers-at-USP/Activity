// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  string x,y;
  cin >> x >> y;
  
  if( (int)(x.at(1)) >= (int)(y.at(1)) ){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}