/*アルゴリズムと工夫点(Reverse Permutation/CPU: 69 ms Memory: 33624 KB  Length: 1396 B)
逆順操作シミュレーションで解く．
順列の区間は，'x' から始まり，'o' で終了している部分列で，区間分けが可能．
この各区間について，最終的な位置と，反転するか否かが分かればよい．
S 上で最後の'o' を含む区間から順にみていくと，下記のような性質が見られる．
 ・区間の数列の並びについて，「反転する」，「反転しない」，「反転する」... を繰り返していく
 ・最終的な位置は，まだ決まっていない最終出力配列上の，「左端」，「右端」，「左端」... を繰り返していく
最悪計算量は O(N) < 10 ^ 7 (定数倍込み) となり，高速．
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
string s;

int main(){
    int i, j;

    cin >> n >> s;
    vector<int> tail_arr;
    while(s.back() == 'x'){
        s.pop_back();
        tail_arr.push_back(n);
        n--;
    }
    reverse(tail_arr.begin(), tail_arr.end());

    vector<vector<int> > arrs;
    i = 0;
    while(i < n){
        vector<int> arr;

        while(i < n && s[i] == 'x'){
            arr.push_back(i + 1);
            i++;
        }
        arr.push_back(i + 1);
        i++;

        arrs.push_back(arr);
    }

    vector<int> ans(n);
    int start = 0, last = n - 1;
    bool is_reverse = true;
    while(arrs.size()){
        auto cur = arrs.back();arrs.pop_back();

        if(is_reverse){
            for(i = cur.size() - 1;i >= 0;i--){
                ans[start] = cur[i];
                start++;
            }
        }else{
            for(i = cur.size() - 1;i >= 0;i--){
                ans[last] = cur[i];
                last--;
            }
        }

        is_reverse = !is_reverse;
    }

    for(int num : tail_arr)ans.push_back(num);
    rep(i, ans.size() - 1)printf("%d ", ans[i]);
    printf("%d\n", ans[i]);
    return 0;
}
