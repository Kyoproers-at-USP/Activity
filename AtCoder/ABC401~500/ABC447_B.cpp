#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

using namespace std;

int main(){
    string s ;
    cin >> s;

    vector<int> character_count(26);

    //登場する文字をアスキーで変換して0baseインデックスに保存
    rep(i,s.length()){
        character_count.at((int)(s.at(i)) - 'a' )++;
    }

    //最瀕の文字が何回出てくるか調べる。
    int max = 0;
    rep(i,s.length()){
        if(character_count.at((int)(s.at(i)) - 'a'  ) > max){
            max = character_count.at((int)(s.at(i)) - 'a'  );
        }
    }

    //全英小文字のインデックスをboolで作成。最大数maxと各文字の頻度が一致するか調べ、一致したものはtrueとする。
    vector<bool> character_count_bool(26,false);
    rep(i,s.length()){
        if(character_count.at((int)(s.at(i)) - 'a'  ) == max){
            character_count_bool.at((int)(s.at(i)) - 'a' ) = true;
        }
    }

    //最大数登場する文字はスキップして出力.
    rep(i,s.length()){
        if(character_count_bool.at((int)(s.at(i)) - 'a' ) == true){
            //cout << i << ' ';
            continue;
        }
        cout << s.at(i);
    }
    cout << endl;
}
