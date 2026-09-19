// AtCoder template
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int t ;
    cin >> t;

    rep(i,t){
        long long x1 , y1 , r1 , x2 , y2 , r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        long long length_between_center;
        length_between_center = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        cout << ( length_between_center <= (r1+r2)*(r1+r2) && length_between_center >= (r1-r2)*(r1-r2)  ? "Yes" : "No") << endl;
    }
}
