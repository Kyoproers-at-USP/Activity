/*アルゴリズムと工夫点(今日はコンテスト/CPU: ? ms Memory: ? KB  Length: - B)
正の約数を列挙し，愚直に条件判定．
正確には，Nの正の約数の逆数にKを掛けた値の分子と分母を，分母の値をNに合わせるように通分した形で求め，整数値になるか判定する．
最悪計算量は，O(√N)<10^3 となり十分高速．
※実装担当：G
*/
#include<iostream>
#include<cassert>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<algorithm>
// #include<bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

set<ll> func(int n){
    ll i;
    set<ll> p;
    for(i=1;i*i<=n;i++){
        if(n%i==0){
            p.insert(i);
            p.insert(n/i);
        }
    }
    return p;
}

int main(){
    ll n,k;
    while(1){
        cin>>n>>k;
        if(!(n||k))break;
        set<ll> p=func(n);
        ll s=0;
        for(auto a:p){
            s+=k*(n/a);
        }
        if(s%n==0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}