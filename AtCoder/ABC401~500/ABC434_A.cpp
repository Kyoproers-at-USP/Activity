#include <iostream>
#include <vector>
using namespace std;

int main(){
    int w,b;
    cin >> w >> b;
    int n;
    for(n = 1 ; 1000 * w >= n * b ;n++ );
    cout << n << endl;
}