/*アルゴリズムと工夫点(Robot Factory/CPU: 53 ms Memory: 55244 KB  Length: 591 B)
貪欲法で解く．
小さいhから順に，できるだけ小さいbとペアを組む貪欲法で解く．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m,k;

int main(){
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    vector<int> h(n),b(m);
    rep(i,n)scanf("%d",&h[i]);
    rep(i,m)scanf("%d",&b[i]);
    sort(h.begin(),h.end());
    sort(b.begin(),b.end());
    i = j = 0;
    while(i < n && j < m){
        if(h[i] <= b[j])i++,j++,k--;
        else j++;
    }
    printf("%s\n",k <= 0 ? "Yes" : "No");
    return 0;
}