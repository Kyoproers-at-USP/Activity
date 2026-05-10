// AtCoder template
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)
const int index_diff = 4; //index_456の通し番号を0~2の範囲に収めるために引く数

int main(){
    vector<vector<int>> a(3,vector<int>(6));

    vector<vector<int>> index_456(3,vector<int>(3)); //4,5,6が何度登場したか記録する配列．
    rep(i,3){
        rep(j,6){
            cin >> a.at(i).at(j);
            int temp = a.at(i).at(j);
            if(temp == 4 || temp == 5 || temp == 6){
                index_456.at(i).at(temp - index_diff)++;
            }
        }
    }

    int answer_patern = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i == j || j == k || i == k) {
                    continue;
                }
                answer_patern += index_456.at(0).at(i) * index_456.at(1).at(j) * index_456.at(2).at(k);
            }
        }
    }
/*
    rep(i,3){
        rep(j,3){
            answer_patern+=min(min( index_456.at( i%3 ).at(j%3),index_456.at( (i+1) % 3).at((j+1)%3) ),index_456.at( (i+2) % 3).at((j+2)%3));
        }
    }
*/

    cout << double(answer_patern)/(6*6*6) << endl;
/*
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            index_456.at(i).at(j)++;
        }
    }
*/

}
