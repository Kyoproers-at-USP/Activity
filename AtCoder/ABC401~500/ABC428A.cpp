#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  int s , a , b , x;
  cin >> s >> a >> b >> x ;
  
  int sum_dis = 0;
  
  for ( int sum_time = 0 ; sum_time <= x ;  ){
    sum_time += a;
    if(sum_time <= x ){
      sum_dis += s * a;
    }else{
      sum_dis += s * (x - sum_time + a);
      cout << sum_dis << endl;
      return 0;
    }
    sum_time += b;
    if(sum_time > x ){
      cout << sum_dis << endl;
      return 0;
    }
    
  }
  
}