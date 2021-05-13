#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector <int> crain;
vector <int> container;

int main(){
    int num;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> num;
        crain.push_back(num);
    }
    cin >> M;
    for(int i = 0; i<M; i++){
        cin >> num;
        container.push_back(num);
    }
    sort(crain.begin(), crain.end(), greater<int>());
    sort(container.begin(), container.end(), greater<int>());
    if(container[0] > crain[0]){
        cout << -1 << endl;
        return 0;
    }
    int maxLength = 0;
    while(!container.empty()){
        maxLength++;
        for(int j = 0; j<N; j++){
            for(int k = 0; k < container.size(); k++){
                if(container[k] <= crain[j]){
                    container.erase(container.begin() + k);
                    break;
                }
            }
        }
    }
    cout << maxLength << endl;
    return 0;
}

/*

9 2 1

9 8 7 6 5 4 3 2 1


3                   
9 2 1
9
9 8 7 6 5 4 3 2 1


3                   
6 8 9
5
2 5 2 4 7
*/