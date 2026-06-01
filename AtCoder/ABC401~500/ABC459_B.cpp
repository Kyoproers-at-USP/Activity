// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n ;
    cin >> n;
    vector<string> s(n);

    rep(i,n){
        cin >> s.at(i);
        if(s.at(i).at(0)== 'a' || s.at(i).at(0)== 'b' || s.at(i).at(0)== 'c')cout << 2;
        if(s.at(i).at(0)== 'd' || s.at(i).at(0)== 'e' || s.at(i).at(0)== 'f')cout << 3;
        if(s.at(i).at(0)== 'g' || s.at(i).at(0)== 'h' || s.at(i).at(0)== 'i')cout << 4;
        if(s.at(i).at(0)== 'j' || s.at(i).at(0)== 'k' || s.at(i).at(0)== 'l')cout << 5;
        if(s.at(i).at(0)== 'm' || s.at(i).at(0)== 'n' || s.at(i).at(0)== 'o')cout << 6;
        if(s.at(i).at(0)== 'p' || s.at(i).at(0)== 'q' || s.at(i).at(0)== 'r' || s.at(i).at(0)== 's')cout << 7;
        if(s.at(i).at(0)== 't' || s.at(i).at(0)== 'u' || s.at(i).at(0)== 'v')cout << 8;
        if(s.at(i).at(0)== 'w' || s.at(i).at(0)== 'x' || s.at(i).at(0)== 'y' || s.at(i).at(0) == 'z')cout << 9;
    }
}
