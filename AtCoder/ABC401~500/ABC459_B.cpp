/*アルゴリズムと工夫点(459/CPU: 1 ms Memory: 3728 KB  Length: 682 B)
アルファベットごとに，Cの値を配列で保持して処理を行えばよい．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
string s;

int main(){
    int i, j;

    const int ALFA = 26;
    vector<char> alfa_to_val(ALFA);
    j = 0;
    for(i = 2;i < 10;i++){
        int k = 0;
        if(i == 7 || i == 9)k = 4;
        else k = 3;
        while(k--){
            alfa_to_val[j] = '0' + i;
            j++;
        }
    }

    scanf("%d", &n);
    string ans = "";
    rep(i, n){
        cin >> s;
        ans += alfa_to_val[s[0] - 'a'];
    }
    cout << ans << endl;
    return 0;
}