#include <iostream>
#include <cmath>
#define MAX 5000000
using namespace std;

string N;
int M;
bool brokenbutton[10];

int main(){
    int num;
    cin >> N >> M;
    for(int i = 0; i<M; i++){
        cin >> num;
        brokenbutton[num] = true;
    }
    
    int moreMin = MAX+1; // 큰것중 가장 작은값
    int lessMax = MAX+1; // 작은것중 가장 큰 값

    for(int i = 0; i<=5000000; i++){

        bool ok = true;
        string temp = to_string(i);

        for(int j = 0; j<temp.size(); j++){
            if(brokenbutton[temp[j] - '0']){
                ok = false;
                break;
            }
        }

        if(ok){
            if(i < atoi(N.c_str())){
                lessMax = i;
            }else{
                moreMin = i;
                i = MAX+1;
            }
        }
    }
    int normal = atoi(N.c_str()) - 100;
    normal = abs(normal);

    if(moreMin != MAX+1){
        int buttonClick = to_string(moreMin).size();
        moreMin = moreMin - atoi(N.c_str()) + buttonClick;
    }

    
    if(lessMax != MAX+1){
        int buttonClick = to_string(lessMax).size();
        lessMax = atoi(N.c_str()) - lessMax + buttonClick;
    }

    int min = MAX;
    if(normal < min) min = normal;
    if(lessMax < min) min = lessMax;
    if(moreMin < min) min = moreMin;
  
    cout << min << endl;
    return 0;
}

/*
4
6
0 1 2 3 4 5

50000
6
0 2 3 6 7 9

100
5
0 1 2 3 4

500000
8
0 2 3 4 6 7 8 9

500000
10
0 1 2 3 4 5 6 7 8 9

500000
9
0 2 3 4 5 6 7 8 9

1234
1
1

5457
3
6 7 8

500000
8
0 2 3 4 6 7 8 9
*/