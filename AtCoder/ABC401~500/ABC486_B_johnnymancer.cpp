// AtCoder template
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n , m;
    cin >> n >> m;
    int a;
    int x;
    int y;

    vector<int> current_team(n);

    rep(i,n){
        cin >> a;
        current_team.at(i) = a;
    }

    rep(i,m){
        cin >> x;
        cin >> y;

        rep(j,n){
            if(current_team.at(j)==x){
                current_team.at(j)=y;
            }
        }
    }

    sort(current_team.begin(),current_team.end());
    rep(i,n){
        cout << current_team.at(i) << " " ;
    }
}
