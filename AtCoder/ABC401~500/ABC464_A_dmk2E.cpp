/*アルゴリズムと工夫点(Decisive Battle/CPU: 1 ms Memory: 3652 KB  Length: 392 B)
'E' と 'W' の数をそれぞれ計算して判定すればよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

int main(){
    cin >> s;

    int east = 0, west = 0;
    for(char c : s){
        east += c == 'E';
        west += c == 'W';
    }

    printf("%s\n", east >= west ? "East" : "West");
    return 0;
}