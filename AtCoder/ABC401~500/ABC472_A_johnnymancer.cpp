// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    string S;
    cin >> S;

    rep(i,S.length()){
        if(S.at(i) != 'A'){
            cout << '.';
            continue;
        }
        cout << S.at(i);
    }
}
