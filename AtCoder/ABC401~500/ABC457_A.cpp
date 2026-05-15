// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n ;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a.at(i);
    }
    int x ;
    cin >> x;

    cout << a.at(x-1) << endl;
}
