// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);

    int ans_sum = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(i >= (n/2)){
            ans_sum+=a;
        }
    }
    
    cout << ans_sum << endl;
}
