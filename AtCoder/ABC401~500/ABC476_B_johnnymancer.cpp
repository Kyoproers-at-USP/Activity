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
    string t;
    cin >> s >> t;

    rep(i,n){
        if(t.at(i) == '*')continue;

        if(s.at(i) != t.at(i)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
