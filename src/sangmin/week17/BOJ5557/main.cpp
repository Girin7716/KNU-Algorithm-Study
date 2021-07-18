#include <iostream>
#define MAX 110
using namespace std;

int N;
int ary[MAX];
long long dp[MAX][30];

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++)
        cin >> ary[i];
    ary[0] = 0;
    dp[0][0] = 0;

    dp[1][ary[1]] = 1;
    for(int i = 2; i<=N; i++){
        for(int j = 0; j<=20; j++){
            if(dp[i-1][j] >= 0){
                if(j - ary[i] >= 0) dp[i][j-ary[i]] += dp[i-1][j];
                if(j + ary[i] <= 20) dp[i][j+ary[i]] += dp[i-1][j];
            }
        }
    }

    cout << dp[N-1][ary[N]] << endl;

    return 0;
}