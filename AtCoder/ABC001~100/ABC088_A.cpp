#include <iostream>

using namespace std;

int main(){
  int n,a;
  cin >> n >> a ;
  
  if(n < 500){
    if(n <= a){
      cout << "Yes" << endl;
      return 0;
    }else{
      cout << "No" << endl;
    }
  }else{
    if( (n % 500) <= a){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}
