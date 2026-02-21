#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n ;
    cin >> n ;
    vector<string> s(n);

    int max = 0;
    rep(i,n){
        cin >> s.at(i) ;
        if(s.at(i).length() > max )max = s.at(i).length();
    }

    rep(i,n){
        rep(j,(max - s.at(i).length())/2)cout << '.' ;
        cout << s.at(i);
        rep(j,(max - s.at(i).length())/2)cout << '.' ;
        cout << endl;
    }
}
