#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  // - 48
  
  int n , a, b;
  
  cin >> n >> a >> b;
  
  int sum = 0;
  
  for(int i = 1 ; i <= n ; i++){
    if(i >= 0 && i < 10){
      if(i <= b && i >= a){
        sum+=i;
      }
    }
    if(i >= 10 && i < 100){
      if( (int)(i/10) + (i % 10) <= b && (int)(i/10) + (i % 10) >= a ){
        sum+=i;
      }
    }
    if( i >= 100 && i < 1000){
      if( (int)(i/100) + (i%100)/10 + (i%10)  <= b && (int)(i/100) + (i%100)/10 + (i%10) >= a ){
        sum+=i;
      }
    }
    if( i >= 1000 && i < 10000 ){
      if( (int)(i/1000)  + (i%1000)/100 + (i%100)/10 + (i%10) <= b && (int)(i/1000)  + (i%1000)/100 + (i%100)/10 + (i%10) >= a){
        sum+=i;
      }
    }
    if( i == 10000){
      if( 1 >= a && 1 <= b){
        sum+=i;
      }
      
    }
  }
  cout << sum << endl;
}
