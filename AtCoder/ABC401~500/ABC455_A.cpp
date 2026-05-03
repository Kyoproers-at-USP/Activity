// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int a,b,c;
    cin >> a >> b >> c;

    if(a!=b){
        if(b==c){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
