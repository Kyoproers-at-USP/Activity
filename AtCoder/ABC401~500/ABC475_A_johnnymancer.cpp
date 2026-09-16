// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    string s;
    cin >> s;

    int s_length = s.length();

    rep(i,s_length){
        cout << s.at(i) ;
        if(i != s_length-1){
            cout << "o";
        }
    }
}
