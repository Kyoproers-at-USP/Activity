/*アルゴリズムと工夫点(Looped Rope/CPU: 1 ms Memory: 3860 KB  Length: 895 B)
全探索で解く．
各マスについて，上下左右に隣なっているかの判定は関数でまとめると楽かも．
※ バーチャル参加
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int h,w;

int main(){
    int i,j;
    scanf("%d%d",&h,&w);
    vector<string> ipt(h);
    rep(i,h)cin>>ipt[i];
    const int dy[] = {-1,0,1,0},MAX_D = 4;
    const int dx[] = {0,1,0,-1};
    auto judge = [&](int y,int x)->bool{
        int i,cnt=0;
        rep(i,MAX_D){
            int nxt_y = y + dy[i],nxt_x = x + dx[i];
            if(
                0<=nxt_y&&nxt_y<h&&
                0<=nxt_x&&nxt_x<w&&
                ipt[nxt_y][nxt_x] == '#'
            )cnt++;
        }
        return cnt == 2 || cnt == 4;
    };
    rep(i,h)rep(j,w){
        if(ipt[i][j] == '#'&&!judge(i,j)){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}