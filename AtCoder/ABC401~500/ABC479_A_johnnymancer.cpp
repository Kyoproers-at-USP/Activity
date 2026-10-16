// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n;
    cin >> n;
    int sum = 0;
    rep(i,n){
        int tmp ;
        cin >> tmp;
        if(i%2 != 0){
            continue;
        }
        sum += tmp;
    }
    cout << sum << endl;
}
