#include <iostream>
#include <vector>

using namespace std;

int main(){
    int h,w,n;
    cin >> h >> w >> n;
    
    vector<vector<int>> a(h,vector<int>(w));
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            cin >> a.at(i).at(j);
        }
    }
    
    vector<int> b(n);
    for(int i = 0 ; i < n ; i++){
        cin >> b.at(i);
    }

    int shout_max = 0;

    for(int i = 0 ; i < h ; i++){
        int shout_num = 0;
        for(int j = 0 ; j < w ; j++){
            for(int k = 0 ; k < n ; k++){
                if(a.at(i).at(j) == b.at(k)){
                    shout_num++;
                }
            }
            if(shout_num > shout_max){
                shout_max = shout_num;
            }
        }
    }

    cout << shout_max << endl;

}