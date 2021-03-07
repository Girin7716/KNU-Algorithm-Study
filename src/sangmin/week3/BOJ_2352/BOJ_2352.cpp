#include <iostream>
#define MAX 40000
using namespace std;

int ary[MAX+1];
int n;

int binary_search(int left, int right, int num){
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(ary[mid] < num)
            left = mid + 1;
        else
            right = mid;
    }
    return right;
}

int main(){
    cin >> n;
    int num;
    int front = 0;
    for(int i = 0; i<n; i++){
        cin >> num;
        if(i == 0){ ary[i] = num; ary[front] = num; continue; }
        if(num > ary[front])
            ary[++front] = num;
        else{ // 이진 탐색 후 넣을 자리 구함
            int index = binary_search(0,front,num);
            ary[index] = num;
        }
    }
    cout << front + 1 << endl;
}




/*
6
4 2 6 3 1 5


6
1 2 4 5 3 6

6
1 3 4 5 6 2

6
1 2 3 4 5 6

6
2 1 4 3 6 5

6
4 2 6 3 1 5
*/