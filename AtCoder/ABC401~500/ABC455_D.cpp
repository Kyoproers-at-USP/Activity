/*アルゴリズムと工夫点(Card Pile Query/CPU: 79 ms Memory: 18196 KB  Length: 2354 B)
双方向リストで解く．
各山で独立したリストを保持しておき，各カードを「リストの要素」として表現する．
そうすることで順序を保ったまま，カードの移動が高速にできる．
各リストの要素数は，先頭から数え上げればよい．
最悪計算量は，O(N + Q) < 10 ^ 7 となり高速．
※ 循環リストの機能を含めようとすると，カードの移動時に，指定されたカードの山を求める必要があり，計算量が悪化する
※ 双方向リストは単方向リストの上位互換ではあるが，循環リストの機能も付加するどうかは要件によって決めること
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template<typename T>
class Node{
public:
    T value;
    int prev_id;
    int next_id;
    static const int NIL = -1;

    Node(
        T value, 
        int prev_id = NIL, 
        int next_id = NIL
    ): value(value), 
       prev_id(prev_id), 
       next_id(next_id){}
};

template<typename T>
class DoublyLinkedList{
public: 
    vector<Node<T> > nodes;
    vector<int> node_heads, card_to_node_id;

    DoublyLinkedList(int size, T nil){
        int i;
        rep(i, size){
            this -> node_heads.push_back(nodes.size());
            this -> nodes.push_back(Node<T>(
                /* value = */ nil
            ));
        }

        this -> card_to_node_id = vector<int>(size);
    }

    void addNode(int node_id, T value){
        int new_node_id = this -> nodes.size();
        card_to_node_id[value] = new_node_id;

        nodes.push_back(Node(
            /* value = */ value, 
            /* prev_id = */ node_id
        ));
        this -> nodes[node_id].next_id = new_node_id;
    }

    void moveCards(int c, int p){
        int c_node_id = card_to_node_id[c];
        this -> nodes[this -> nodes[c_node_id].prev_id].next_id = Node<T>::NIL;
        
        int p_node_id = card_to_node_id[p];
        this -> nodes[p_node_id].next_id = c_node_id;
        this -> nodes[c_node_id].prev_id = p_node_id;
    }

    int countNodes(int head_index){
        int now_node_id = node_heads[head_index], ans = 0;

        while(nodes[now_node_id].next_id != Node<T>::NIL){
            now_node_id = nodes[now_node_id].next_id;
            ans++;
        }
        return ans;
    }
};

int n, q;

int main(){
    int i, j;
    scanf("%d%d", &n, &q);

    DoublyLinkedList<int> list(/* size = */ n, /* nil = */ -1);
    rep(i, n)list.addNode(/* node_id = */ i, /* value = */ i);

    while(q--){
        int c, p;
        scanf("%d%d", &c, &p);
        c--;p--;
        list.moveCards(/* c = */ c, /* p = */ p);
    }

    rep(i, n - 1)printf("%d ", list.countNodes(/* head_index = */ i));
    printf("%d\n", list.countNodes(/* head_index = */ i));
    return 0;
}