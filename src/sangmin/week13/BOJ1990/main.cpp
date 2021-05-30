#include <iostream>
#include <cmath>
#define MAX 100000000
using namespace std;

bool prime[MAX + 1] = {false,};

int main(){
    long long a,b;
    cout.tie(NULL);
    cin >> a >> b;
    for(long long i = 2; i<=sqrt(b);i++){
        if(prime[i] == false){
            prime[i] = false;
            for(long long j = 2; j*i <= 10000000; j++){
                prime[i*j] = true;
            }
        }
    }

    for(long long i = a; i<=b; i++){
        if(i >= 10000000)break;
        if(prime[i] == false){
            string str = to_string(i);
            if(str.size() == 1)
                cout << str << endl;
            else if(str.size() == 2 || str.size() % 2 == 1){
                bool flag = true;
                for(int j = 0; j < str.size()/2 ; j++){
                    if(str[j] != str[str.size()- j - 1]){
                        flag = false;
                        break;
                    }
                }
                if(flag) printf("%s\n",str.c_str());
            }
        }
    }
    cout << -1 << endl;
}

/*
5 550

5 100000000
*/