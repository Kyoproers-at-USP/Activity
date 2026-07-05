// AtCoder template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    double x , y ;
    cin >> x >> y;

    if( (x/16) == (y/9) ){
        cout << "Yes";
        return 0;
    }
    cout << "No";
}
