#include <iostream>
#define MAX 1001
using namespace std;

int N;
int dp[10][MAX];

int main(){

    cin >> N;

    for(int i = 0; i < 10; i++)
        dp[i][1] = 1;

    for(int i = 2; i<=N; i++)
        for(int j = 0; j<10; j++)
            for(int k = 0; k<=j; k++){
                dp[j][i] = dp[j][i] + dp[k][i-1];
                dp[j][i] %= 10007;
            }

    int result = 0;
    for(int i = 0; i<10; i++)
        result += dp[i][N];
    result %= 10007;
    cout << result << endl;

    return 0;
}