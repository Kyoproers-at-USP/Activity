// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int n , m ;
    cin >> n >> m;

    int answer = 0;
    while(m != 0){
        m = n%m;
        answer++;
    }
    cout << answer;
}
