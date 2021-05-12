#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> ary;
int N,M;

int binarySearch(int left, int right, int value){
   if(left > right) return right;
   int middle = (left + right) / 2;
   if (ary[middle] == value) return middle;
		else if (ary[middle] < value)
			return binarySearch(middle+1, right, value);
		else
			return binarySearch(left, middle-1, value);
}

int main(){
    int num;
    int result = 0;
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        cin >> num;
        ary.push_back(num);
    }
    sort(ary.begin(), ary.end());
    
    int zeroStart = binarySearch(0,N-1,0);
    
    for(int i = 0; i<=zeroStart; i+=M)
        result += ary[i]*-1 * 2;

    for(int i = N-1; i>zeroStart; i-=M)
        result += ary[i]*2;

    if(ary[0]*-1 > ary[N-1])
        result -= ary[0]*-1;
    else result -= ary[N-1];

    cout << result << endl;
}


/*
7 2
-37 2 -6 -39 -29 11 -28

7 2
-39 -37 -29 -28 -6 2 11 

7 3
-39 -37 -29 -28 -6 2 11 
*/