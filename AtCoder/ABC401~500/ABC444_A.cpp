#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    string s ;
    cin >> s;

    if(s.at(0) == s.at(1) && s.at(1) == s.at(2)){
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
}