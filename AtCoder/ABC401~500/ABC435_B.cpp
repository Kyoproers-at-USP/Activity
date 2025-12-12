#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  
  for(int i = 0 ; i < n ; i++){
    cin >> a.at(i);
  }
  
  int no_div_ans = 0;
  
  for(int i = 0 ; i < n ; i++){
    for(int j = i ; j < n ; j++){
      int sum = 0 ;
      for(int start = i ; start <= j ; start++){
        sum += a.at(start);
      }
      
      bool flag = true;
      for(int l = i ; l <= j ; l++ ){
        if(sum % a.at(l) == 0){
          flag = false;
        }
      }
      if(flag==true){
        no_div_ans++;
      }
      
    }
  }
  
  cout << no_div_ans << endl;
}