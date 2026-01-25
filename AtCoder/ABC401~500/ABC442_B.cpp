/*アルゴリズムと工夫点(Music Player/CPU: 12 ms Memory: 3828 KB  Length: 681 B)
シミュレーションして解く．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define THRESH_VOLUME 3
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int q;

int main(){
    int volume = 0, is_play = false;
    scanf("%d", &q);
    while(q--){
        int a;
        scanf("%d", &a);
        switch(a){
            case 1:
                volume++;
                break;
            case 2:
                volume = max(volume - 1, 0);
                break;
            default :
                is_play = !is_play;
        }
        printf("%s\n", is_play && volume >= THRESH_VOLUME ? "Yes" : "No");
    }
    return 0;
}