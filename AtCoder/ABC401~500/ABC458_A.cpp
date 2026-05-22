// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    string s;
    int n;
    cin >> s ;
    cin >> n;

    int a = s.size();

    for(int i = n  ; i < a - n ; i++ ){
        cout << s.at(i);
    }


}
