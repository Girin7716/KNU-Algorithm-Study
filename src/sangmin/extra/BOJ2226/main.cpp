#include <iostream>
#define MAX 1000
using namespace std;

int N;

int main(){
    cin >> N;
    unsigned long long result = 1;

    if(N == 1){
        cout << 0 << endl;
        return 0;
    }

    for(int i = 3; i <= N; i++){
        if(i % 2) // 홀수
            result += (result - 1);
        else // 짝
            result += (result + 1);
    }

    cout << result << endl;
    return 0;
}

/*

1은 01로
0은 10으로

1     -> 01        -> 10(01)         -> 0110(1001)  -> 10010110(01101001)  -> 0110100110010110(1001011001101001) -> 10010110011010010110100110010110(01101001100101101001011001101001)
0 + 0 -> 1 + 0 = 1 ->  1 + 1 - 1 = 1 ->  2 + 1 = 3  -> 3 + 3 - 1= 5        -> 6 + 5 = 11                         -> 11 + 11 - 1 = 21
1     -> 2         ->  3             ->  4          -> 5                   -> 6                                  -> 7


-> 8
-> 22 + 21
-> 01101001100101101001011001101001100101100110100101101001100101101001011001101001011010011001011001101001100101101001011001101001


-> 9
-> 43 + 42
*/

/*

N = int(input())
result = 1
if N==1:
    print(0)
elif N==2:
    print(1)
else:
    for i in range(3,N+1):
        if(i%2) :
            result =result + (result-1)
        else :
            result= result + (result+1)
    print(result)
    
*/