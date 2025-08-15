/*アルゴリズムと工夫点(働き者のカレンダー/CPU: ? ms Memory: ? KB  Length: - B)
平日の日数から，元々平日だが休日となった日数を数え上げる．
期間[1,m]ではなく，期間[0,m-1]で平日の日数を数え上げる（日にちは全て-1しておく）．
この期間での平日日数は，"5*floor(m/7)+min(5,m%7)"となる．
その後追加休日の一覧を順次見て，7で割った余りから平日か判定し，適宜平日日数から引く．
重複の対処ではsetを使用しており，最悪計算量は O(n*log2(n))<10^4 となり十分高速．
実装担当：G
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

int main(){
    ll n,m,a;
    while (1)
    {
        cin>>n>>m;
        if(n==0&&m==0)break;
        set<ll> d;
        while(n--){
            cin>>a;
            a--;
            if(a<m){
                d.insert(a);
            }
        }
        ll sum=5*(m/7)+min(5LL,(m%7));
        for(auto i:d){
            if(!(i%7==5||i%7==6))
                sum--;
        }
        cout<<sum<<endl;
    }
    return 0;
}