#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

using namespace std;

int main(){
    int n , m;
    cin >> n >> m;

    vector<int> ans(n);

    vector<int> L(n);
    vector<bool> choosed_drink(m+1,false);
    choosed_drink.at(0) = true;
    rep(i,n){
        cin >> L.at(i);
        vector<int> X(L.at(i));

        rep(j,L.at(i)){
            cin >> X.at(j) ;
        }
        rep(j, L.at(i)){
            if(choosed_drink.at(X.at(j)) == false){
                choosed_drink.at(X.at(j)) = true;
                ans.at(i) = X.at(j);
                break;
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        cout << ans.at(i) << endl;
    }
}
