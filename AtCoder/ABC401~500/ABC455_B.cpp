// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int grid_find(vector<string>& s , int h1 , int h2 , int w1 , int w2){
    for(int i = h1 ; i <= h2 ; i++){
        for(int j = w1 ; j <= w2 ; j++){
            if(s.at(i).at(j) != s.at(h1+h2-i).at(w1+w2-j)){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int h , w ;
    cin >> h >> w;

    vector<string> s(h);
    rep(i,h){
        cin >> s.at(i);
    }

    int ans = 0;
    for(int h1 = 0 ; h1 < h ; h1++){
        for(int h2 = h1 ; h2 < h ; h2++){
            for(int w1 = 0 ; w1 < w ; w1++){
                for(int w2 = w1 ; w2 < w ; w2++){
                    if(grid_find( s, h1, h2 , w1, w2))ans++;
                }
            }
        }
    }

    cout << ans << endl;

}
