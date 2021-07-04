#include <iostream>
#include <queue>
using namespace std;

int N,K;
// string num;
string str;
string result = "";

int main(){
    cin >> N >> K;
    cin >> str;
    
    deque <char> dq;

    for(int i = 0; i < str.length(); i++){
        while(K && !dq.empty() && dq.back() < str[i]){
            dq.pop_back();
            K--;
        }
        dq.push_back(str[i]);

        for(int i = 0; i<dq.size(); i++)
            cout << dq[i];
        cout << endl;
    }

    for(int i = 0; i<dq.size() - K; i++)
        cout << dq[i];
    cout << endl;

    return 0;
}


// 오른쪽에는 무조건 K - i(자릿수) 만큼 있어야함

/*
10 4
4177252841

10 4
5555555555

7 3
1231234

5 4
92399

9 4
598658943

12 2
834285349989
99

12 3
834285349989
999

12 4
834285349989
9989

12 5
834285349989
89989

12 6
834285349989

12 7
834285349989

12 8
834285349989

12 9
834285349989

12 10
834285349989


27 3
123456789123456789123456789

27 4
123456789123456789123456789

27 5
123456789123456789123456789



오른쪽에는 반드시 K - 자리수 만큼 있어야하고

왼쪽에는 반드시 N - (K-자리수) 만큼 있어야한다.


*/



//가장 왼쪽부터 N-K의 자리수만큼 나와야하니까 