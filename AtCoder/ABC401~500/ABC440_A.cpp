#include <iostream>

using namespace std;

int main(){
    int x , y;

    cin >> x >> y;

    int freq = 0;
    for(int i = 0 ; i < y ; i++){
        x *= 2;
    }
    cout << x << endl;
}