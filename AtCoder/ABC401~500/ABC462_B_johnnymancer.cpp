// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n ;
    cin >> n;

    vector<int> k(n);
    vector<vector<int>> a(n);
    rep(i,n){
        cin >> k.at(i);
        rep(j,k.at(i)){
            int tmp;
            cin >> tmp;
            a.at(i).push_back(tmp);
        }
    }
    
    vector<int> given(n); //人iにプレゼントした人数
    vector<vector<bool>> gift_index(n,vector<bool> (n)); //受け取りの記録

    rep(i,n){
        rep(j,k.at(i)){
            given.at(a.at(i).at(j)-1)++;
            gift_index.at(a.at(i).at(j) - 1).at(i)=true;
        }
    }

    rep(i,n){
        cout << given.at(i) << " ";
        rep(j,n){
            if(gift_index.at(i).at(j) == true){
                cout << j+1 << " ";
            }
        }
        cout << endl;
    }

    
}
