#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

using namespace std;

int main(){
    int n , m ;
    cin >> n >> m;

    if(n % 2 != 0)n++;

    if( n/2 >= m){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
