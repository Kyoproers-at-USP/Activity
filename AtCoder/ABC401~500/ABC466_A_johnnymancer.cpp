// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n;
    cin >> n;

    rep(i,n){
        int x;
        cin >> x;
        if(x>=0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
