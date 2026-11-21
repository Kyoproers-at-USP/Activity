// AtCoder template
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    int min_ball = 10;
    bool nine_flag = false;
    rep(i,n){
        cin >> a.at(i);
        min_ball=min(a.at(i) , min_ball);
        if(a.at(i)==9)nine_flag=true;
    }
    if(nine_flag==1){
        cout << min_ball << endl;
    }else{
        cout << -1 << endl;
    }
}
