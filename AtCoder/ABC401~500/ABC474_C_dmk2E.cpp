/*アルゴリズムと工夫点(Remove and Append/CPU: 34 ms Memory: 7160 KB  Length: 1455 B)
双方向循環リストを実装して解く．
配列上の各値について，リスト上の要素とみなすことで，削除の操作を高速化する．
操作後の配列はリストの先頭から辿っていけば求められる．
最悪計算量は，O(N + Q) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int NIL = 0;

struct Node{
    int prev, nxt;

    Node(int prev = NIL, int nxt = NIL):prev(prev), nxt(nxt){};
};

int n, q;

int main(){
    int i;

    scanf("%d%d", &n, &q);
    vector<int> p(n);
    rep(i, n)scanf("%d", &p[i]);

    vector<Node> val_to_node(n + 1);

    auto appendNode = [&](int val) -> void{
        int last = val_to_node[0].prev;
        val_to_node[0].prev = val;

        val_to_node[val].nxt = val_to_node[last].nxt;
        val_to_node[last].nxt = val;
        val_to_node[val].prev = last;
    };
    rep(i, n)appendNode(/* val = */ p[i]);

    auto deleteNode = [&](int val) -> void{
        int prev_val = val_to_node[val].prev;
        int nxt_val = val_to_node[val].nxt;

        val_to_node[prev_val].nxt = nxt_val;
        val_to_node[nxt_val].prev = prev_val;
    };
    int now_last = p[n - 1];
    while(q--){
        int a;
        scanf("%d", &a);

        deleteNode(/* val = */ a);
        appendNode(/* val = */ a);

        now_last = a;
    }

    vector<int> ans;
    i = val_to_node[0].nxt;
    while(i != NIL){
        ans.push_back(i);
        i = val_to_node[i].nxt;
    }

    rep(i, n - 1)printf("%d ", ans[i]);
    printf("%d\n", ans[i]);
    return 0;
}