/*アルゴリズムと工夫点(Faucets and Drains/CPU: 1 ms Memory: 3868 KB  Length: 734 B)
入力される N * M 個の二次元文字列について，1行または1列全てが'o'であるかを判定すればよい．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;

int main(){
    int i, j;

    scanf("%d%d", &n, &m);
    vector<bool> faucet(n, false), drain(m, false);
    rep(i, n){
        string s;
        cin >> s;

        rep(j, m)if(s[j] == 'o'){
            faucet[i] = true;
            drain[j] = true;
        }
    }

    rep(i, n)if(faucet[i] == false){
        printf("Faucet %d\n", i + 1);
        break;
    }
    if(i == n){
        rep(i, m)if(drain[i] == false){
            printf("Drain %d\n", i + 1);
            break;
        }
    }
    return 0;
}