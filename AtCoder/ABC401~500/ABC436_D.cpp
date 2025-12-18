/*アルゴリズムと工夫点(Teleport Maze/CPU: 55 ms Memory: 25476 KB  Length: 1833 B)
超頂点を用いたBFSで解く．
アルファベットごとに1つずつ超頂点を用意し，その頂点と同じアルファベットの頂点全てが辺で繋がったグラフを考える．
最悪計算量は，O(H + W) < 10^7 となり高速．
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int> P;

int h,w;

int main(){
    int i,j;
    const int ALFA = 26, NIL = -1;
    scanf("%d%d",&h,&w);
    vector<string> mp(h);
    rep(i,h)cin >> mp[i];
    vector<vector<P> > alfa_to_point(ALFA);
    rep(i,h)rep(j,w)if('a' <= mp[i][j] && mp[i][j] <= 'z'){
        alfa_to_point[mp[i][j] - 'a'].push_back(P(i,j));
    }
    auto bfs = [&]() -> int{
        int i;
        const int dy[] = {-1, 0, 1, 0}, MAX_D = 4;
        const int dx[] = {0, 1, 0, -1};
        queue<P> que;
        vector<vector<int> > vis(h, vector<int>(w, NIL));
        vector<bool> is_used(ALFA, false);
        que.push(P(0,0));
        vis[0][0] = 0;
        while(que.size()){
            P now = que.front();que.pop();
            if('a' <= mp[now.first][now.second] && mp[now.first][now.second] <= 'z' && is_used[mp[now.first][now.second] - 'a'] == false){
                is_used[mp[now.first][now.second] - 'a'] = true;
                for(auto [y,x] : alfa_to_point[mp[now.first][now.second] - 'a'])if(vis[y][x] == NIL){
                    vis[y][x] = vis[now.first][now.second] + 1;
                    que.push(P(y,x));
                }
            }
            rep(i,MAX_D){
                int y = now.first + dy[i];
                int x = now.second + dx[i];
                if(0 <= y && y < h && 0 <= x && x < w && mp[y][x] != '#' && vis[y][x] == NIL){
                    vis[y][x] = vis[now.first][now.second] + 1;
                    que.push(P(y,x));
                }
            }
        }
        return vis[h - 1][w - 1];
    };
    printf("%d\n", bfs());
    return 0;
}