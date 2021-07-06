#include <iostream>
#include <cmath>
#define MAX 1000
using namespace std;

int students[MAX+1];
int dp[MAX+1];

int N;

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> students[i];

    for(int i = 1; i<=N; i++){
        int maxNum = 0;
        int minNum = MAX*MAX;

        for(int j = i; j >= 1; j--){
            minNum = min(minNum,students[j]);
            maxNum = max(maxNum,students[j]);
            dp[i] = max(dp[i], dp[j-1]+(maxNum-minNum));
        }
    }
    cout << dp[N] << endl;
    return 0;
}

/*
dp[i] = i까지 나올 수 있는 최대값

dp[]

dp[4] = dp[1] + 

10
2 5 7 1 3 4 8 6 9 3

2일때
2 = 0

5일때
2, 5 = 0
2 5 = 3

7일때
2, 5 7 = 2
2 5, 7 = 3
2 5 7 = 5

1일때

(2 5 7), 1 = dp[3] + 0
2 5, 7 1 = dp[2] + 7 - 1
2, 5 7 1 =  dp[1] + 7 - 1
2 5 7 1 = 7 - 1


*/