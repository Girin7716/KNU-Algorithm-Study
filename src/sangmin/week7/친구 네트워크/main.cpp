#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define MAX 200000
int T;
int N;
int parent[MAX];
int value[MAX];

int findParent(int curIdx);
void setUnion(int idx1, int idx2);

int main(){
    cin.tie(0);
    cin >> T;
    for(int i = 0; i<T; i++){
        cin >> N;
        int idx = 0;
        map <string, int> indexMatching;
        for(int j = 0 ; j<N*2; j++){
            parent[j] = j;
            value[j] = 1;
        }
        for(int j = 0; j<N; j++){
            string s1, s2;
            cin >> s1 >> s2;
            if(indexMatching.find(s1) != indexMatching.end()){}
            else
                indexMatching.insert(make_pair(s1,idx++));

            if(indexMatching.find(s2) != indexMatching.end()){}
            else
                indexMatching.insert(make_pair(s2,idx++));

            int p1 = findParent(indexMatching[s1]);
            int p2 = findParent(indexMatching[s2]);
            if(p1 != p2)
                setUnion(p1,p2);
            cout << value[p1] << "\n";
        }
    }
}

int findParent(int curIdx){
    if(parent[curIdx] == curIdx) {return curIdx;}
    return parent[curIdx] = findParent(parent[curIdx]);
}

void setUnion(int idx1, int idx2){
    value[idx1] = value[idx1] + value[idx2];
    parent[idx2] = parent[idx1];
}

/*
2
3
Fred Barney
Barney Betty
Betty Wilma
3
Fred Barney
Betty Wilma
Barney Betty

*/