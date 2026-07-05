// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n , l;
    cin >> n >> l;

    int passed_count = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(a>=l){
            passed_count++;
        }
    }
    cout << passed_count << endl;
}
