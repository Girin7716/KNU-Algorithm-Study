#include <iostream>
#include <cmath>
#define MAX 10
using namespace std;

int main(){
    int result = -1;
    int map[MAX][MAX];
    int N,M;
    scanf("%d %d",&N, &M);
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            scanf("%1d",&map[i][j]);

    for(int i = 0; i<N; i++)
        for (int j = 0; j<M; j++){
            for(int a = -N; a < N; a++){
                for(int b = -M; b < M; b++){

                    if(a == 0 && b == 0) continue;

                    int i1 = i;
                    int j1 = j;
                    int temp = 0;

                    while(i1 < N && i1 >= 0 && j1 < M && j1 >= 0){
                        temp *= 10;
                        temp += map[i1][j1];
                        if(sqrt(temp) == (int)sqrt(temp))
                            if(result < temp)   result = temp;

                        i1 += a;
                        j1 += b;
                    }
                }
            }
        }
    cout << result << endl;
    return 0;
}