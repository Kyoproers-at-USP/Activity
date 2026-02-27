#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)
#define CAPITAL_MOVE 32;

using namespace std;

int main(){
    string s ;
    cin >> s;
    int tmp = (int)s.at(0) + CAPITAL_MOVE;
    cout << "Of" << char(tmp) << s.erase(0,1) << endl;
}
