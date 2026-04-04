/*アルゴリズムと工夫点(Concat Power of 2/CPU: 63 ms Memory: 11704 KB  Length: 1610 B)
再帰全探索 + ソート で解く．
N番目の「良い整数」の値が 10 ^ 9 以下であるため，
最大9桁の整数について考えればよく，総数Sは S = 1257874 < 10 ^ 7 であるため全列挙しても高速に処理可能．
最悪計算量は，O(S * log2(S)) < 10 ^ 8 となり，間に合う．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int to_integer(string& str){
    int ans = 0;
    for(char c : str){
        ans *= 10;
        ans += (int)c - (int)'0';
    }
    return ans;
}

int main(){
    int i, j;
    // 前処理
    const int MAX = 30, MAX_LENGTH = 9;
    vector<vector<string> > len_to_power_two(MAX_LENGTH + 1);
    rep(i, MAX){
        int power_two = (1 << i);
        string str_num = to_string(power_two);
        len_to_power_two[str_num.length()].push_back(str_num);
    }
    
    // 本処理
    vector<int> nums;
    auto rec = [&](auto& func, int digit, string now_str) -> void{
        int i;
        if(now_str.length() == digit){
            nums.push_back(to_integer(/* str =  */ now_str));
            return ;
        }
        for(i = 1;now_str.length() + i <= digit;i++){
            for(string str : len_to_power_two[i]){
                func(
                    /* func = */ func, 
                    /* digit = */ digit, 
                    /* now_str = */ now_str + str
                );
            }
        }
    };
    rep(i, MAX_LENGTH){
        rec(
            /* func = */ rec, 
            /* digit = */ i + 1, 
            /* now_str = */ ""
        );
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    scanf("%d", &n);
    printf("%d\n", nums[n - 1]);
    return 0;
}