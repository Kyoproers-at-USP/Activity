/*アルゴリズムと工夫点(/CPU:  ms Memory:  KB  Length:  B)

*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i, j, max_chars = 0;
    scanf("%d", &n);
    vector<string> strs(n);
    rep(i, n){
        cin >> strs[i];
        max_chars = max(max_chars, (int)strs[i].length());
    }
    rep(i, n){
        int diff_chars = (max_chars - strs[i].length()) / 2;
        string dots = "";
        while(diff_chars--)dots += '.';
        cout << dots + strs[i] + dots << '\n';
    }
    return 0;
}