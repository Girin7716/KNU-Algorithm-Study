#include <iostream>
#include <vector>
#define MAX 15000
using namespace std;

vector <int> sinker;
int sinkers;
int marbles;
vector <int> marble;
bool weight[32][MAX + 1];
bool result[MAX + 1];
void set_weight(int n1, int index);

int main(){
    cin >> sinkers;
    for(int i = 0; i<sinkers; i++){
        int n;
        cin >> n;
        sinker.push_back(n);
    }


    cin >> marbles;
    for(int i = 0; i<marbles; i++){
        int n;
        cin >> n;
        marble.push_back(n);
    }
    set_weight(sinker[0],1);
    for(int i = 0; i<marbles; i++)
        if(result[marble[i]] == true)
            cout << "Y ";
        else
            cout << "N ";
    return 0;
}

void set_weight(int n1, int index){
    if(index > sinkers){
        return;
    }

    int n2 = sinker[index];
    result[n1] = true; result[n2] = true;
    weight[index][n1] = true;
    int next_n1;
    
    if(n2 > n1)
        next_n1 = n2 - n1;
    else
        next_n1 = n1 - n2;

    if(!weight[index+1][next_n1])
        set_weight(next_n1, index+1);

    next_n1 = n2;
    if(!weight[index+1][next_n1])
        set_weight(next_n1,index+1);


    if(!weight[index+1][n1])
        set_weight(n1,index+1);

    next_n1 = n1 + n2;
    if(!weight[index+1][next_n1])
        set_weight(next_n1,index+1);
}

/*
2
1 4
2
3 2

2
1 4
2
2 3


4
1 4 5 7
8
2 3 10 11 12 13 14 30

3
7 8 9
1
6
*/

