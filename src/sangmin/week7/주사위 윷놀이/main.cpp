#include <iostream>
#include <vector>
#define MAX 10

using namespace std;
int sequence[MAX];

int Max = 0;
int map[35];
int value[35];
bool visit[35];
int hourse[4];

void dfs(int level, int sum);

int main(){
    for(int i = 0; i<MAX; i++)
        cin >> sequence[i];

    for(int i = 0; i<21; i++){
        map[i] = i+1; // next map
        value[i] = i*2;
    }
    map[21] = 21;
    for(int i = 22; i<27; i++)
        map[i] = i + 1;

    map[28] = 29; map[29] = 30; map[30] = 25;
    map[31] = 32; map[32] = 25; map[27] = 20;

    value[22] = 13; value[23] = 16;
    value[24] = 19; value[25] = 25;
    value[26] = 30; value[27] = 35;
    value[28] = 28; value[29] = 27;
    value[30] = 26; value[31] = 22;
    value[32] = 24;

    dfs(0,0);
    cout << Max << endl;
    return 0;
}
void dfs(int level, int sum){
    if(level == MAX){
        if(sum > Max) Max = sum;
        return;
    }
    for(int i = 0; i<4; i++){
        int prev = hourse[i];
        int now = prev;
        int distance = sequence[level];
        switch(now){
            case 5:
            now = 22;
            distance--;
            break;

            case 10:
            now = 31;
            distance--;
            break;

            case 15:
            now = 28;
            distance--;
            break;

            case 25:
            now = 26;
            distance--;
            break;

            default:
            now = now;
        }

        while(distance--){
            now = map[now];
        }

        if(now != 21 && visit[now] == true) continue;

        visit[prev] = false;
        visit[now] = true;
        hourse[i] = now;

        dfs(level+1, sum + value[now]);
        
        hourse[i] = prev;
        visit[prev] = true;
        visit[now] = false;
    }
}

/*
1 2 3 4 1 2 3 4 1 2

1 1 1 1 1 1 1 1 1 1

5 1 2 3 4 5 5 3 2 4

5 5 5 5 5 5 5 5 5 5
*/