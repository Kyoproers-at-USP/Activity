/*アルゴリズムと工夫点(Alphametic Prime/CPU: 148 ms Memory: 8868 KB  Length: 1727 B)
エラトステネスの篩 + 条件判定の高速化 で解く．
Sの最大の長さは7であるから，扱う最大の素数の値は 10 ^ 7 未満となる．
そのため素数の列挙はエラトステネスの篩で間に合う．
列挙した後は，その各桁毎に「添え字」をグルーピングし，下記の条件を満たすか判定すればよい．
 ・各グループごとに一意な文字を割り当てられる
 ・グループ内の添え字に対応するS上の文字は同一
最悪計算量は，O(10 ^ |S| * (log(log(10 ^ |S|)) + |S|)) ≒ 10 ^ 8 となり，間に合う．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

vector<int> getPrimes(int min_val, int max_val){
    int i, j;
    vector<bool> is_prime(max_val + 1, true);
    is_prime[0] = is_prime[1] = false;

    vector<int> primes;
    for(i = 2;i <= max_val;i++){
        if(is_prime[i]){
            if(i >= min_val)primes.push_back(i);
            
            j = 2 * i;
            while(j <= max_val){
                is_prime[j] = false;
                j += i;
            }
        }
    }

    return primes;
}

int main(){
    int i, j;
    const int MAX_DIGIT_NUM = 10;
    const char NIL = '*';

    cin >> s;
    i = j = 1;
    while(j < s.length()){
        i *= 10;
        j++;
    }
    vector<int> primes = getPrimes(
        /* min_val = */ i, 
        /* max_val = */ i * 10
    );

    auto judge = [&](string num) -> bool{
        int i;
        vector<vector<int> > num_to_ids(MAX_DIGIT_NUM);
        rep(i, num.size())num_to_ids[num[i] - '0'].push_back(i);
        
        int is_used = 0;
        rep(i, num_to_ids.size())if(num_to_ids[i].size() >= 1){
            char target = s[num_to_ids[i][0]];
            if((is_used >> (target - 'a')) & 1)return false;
            is_used |= (1 << (target - 'a'));

            for(int id : num_to_ids[i])if(s[id] != target)return false;
        }

        return true;
    };
    for(int prime : primes){
        if(judge(/* num = */ to_string(prime))){
            printf("%d\n", prime);
            return 0;
        }
    }
    puts("-1");
    return 0;
}