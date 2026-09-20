// AtCoder template
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int main(){
    string s;
    cin >> s;
    if(s.at(s.length()-1) == 'e'){
        cout << s << "r" << endl;
    }else{
        cout << s << "er" << endl;
    }
}
