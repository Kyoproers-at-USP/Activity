// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    rep(i,n){
        if(s.at(i) == 'A')cout << "Alpha ";
        if(s.at(i) == 'B')cout << "Bravo ";
        if(s.at(i) == 'C')cout << "Charlie ";
    }
}
