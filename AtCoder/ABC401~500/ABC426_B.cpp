// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  for(int i = 0 ; i < s.size() - 1 ; i++){
    if(s.at(i) != s.at(i+1)){
      if(i != 0 && s.at(i - 1) == s.at(i+1) ){
        cout << s.at(i) << endl;
        return 0;
      }else if( i != 0 && s.at( i - 1 ) != s.at(i + 1)){
        cout << s.at(i + 1) << endl;
        return 0;
      }
    }
  }
  cout << s.at(0) << endl;
}