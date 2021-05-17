#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector < string > maps[101];

int N, M;

int main(){
    int zero;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i<N; i++){
        string temp;
        cin >> temp;
        maps[temp.size()].push_back(temp);
    }

    cin >> M >> zero;

    for(int i = 0; i<M; i++){
        int result = 1;
        bool flag = false;
        char temp[10001];
        cin.clear();
        cin.getline(temp,10001);

        char * ptr = strtok(temp, " ");

        while(ptr != NULL){
            int count = 0;
            if(strlen(ptr) <= 3){
                for(int i = 0; i<maps[strlen(ptr)].size(); i++){
                    if(maps[strlen(ptr)][i] == ptr) {
                        count++;
                        break;
                    }
                }
            }
            else{
                for(int i = 0; i < maps[strlen(ptr)].size(); i++){
                    int nums[58] = {0};
                    for(int i = 1; i<strlen(ptr)-1; i++)
                        nums[ptr[i]-'A']++;
                    int k;
                    if(maps[strlen(ptr)][i].front() == ptr[0] && maps[strlen(ptr)][i].back() == ptr[strlen(ptr)-1]){
                        for(k = 1; k < strlen(ptr)-1; k++){
                            nums[maps[strlen(ptr)][i][k]-'A']--;
                            if(nums[maps[strlen(ptr)][i][k]-'A'] < 0)
                                break;
                        }

                        if(k == strlen(ptr)-1)
                            count++;
                    }
                }
            }
            ptr = strtok(NULL, " ");
            if(count != 0){
                result *= count;
                flag = true;
            }
        }
        if(flag == false)
            cout << "0" << endl;
        else
            cout << result << endl;
    }
    return 0;
}


/*
3
ababa
aabba
abcaa
2
ababa
abbaa

*/