//しばらく期末テスト対策でA問題だけやります。

// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repkai(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(){
  int p,q,x,y;
  cin >> p >> q >> x >> y;
  
  if( p <= x && x <= p + 99 && q <= y &&  y <= q + 99){
    cout << "Yes" << endl;
    return 0;
  }
  
  cout << "No" << endl;
  
}