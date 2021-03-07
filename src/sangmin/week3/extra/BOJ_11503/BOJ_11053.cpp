#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;

int ary[MAX+1];
int d[MAX+1];
int n;

int binary_search(int left, int right, int num){
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(d[mid] < num)
            left = mid+1;
        else
            right = mid;
    }
    return right;
}

int main(){
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> ary[i];

    int front = 0;
    for(int i = 0; i<n; i++){
        if(i == 0) {d[i] = ary[i]; continue;}

        if(d[front] < ary[i])
            d[++front] = ary[i];
        else
            d[binary_search(0,front,ary[i])] = ary[i];
    }
    cout << front + 1 << endl;
    return 0;
}