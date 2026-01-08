/*アルゴリズムと工夫点(Happy Number/CPU: 1 ms Memory: 3820 KB  Length: 619 B)
ループしないか判定しながらシミュレーションして解く．
*/
#include<iostream>
#include<map>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int getNext(int n){
    int ans = 0;
    string str = to_string(n);
    for(char c : str)ans += (c - '0') * (c - '0');
    return ans;
}

int main(){
    int i,j;
    map<int, bool> dict;
    scanf("%d", &n);
    dict[n] = true;
    while(n != 1){
        n = getNext(n);
        if(dict[n]){
            puts("No");
            return 0;
        }
        dict[n] = true;
    }
    puts("Yes");
    return 0;
}