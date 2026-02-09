#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n,k;
    cin >> n >> k ;

    int ans_sum = 0;
    rep(i,n+1){
        int sum = 0 ;

        string s = to_string(i);
        
        int s_size = s.length();
        rep(j,s_size){
            sum += (int)(s.at(j) - '0');
        }

        if(sum == k){
            ans_sum++;
        }
    }
    cout << ans_sum << endl;
}