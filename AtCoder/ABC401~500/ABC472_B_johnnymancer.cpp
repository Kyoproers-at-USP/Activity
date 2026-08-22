// AtCoder template
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n;
    cin >> n;
    vector<int> L(n);

    rep(i,n){
        cin >> L.at(i);
    }

    int abs_min = 100000;

    rep(i,n-1){
        int fore_sum = 0;
        int lear_sum = 0;    
        rep(j,n){
            if(j <= i){
                fore_sum += L.at(j);
            }else{
                lear_sum += L.at(j);
            }
        }
    if(abs_min > abs(fore_sum-lear_sum)){
                abs_min = abs(fore_sum-lear_sum);
            }
    }

    cout << abs_min << endl;
}
