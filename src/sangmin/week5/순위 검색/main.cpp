#include <string>
#include <vector>
#include <cstring>
#define MAX 100
using namespace std;

vector <int> list[3][2][2][2];

vector<int> solution(vector<string> info, vector<string> query) {
  
    vector <int> answer;
    char temp[MAX];
    for(int i = 0; i < info.size(); i++){
        strcpy(temp, info[i].c_str());
        char * ptr = strtok(temp, " ");
        int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
        while(ptr!=NULL){
            if(strcmp(ptr,"cpp") == 0) n1 = 1;
            else if(strcmp(ptr,"python") == 0) n1 = 2;

            if(strcmp(ptr,"backend") == 0) n2 = 1;

            if(strcmp(ptr,"senior") == 0) n3 = 1;

            if(strcmp(ptr,"pizza") == 0){
                n4 = 1;
                break;
            } 
            else if(strcmp(ptr,"chicken") == 0) break;
            ptr = strtok(NULL," ");
        }
            ptr = strtok(NULL," ");
            list[n1][n2][n3][n4].push_back(atoi(ptr));
    }

    for(int i = 0; i < query.size(); i++){
        vector <char*> arys;
        int count = 0;
        strcpy(temp, query[i].c_str());
        char * ptr = strtok(temp," ");
        while(ptr != NULL){
            if(strcmp(ptr,"and") != 0)
                arys.push_back(ptr);
            ptr = strtok(NULL," ");
        }
        int a1,a2,b1,b2,c1,c2,d1,d2;
        
        if(strcmp(arys[0],"cpp") == 0) a1 = a2 = 1;
        else if(strcmp(arys[0],"java") == 0) a1 = a2 = 0;
        else if(strcmp(arys[0],"python") == 0) {a1 = a2 = 2;}
        else if(strcmp(arys[0],"-") == 0) {a1 = 0; a2 = 2;}
        
        if(strcmp(arys[1],"frontend") == 0) b1 = b2 = 0;
        else if(strcmp(arys[1],"backend") == 0) b1 = b2 = 1;
        else if(strcmp(arys[1],"-") == 0) {b1 = 0; b2 = 1;}
        
        if(strcmp(arys[2],"junior") == 0) c1 = c2 = 0;
        else if(strcmp(arys[2],"senior") == 0) c1 = c2 = 1;
        else if(strcmp(arys[2],"-") == 0) {c1 = 0; c2 = 1;}

        if(strcmp(arys[3],"chicken") == 0) d1 = d2 = 0;
        else if(strcmp(arys[3],"pizza") == 0) d1 = d2 = 1;
        else if(strcmp(arys[3],"-") == 0) {d1 = 0; d2 = 1;}

        for(int j = a1; j <= a2; j++)
            for(int k = b1; k <= b2; k++)
                for(int l = c1; l <= c2; l++)
                    for(int m = d1; m <= d2; m++){
                        int n = atoi(arys[4]);
                        for(int o = 0; o < list[j][k][l][m].size(); o++)
                            if(n <= list[j][k][l][m][o]){
                                count++;
                            }
                    }
        answer.push_back(count);            
    }
    return answer;
}

/*
   info.push_back("java backend junior pizza 150");
    info.push_back("python frontend senior chicken 210");
    info.push_back("python frontend senior chicken 150");
    info.push_back("cpp backend senior pizza 260");
    info.push_back("java backend junior chicken 80");
    info.push_back("python backend senior chicken 50");

    query.push_back("java and backend and junior and pizza 100");
    query.push_back("python and frontend and senior and chicken 200");
    query.push_back("cpp and - and senior and pizza 250");
    query.push_back("- and backend and senior and - 150");
    query.push_back("- and - and - and chicken 100");
    query.push_back("- and - and - and - 150");

*/