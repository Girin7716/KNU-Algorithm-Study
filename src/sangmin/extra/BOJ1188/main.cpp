#include <iostream>

using namespace std;

int M, N;

int gcd(int a, int b){
    if(a%b == 0)
        return b;
    return gcd(b, a%b);
}

int main(){
    cin >> N >> M;
    int sausage = N % M;
    if(sausage == 0){
        cout << 0 << endl;
        return 0;
    }   
    cout << (M - gcd(N,M)) << endl;
    return 0;
}