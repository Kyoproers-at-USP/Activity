#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    string s ;
    cin >> s;
    cout << (s.at(0) == s.at(s.length() - 1) ? "Yes" : "No") << endl;
}
