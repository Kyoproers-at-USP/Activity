// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    //cout << (int)('0') << endl;
    //cout << (int)('9') << endl;

    string s ;
    cin >> s;

    rep(i,s.length()){
        if(48 <= (int)(s.at(i)) && (int)(s.at(i)) <= 57){
            cout << s.at(i);
        }
    }
}
