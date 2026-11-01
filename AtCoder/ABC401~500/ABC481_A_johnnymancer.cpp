// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int a , b;
    cin >> a >> b;

    if((a+b)/10 == 0){
        cout << 1 << endl;
    }else{
        cout << 2 << endl;
    }
}
