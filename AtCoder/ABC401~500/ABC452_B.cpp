// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int h,w;
    cin >> h >> w;

    rep(i,w){
        cout << '#' ;
    }
    cout << endl;

    rep(i,h-2){
        cout << '#';
        rep(j,w-2){
            cout << '.';
        }
        cout << '#' << endl;
    }

    rep(i,w){
        cout << '#' ;
    }
    cout << endl;
}
