#include <iostream>
#define MAX 50
using namespace std;

int map[MAX+1];
int N;
int target;
bool isParent[MAX+1];

int main(){
    cin >> N;
    for(int i = 0; i<N; i++){
        scanf("%d",&map[i]);
        if(map[i] == -1)
            isParent[i] = true;
        else
            isParent[map[i]] = true;
    }
    cin >> target;
    int targetParent = map[target];
    isParent[targetParent] = false;
    for(int i = 0; i<N; i++){
        if(i != target && map[i] == targetParent)
            isParent[targetParent] = true;
    }

    isParent[target] = true;

    for(int i = 0; i<N; i++){
        if(!isParent[i]){
            int idx = map[i];
            while(idx != -1){
                if(idx == target)
                    isParent[i] = true;
                idx = map[idx];
            }
        }
    }
    int result = 0;
    for(int i = 0; i<N; i++)
        if(!isParent[i]) result++;

    cout << result << endl;

    return 0;
}

/*
5
-1 0 0 1 1
2

5
-1 0 0 1 1
1

5
-1 0 0 1 1
0

9
-1 0 0 2 2 4 4 6 6
4

4

-1 0 1 2

2

지워서 리프가 되는 경우도 생각하기


*/