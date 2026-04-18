// AtCoder template
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    int t,x;
    cin >> t >> x;

    int mesured_score = 0;
    vector<int> a(t+1);

    int i = 0;
    cin >> a.at(i);
    cout << i << " " << a.at(i) << endl;
    mesured_score = a.at(i);
    i++;
    for( ; i <= t ; i++){
        cin >> a.at(i);
        if( abs(a.at(i) - mesured_score) >= x){
            mesured_score = a.at(i);
            cout << i << " " << mesured_score << endl;
        }
    }
}
