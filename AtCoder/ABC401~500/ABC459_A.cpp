// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    string s = "HelloWorld";
    int x ;
    cin >> x;

    rep(i,s.size()){
        if(i==x-1){
            continue;
        }
        cout << s.at(i);
    }
}
