#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> ans(n,vector<int>(n));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            ans.at(i).at(j) = -1;
        }
    }

    ans.at(0).at( ((n-1)/2)) = 1;

    int r = 0;
    int c = (n-1)/2;
    int k = 1;

    for(int i = 0 ; i < ( n * n ) - 1 ; i++){
        k++;
        if(ans.at( ( r - 1 + n ) % n ).at( ( c + 1 ) % n ) == -1){
            ans.at( ( r - 1 + n ) % n ).at( ( c + 1 ) % n ) = k;
            r = (r - 1 + n) % n;
            c = (c + 1) % n;
        }else{
            ans.at( ( r + 1 + n) % n ).at( c ) = k;
            r = (r + 1) % n;
        }
        
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << ans.at(i).at(j) << " ";
        }
        cout << endl;
    }
}