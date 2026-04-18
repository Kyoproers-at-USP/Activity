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

    int i ;

    for(i = 0 ; i < n ; i++){
        if(s.at(i) == 'o'){
            continue;
        }else{
            break;
        }
    }

    for(; i < n ; i++){
        cout << s.at(i);
    }
}
