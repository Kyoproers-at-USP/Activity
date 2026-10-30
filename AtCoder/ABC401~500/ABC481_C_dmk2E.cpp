/*アルゴリズムと工夫点(Bank Accounts/CPU: 242 ms Memory: 19392 KB  Length: 568 B)
次に割り当てるIDを保持しつつ，連想配列使ってシミュレーションして解く．
最悪計算量は，O(Q * log2(Q)) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<map>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int q;

int main(){
    scanf("%d", &q);

    int now_id = 1;
    map<string, int> name_to_id;
    while(q--){
        string s;
        cin >> s;

        if(name_to_id.find(s) != name_to_id.end())printf("%d\n", name_to_id[s]);
        else{
            printf("%d\n", now_id);
            name_to_id[s] = now_id;
            now_id++;
        }
    }
    return 0;
}