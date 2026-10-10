// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n ,m;
    cin >> n >> m;

    if(n < m){
        int base = m / n;
        
        rep(i,n){
            if(i < m%n){
                cout << base + 1 << endl;
            }else{
                cout << base << endl;
            }
        }

    }else{
        rep(i,n){
            if(i < m){
                cout  << 1 << endl;
            }else{
                cout  << 0 << endl;
            }
        }
    }
}
