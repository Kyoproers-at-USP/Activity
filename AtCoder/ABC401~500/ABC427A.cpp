#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
  string ans;
  cin >> ans ;
  
  for(int i = 0 ; i < ans.size() ; i++){
    if(i != ((ans.size())/2) ){
      cout << ans.at(i);
    }
  }
}