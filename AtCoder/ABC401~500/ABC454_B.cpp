// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n , m;
    cin >> n >> m;

    vector<int> f(n);
    vector<int> cloth(m);

    rep(i,n){
        cin >> f.at(i);
        cloth.at(f.at(i)-1)++;
    }

    int flag = 1;
    rep(i,n){
        if(cloth.at(f.at(i)-1) == 1){
            continue;
        }else{
            cout <<"No" << endl;
            flag=0;
            break;
        }
    }

    if(flag)cout << "Yes" << endl;

    rep(i,m){
        if(cloth.at(i) == 0 ){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}
