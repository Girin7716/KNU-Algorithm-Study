#include <iostream>
using namespace std;

int dp[31];

// 1은 무조건 1칸 차지
// 2는 2칸 차지
// 4는 2칸 차지

int main(){
    int N;
    cin >> N;
    dp[1] = 1;
    dp[0] = 1;

    for(int i = 2; i<=N; i++)
        dp[i] = dp[i-1] + dp[i-2] * 2;

    N%2==1 ? cout << (dp[N] + dp[(N-1)/2])/2 << endl :  cout << (dp[N] + dp[N/2] + dp[N/2 - 1] * 2)/2 << endl; 

    return 0;
}


/*

*/