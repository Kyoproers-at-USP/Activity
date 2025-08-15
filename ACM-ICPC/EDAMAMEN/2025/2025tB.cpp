/*アルゴリズムと工夫点(Flight Planning/CPU: ? ms Memory: ? KB  Length: - B)
シミュレーションして愚直に解を求める．
※実装担当：N
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

int i;

int main(){
    while(true){
        int n,m;
        cin >> n >> m;
        if(n==0&&m==0) break;
        vector<int> a(m),b(m);
        rep(i,m){
            cin >> a[i] >> b[i];
            a[i]--;
            b[i]--;
        }

        vector<int> cnt(n,0);
        for(int i=0;i<m;i++){
            if(cnt[a[i]]==0){
                cnt[b[i]]++;
            }else if(cnt[a[i]]>=1){
                cnt[a[i]]--;
                cnt[b[i]]++;
            }
        }

        int ans=0;
        rep(i,n){
            ans+=cnt[i];
        }

        cout << ans << endl;
    }
    return 0;
}