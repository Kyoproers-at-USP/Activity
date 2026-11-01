// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n , k;
    cin >> n >> k ;
    vector<int> a(n);
    int sum_answer = 0;
    rep(i,n){
        cin >> a.at(i);

        if(i != 0 ){
            if((a.at(i) > k && a.at(i-1) < k) || (a.at(i) < k && a.at(i-1) > k)){
                sum_answer++;
            }else if(a.at(i) == k){
                sum_answer++;
                continue;
            }
        }
        if(a.at(i) == k){
            sum_answer++;
            continue;
        }

    }

    cout << sum_answer << endl;
}
