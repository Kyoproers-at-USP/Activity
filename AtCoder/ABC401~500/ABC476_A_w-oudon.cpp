# include<iostream>
# include<string>
using namespace std;

int main() {
  string S;
  cin >> S;
  if(S.at(S.size()-1)=='e'){
     S.push_back('r');
     cout << S << endl;
  }
  else{
    S += "er";
    cout << S << endl;
  }
}