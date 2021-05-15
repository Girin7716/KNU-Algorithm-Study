#include <iostream>
#include <algorithm>
#include <cstring>
#define INF -0x1fffffff
#define MAX 100
using namespace std;

int dp[MAX+1][51];
int ary[MAX+1];
int sum[MAX+2];
bool check[MAX+1][51];
int N,M;

int calc(int k, int cnt) {
	if (cnt == 0) return 0;
	if (k <= 0) return INF;

	if (check[k][cnt]) return dp[k][cnt];
	check[k][cnt] = true;

	int& ret = dp[k][cnt];
	
	ret = calc(k-1,cnt);
	for (int i = 1; i <= k; i++)
		ret = max(calc(i - 2, cnt - 1) + sum[k] - sum[i - 1], ret);

	return ret;
}

int main(){
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        cin >> ary[i];
        sum[i] = sum[i-1] + ary[i];
    }

    memset(check, false, sizeof(check));

    int result = calc(N,M);
    cout << result << endl;
    return 0;
}

/*
6 2
-1
3
1
2
4
-1
*/