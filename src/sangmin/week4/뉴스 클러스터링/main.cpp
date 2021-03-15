#include <iostream>
#include <string>
#include <cstring>
#define MAX 1000
using namespace std;

//string str1;
//string str2;

char str1_token[MAX][3];
char str2_token[MAX][3];
char union_token[MAX + MAX][3];
char forest_token[MAX][3];

int solution(string str1, string str2) {
    int token1 = 0;
    int token2 = 0;
    str1[0] = toupper(str1[0]);
    str2[0] = toupper(str2[0]);
    for(int i = 1; i<str1.size(); i++){
        str1[i] = toupper(str1[i]);

        if(str1[i-1] > 90 || str1[i-1] < 65 || str1[i] > 90 || str1[i] < 65)
            continue;

        str1_token[token1][0] = str1[i-1];
        str1_token[token1][1] = str1[i];
        str1_token[token1][2] = '\0';
        token1++;
    }
    for(int i = 1; i<str2.size(); i++){
        str2[i] = toupper(str2[i]);

        if(str2[i-1] > 90 || str2[i-1] < 65 || str2[i] > 90 || str2[i] < 65)
            continue;
        
        str2_token[token2][0] = str2[i-1];
        str2_token[token2][1] = str2[i];
        str2_token[token2][2] = '\0';
        token2++;
    }
    int token3 = 0;
    for(int i = 0; i<token1; i++){
        for(int j = 0; j<token2; j++){
            if(strcmp(str1_token[i], str2_token[j]) == 0){
                cout << str2_token[j] << endl;
                strcpy(str2_token[j],"");
                token3++;
                break;
            }
        }
    }
    double result = (double)token3/ ((double)token1 + (double)token2 - (double)token3);
    if(token1 == 0 && token2 == 0)
        result = 1;
    int answer = result * 65536;
    return answer;
}