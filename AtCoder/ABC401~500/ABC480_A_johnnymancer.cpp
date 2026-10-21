// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;

    if( s1.at(0)  == 'A' && s2.at(1) == 'D' || 
        s1.at(1)  == 'A' && s2.at(0) == 'D' ||
        s2.at(0)  == 'A' && s1.at(1) == 'D' ||
        s2.at(1)  == 'A' && s1.at(0) == 'D'){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
}
