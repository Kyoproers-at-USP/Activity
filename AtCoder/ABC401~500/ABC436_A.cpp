#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;

    for(int i = 0 ; i < n - s.length() ; i++){
        cout << 'o' ;
    }

    cout << s << endl;
}