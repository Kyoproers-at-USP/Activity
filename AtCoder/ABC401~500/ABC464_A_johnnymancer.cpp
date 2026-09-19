// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    string s;
    cin >> s;

    int num_e , num_w;
    rep(i,s.length()){
        if(s.at(i)=='E'){
            num_e++;
        }else{
            num_w++;
        }
    }

    if(num_e>num_w){
        cout << "East";
    }else{
        cout << "West";
    }
}
