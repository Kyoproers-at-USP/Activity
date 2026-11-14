// Atcoder template
#include <iostream>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0; i < int(n) ; i++)

int main(){
  int n ;
  cin >> n;

  int sheet =0;
  sheet = n / 2 + n % 2;

  cout << sheet << endl;
}