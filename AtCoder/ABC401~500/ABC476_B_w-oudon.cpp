# include<iostream>
# include<string>
using namespace std;

int main(){
  string S, T;
  int N, z;
  z = 0;
  cin >> N >> S >> T;
  for(int i = 0; i < N; i++){
    char x = S[i];
    char y = T[i];
    if(x == y){
    }
    else if(y == '*'){
    }
    else{
     z = 1;
     break;
    }
  }
  if(z == 1){
    cout << "No" << endl;
  }
  else if(z == 0){
  cout << "Yes" << endl;
  }
}