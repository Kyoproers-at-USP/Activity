#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  int k,a,b;
  cin >> k >> a >> b;
  
  int dis = k;
  for(int i = 0 ; ; i++){
    if(dis * i <= b && dis * i >= a ){
      cout << "OK" << endl;
      return 0;
    }
    if( dis * i > b){
      break;
    }
  }
  cout << "NG" << endl;
}
