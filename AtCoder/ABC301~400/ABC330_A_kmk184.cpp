#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)n; i++)
using ll=long long;
using P=pair<int,int>;

int main(){
    int n,l;
    cin >> n >> l;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int cnt=0;
    rep(i,n){
        if(a[i]>=l) cnt++;
    }
    cout << cnt << endl;
    return 0;
}