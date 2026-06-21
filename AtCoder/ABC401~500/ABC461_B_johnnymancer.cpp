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
    vector<int> b(n);

    rep(i,n){
        cin >> a.at(i);
    }
    rep(i,n){
        cin >> b.at(i);
    }

    rep(i,n){
        if(i != b.at(a.at(i)-1)-1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
