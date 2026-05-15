// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n ; cin >> n;
    vector<vector<int>> a(n,vector<int>(0));

    rep(i,n){
        int l ;cin >> l;

        rep(j,l){
            int push_num; cin >> push_num;
            a.at(i).push_back(push_num);
        }
    }

    int x , y;
    cin >> x >> y;

    cout << a.at(x-1).at(y-1) << endl;
}
