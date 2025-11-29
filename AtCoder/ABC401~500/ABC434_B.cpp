#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<double> a(n);
  vector<double> b(n);
  
  vector<double> ave(m,0);
  vector<double> ave_w(m,0);
  
  for(int i = 0 ; i < n ; i++){
    cin >> a.at(i) >> b.at(i);
    ave.at(a.at(i) - 1)++;
    ave_w.at(a.at(i) - 1 ) += b.at(i);
  }
  for(int i = 0 ; i < m ; i++ ){
    //cout << ave_w.at(i) / ave.at(i) << endl;
    printf("%.8f\n",ave_w.at(i)/ave.at(i));
  }
  
}