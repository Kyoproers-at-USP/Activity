/*アルゴリズムと工夫点(Setsubun/CPU: 1 ms Memory: 3944 KB  Length: 561 B)
二分探索で解く．
条件を整理すると，
(X年後に食べている豆の総数) = 
Σ(i∈[N, N + X]) i - Σ(i∈[1, N - 1]) i = 
(X ^ 2 + (2 * N + 1) * X + 2 * N) / 2
>= K
つまり，"X ^ 2 + (2 * N + 1) * X + 2 * N >= 2 * K"
この条件を満たす最小のXを二分探索すればよい．
最悪計算量は，O(log2(√K)) < 10 ^ 3 となり十分高速．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, k;

int main(){
    const int MAX = (1e5);
    int left = 1, right = MAX;
    scanf("%d%d", &n, &k);
    if(n >= k){
        puts("0");
        return 0;
    }
    while(left < right){
        int mid = (left + right) / 2;
        if(mid + (2 * n + 1) >= (2 * k - 2 * n + mid - 1) / mid)right = mid;
        else left = mid + 1;
    }
    printf("%d\n", left);
    return 0;
}