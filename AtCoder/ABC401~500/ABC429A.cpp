// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repkai(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(){
  int n , m;
  cin >> n >> m;
  
  for(int i = 1 ; i <= n ; i++){
    if(i <= m ){
      cout << "OK" << endl;
    }else{
      cout << "Too Many Requests" << endl;
    }
  }
}