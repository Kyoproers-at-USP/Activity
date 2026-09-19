// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int a , b ;
    cin >> a >> b;

    if(3*a > 2*b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
