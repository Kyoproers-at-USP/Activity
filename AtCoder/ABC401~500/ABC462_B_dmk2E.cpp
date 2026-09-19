/*アルゴリズムと工夫点(Gift/CPU: 2 ms Memory: 3932 KB  Length: 872 B)
人毎に，誰からプレゼントをもらったかを管理して解けばよい．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i, j;
    
    scanf("%d", &n);
    vector<vector<int> > given_by(n);

    rep(i, n){
        int k;
        scanf("%d", &k);

        while(k--){
            int a;
            scanf("%d", &a);a--;
            given_by[a].push_back(i);
        }
    }

    rep(i, n){
        printf("%ld", given_by[i].size());
        
        if(given_by[i].size()){
            putchar(' ');

            sort(given_by[i].begin(), given_by[i].end());
            rep(j, given_by[i].size() - 1)printf("%d ", given_by[i][j] + 1);
            printf("%d\n", given_by[i][j] + 1);
        }else puts("");
    }
    return 0;
}