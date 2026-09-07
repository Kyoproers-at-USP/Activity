// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n;
    cin >> n;

    vector<int> a(101);

    rep(i,n){
        int tmp = 0;
        cin >> tmp;
        a.at(tmp)++;
    }

    int ans_sum = 0;
    rep(i,101){
        a.at(i) %= 2;
        if(a.at(i) == 1){
            ans_sum += i;
        }
    }

    cout << ans_sum << endl;

}
