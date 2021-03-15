#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define Full_spectrum pair <double, double>

Full_spectrum times[2000];

int solution(vector<string> lines) {
    char hours[3];
    char minutes[3];
    char secs[7];
    char add_secs[8];
    int answer = 0;
    for(int i = 0; i<lines.size(); i++){
        strcpy(add_secs,"       ");
        lines[i].copy(hours,2,11);
        double hour = stod(hours);

        lines[i].copy(minutes,2,14);
        double minute = stod(minutes);

        lines[i].copy(secs,6,17);
        double sec = stod(secs);

        lines[i].copy(add_secs,6,24);
        double add_sec = stod(add_secs);

        sec += (minute * 60.0);
        sec += (hour * 3600.0);
        double start_sec = sec - add_sec + 0.001;
        times[i] = make_pair(start_sec, sec);
        cout << times[i].first << ", " << times[i].second << endl;
    }
    int sum = 0;
    for(int i = 0; i<lines.size(); i++){
        double start = times[i].first;
        sum = 0;
            for(int j = 0; j<lines.size(); j++){
                if(start <= times[j].first && times[j].first <= start + 1){
                    sum++;
                    continue;
                }
                if(start <= times[j].first && times[j].second <= start + 1){
                    sum++;
                    continue;
                }
                if(start <= times[j].second && times[j].second <= start + 1){
                    sum++;
                    continue;
                }
                if(times[j].first <= start && start + 1 <= times[j].second){
                    sum++;
                    continue;
                }
            }
            if(sum > answer)
                answer = sum;

                start = times[i].second;
                sum = 0;
                    for(int j = 0; j<lines.size(); j++){
                if(start <= times[j].first && times[j].first < start + 1){
                    sum++;
                    continue;
                }
                if(start <= times[j].first && times[j].second < start + 1){
                    sum++;
                    continue;
                }
                if(start <= times[j].second && times[j].second < start + 1){
                    sum++;
                    continue;
                }
                if(times[j].first <= start && start + 1 < times[j].second){
                    sum++;
                    continue;
                }
            }
            if(sum > answer)
                answer = sum;
    }
    cout << answer << endl;
    return answer;
}
