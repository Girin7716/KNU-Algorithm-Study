#include <iostream>
#include <cmath>
#define MAX 100000
using namespace std;


int main(){
    int N;
    long long int result1, result2;
    long long int ary[MAX+1];
    long long int sum;
    long long int min = 0x1ffffffffffff;

    cin >> N;
    int left = 0, right = N-1;

    for(int i = 0; i<N; i++)
        cin >> ary[i];

    while(left < right){
        sum = ary[left] + ary[right];

        if(abs(sum) < min){
            min = abs(sum);
            result1 = ary[left];
            result2 = ary[right];
        }

        if(sum > 0) right--;
        else left++;
    }
    cout << result1 << " " << result2 << endl;
    return 0;
}


/*

5
-99 -2 -1 4 98

*/