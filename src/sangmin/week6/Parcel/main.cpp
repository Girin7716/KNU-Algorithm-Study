#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 800000
using namespace std;

int w,n;
vector <int> ary;
bool weight[MAX];

int main(){
    cin >> w >> n;
    for(int i = 0; i<n; i++){
        int num;
        cin >> num;
        ary.push_back(num);
    }
    for(int i = 0; i<n; i++){
        for(int j = i + 1; j<n; j++){
            if(ary[i] + ary[j] >= w) continue;
            if(weight[w - ary[i] - ary[j]])
            {
                cout << "YES" << endl;
                return 0;
            }
        }
        for(int j = 0; j<i; j++)
            if(ary[i] + ary[j] < w)
                weight[ary[i] + ary[j]] = true;
    }
    cout << "NO" << endl;
    return 0;
}

/*
10 6
5 10 7 3 2 1

21 7
10 1 4 6 2 8 5
*/