#include <iostream>
#include <stack>
using namespace std;
#define MAX 100000000

stack < pair<int, int> > maxTower; // value, idx 저장
int N;

int main(){
    int num;
    cin >> N;
    maxTower.push(make_pair(MAX,0));
    for(int i = 0; i<N; i++){
        scanf("%d",&num);
        int value = maxTower.top().first; // 높이
        int idx = maxTower.top().second; // 전의 idx
        
        //현재가 이전보다 클 경우 이전은 전부 무시된다. 현재 크기보다 클때까지 pop 해준다.
        if(num > value){
            while(!maxTower.empty() && maxTower.top().first < num)
                maxTower.pop();
            printf("%d ", maxTower.top().second);
            maxTower.push(make_pair(num,i+1));
        }
        else{ // 현재가 이전보다 작을 경우 이전의 idx를 받아 사용하고 넣어준다
            printf("%d ", maxTower.top().second);
            maxTower.push(make_pair(num,i+1));
        }
    }
    return 0;
}