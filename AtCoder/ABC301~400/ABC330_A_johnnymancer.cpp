// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n , l;
    cin >> n >> l;

    int sum_passed = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(a>=l){
            sum_passed++;
        }
    }
    cout << sum_passed;
}
