#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map <string,int> courses;
vector <string> tokens [21][11];

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
        vector <string> answer;
     int max = course[course.size()-1];

    for(int i = 0; i < orders.size(); i++){
        for(int j = 0; j<orders[i].length(); j++){
            string t = "";
            t += orders[i].at(j);
            tokens[i][1].push_back(t);
        }
        sort(tokens[i][1].begin(), tokens[i][1].end());
    }


    for(int n = 2; n <= max; n++){
        int size = n;
        for(int i = 0; i < orders.size(); i++){
            if(orders[i].length() >= size){
                for(int k = 0; k < tokens[i][size-1].size(); k++){
                    string token = tokens[i][size-1][k];
                    for(int j = 1; j < tokens[i][1].size(); j++){
                        string plusToken = tokens[i][1][j];
                        if(token.c_str()[size-2]< plusToken.c_str()[0]){
                            string nextToken = token + plusToken;
                            tokens[i][size].push_back(nextToken);
                            if(courses.find(nextToken) == courses.end())
                                courses.insert(make_pair(nextToken,1));
                            else
                                courses[nextToken]++;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i<course.size(); i++){
        int size = course[i];
        int max = 0;
        for(auto it = courses.begin(); it != courses.end(); it++){
            if(it->first.length() == size){
                if(it->second > max)
                    max = it->second;
            }
        }
        for(auto it = courses.begin(); it != courses.end(); it++){
            if(it->first.length() == size && it->second == max  && it->second != 1){
                answer.push_back(it->first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    for(int i = 0; i<answer.size(); i++){
        cout << answer[i] << endl;
    }
    return answer;
}