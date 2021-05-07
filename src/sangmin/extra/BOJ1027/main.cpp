#include <iostream>
#include <vector>
using namespace std;

vector <long long> ary;
int value[50];
int N;

int main(){
    long long num;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> num;
        ary.push_back(num);
    }
       
    int max = 0;
    for(int i = 0; i < N - 1; i++){
        long long dot1 = ary[i]; // 기준점
        for(int j = i + 1; j<N; j++){
            long long dot2 = ary[j];
            double result = (double)(dot2 - dot1)/(double)(j - i);

            for(int k = i + 1; k < N; k++){
                if(j == k){
                    value[i]++;
                    value[j]++;
                    break;
                }
                long long dot3 = ary[k];
                double result2 = (double)(dot3 - dot1)/(double)(k - i);
                if(result <= result2) break;
            }
        }
    }
    for(int i = 0; i < N; i++)
        if(max < value[i]) max = value[i];
    cout << max << endl;
    return 0;
}