#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N, Ans;
    cin >> N;
    if(N%2==0){
        Ans = N/2;
    }
    else{
        N += 1;
        Ans = N/2;
    }
    cout << Ans << endl;
}