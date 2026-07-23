// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n , m;
    cin >> n >> m;

    vector<int> color_max(m,-1);
    rep(i,n){
        int c , s;
        cin >> c >> s;
        if(s > color_max.at(c-1)){
            color_max.at(c-1) = s;
        }
    }
    rep(i,m){
        cout << color_max.at(i) << " ";
    }
}
