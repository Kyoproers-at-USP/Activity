/*アルゴリズムと工夫点(Puddles/CPU: 22 ms Memory: 4144 KB  Length: 1478 B)
BFS で解く．
白色のマス目について幅優先探索を行い，順番に白色領域を探索していく．
その際，グリッドの最外周を含むか判定し，黒マスに囲われた領域かどうかを判定する．
最悪計算量は，O(H * W) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> P;

int h, w;

int main(){
    int i, j;
    scanf("%d%d", &h, &w);
    vector<vector<bool> > is_white(h, vector<bool>(w));
    rep(i, h){
        getchar();
        rep(j, w)is_white[i][j] = getchar() == '.';
    }

    const int dy[] = {-1, 0, 1, 0}, MAX_D = 4;
    const int dx[] = {0, 1, 0, -1};
    auto bfs = [&](int y, int x) -> bool{
        int i;
        bool judge = true;
        queue<P> que;
        que.push(P(y, x));
        is_white[y][x] = false;
        while(que.size()){
            auto [now_y, now_x] = que.front();que.pop();
            if(
                now_y == 0 || now_y == h - 1 || 
                now_x == 0 || now_x == w - 1
            )judge = false;
            rep(i, MAX_D){
                y = now_y + dy[i];
                x = now_x + dx[i];
                if(
                    0 <= y && y < h && 
                    0 <= x && x < w &&
                    is_white[y][x]
                ){
                    is_white[y][x] = false;
                    que.push(P(y, x));
                }
            }
        }
        return judge;
    };

    int ans = 0;
    rep(i, h)rep(j, w)if(is_white[i][j])ans += bfs(i, j);
    printf("%d\n", ans);
    return 0;
}