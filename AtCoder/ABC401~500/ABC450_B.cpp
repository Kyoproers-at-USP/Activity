/*アルゴリズムと工夫点(Split Ticketing/CPU: 2 ms Memory: 4088 KB  Length: 656 B)
全探索して解く．
N <= 100 であるため，O(N ^ 3) < 10 ^ 7 となり間に合う．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i, j, k;
    scanf("%d", &n);
    const int NIL = -1;
    vector<vector<int> > adj(n, vector<int>(n, NIL));
    rep(i, n){
        for(j = i + 1;j < n;j++){
            int c;
            scanf("%d", &c);
            adj[i][j] = c;
        }
    }
    rep(i, n)rep(j, i)rep(k, j){
        if(adj[k][j] + adj[j][i] < adj[k][i]){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}