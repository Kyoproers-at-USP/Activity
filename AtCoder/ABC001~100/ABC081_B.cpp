#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  int n;
  cin >> n ;
  vector<int> bla(n);
  for(int i = 0 ; i < n ; i++){
    cin >> bla.at(i) ;
  }
  
  int sum = 0 ;
  while(1){  
    for(int i = 0 ; i < n ; i++){
      if(bla.at(i) % 2 == 1){
        cout << sum << endl;
        return 0;
      }
      bla.at(i) /= 2;
    }
    sum++;
  }
}
