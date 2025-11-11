// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repkai(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(){
  int x,n,q ;
  cin >> x >> n;
  
  vector<int> w(n);
  rep(i,n){
    cin >> w.at(i);
  }
  
  cin >> q;
  vector<int> p(q);
  rep(i,q){
    cin >> p.at(i);
  }
  
  vector<int> status(n,0);
  
  int robot_w = x ;
  rep(i,q){
    if(status.at(p.at(i) - 1) == 0){
      robot_w += w.at(p.at(i) - 1);
      status.at(p.at(i) - 1) = 1;
    }else{
      robot_w -= w.at(p.at(i) - 1);
      status.at(p.at(i) - 1) = 0;
    }
    cout << robot_w << endl;
  }
  
}
