#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    string s;
    cin >> s;
    int num_dot = 0;
    
    rep(i,s.length()){
        if(s.at(i) == 'i' || s.at(i) == 'j'){
            num_dot++;
        }
    }

    cout << num_dot << endl;
}