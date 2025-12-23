/*アルゴリズムと工夫点(Tombola/CPU: 1 ms Memory: 3984 KB  Length: 669 B)
行ごとに整数ごとの数を保持して置けば実装が少し楽．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_A 90
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int h,w,n;

int main(){
    int i,j;
    scanf("%d%d%d", &h, &w, &n);
    vector<vector<int> > row_to_cnt(h, vector<int>(MAX_A, 0));
    vector<int> cnt(h, 0);
    rep(i,h)rep(j,w){
        int a;
        scanf("%d", &a);a--;
        row_to_cnt[i][a]++;
    }
    while(n--){
        int b;
        scanf("%d", &b);b--;
        rep(i,h)cnt[i] += row_to_cnt[i][b];
    }
    j = 0;
    rep(i,h)j = max(j, cnt[i]);
    printf("%d\n", j);
    return 0;
}