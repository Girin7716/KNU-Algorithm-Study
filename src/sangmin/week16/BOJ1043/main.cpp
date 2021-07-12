#include <iostream>
#include <vector>
using namespace std;

vector <int> parties[50];

int N, M; //사람과 파티
int truth;// 진실을 아는 사람의 수

int parent[51]; // 인원
bool truthPeople[51];

//오는 사람과 수
int findParent(int i){
    if(parent[i] == i) return i;
    return parent[i] = findParent(parent[i]);
}

void setUnion(int n1, int n2){
    parent[n1] = n2;
}

int main(){
    int input;
    int num;

    cin >> N >> M;
    cin >> truth;

    for(int i = 1; i<=N; i++) parent[i] = i;

    for(int i = 0; i<truth; i++){
        cin >> input;
        truthPeople[input] = true;
    }



    for(int i = 0; i < M; i++){
        cin >> num;
        for(int j = 0; j<num; j++){
            cin >> input;
            parties[i].push_back(input);
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < parties[i].size() - 1; j++){
            int p1 = findParent(parties[i][j]);
            int p2 = findParent(parties[i][j+1]);
            if(p1 != p2) setUnion(p1, p2);
        }
    }

    for(int i = 1; i<=N; i++)
        if(truthPeople[i])
            truthPeople[findParent(i)] = true;

    int result = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < parties[i].size(); j++){
            if(truthPeople[findParent(parties[i][j])]){
                result++;
                break;
            }
        }
    }
    cout << M - result << endl;

    return 0;
}

/*
4 3
0
2 1 2
1 3
3 2 3 4

3

4 1
1 1
4 1 2 3 4

0

4 1
0
4 1 2 3 4

1

4 5
1 1
1 1
1 2
1 3
1 4
2 4 1

2
*/