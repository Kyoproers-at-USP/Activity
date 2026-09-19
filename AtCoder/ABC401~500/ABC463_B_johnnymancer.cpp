// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n;
    char x;
    cin >> n >> x;

    rep(i,n){
        string s;
        cin >> s;
        if(s.at(char(x) -'A') == 'o'){
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";

}
