// AtCoder template
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int h , w;
    cin >> h >> w;
    //vector<vector<int>> x(h,vector<int>(w));

    //もし1つしかマスが無いなら0を出力．
    if(h == 1 && w == 1){
        cout << 0 << endl;
        return 0;
    }

    //hかwが1なら，隣接数は始点と終点が1で挟まれている部分は2になるから，条件分岐で直接出す．
    // wが1のパターンは改行を行う．
    if(h == 1 || w == 1){
        rep(i,max(h,w)){
            if(i == 0 || i == max(h,w) - 1){
                cout << 1 << " ";
                if(h == max(h,w))cout << endl;
                continue;
            }
            cout << 2 << " " ;
            if(h == max(h,w))cout << endl;
        }
        return 0;
    }

    //h != 1 , w != 1 (h > 0 , w > 0)で，グリッドの隅のマスは必ず2になり，
    //隅にオセロの要領で挟まれたグリッドは3になる．それ以外のグリッドは4になる．
    rep(i,h){
        rep(j,w){
            if(i == 0 || i == h-1){
                if(j == 0 || j == w-1 ){
                    cout << 2 << " " ;
                    continue;
                }
                cout << 3 << " " ;
                continue;
            }
            if(j == 0 || j == w-1){
                cout << 3 << " ";
                continue;
            }
            cout << 4 << " " ;
        }
        cout << endl;
    }
}
