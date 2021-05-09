#include <iostream>
using namespace std;

int N;

enum {
    start, err, s1, s2, s3, s4, s5, s6, s7, s8
};

int main(){
    cin >> N;
    while(N--){
        string str;
        cin >> str;
        int stmt = start;
        const char * line = str.c_str();
        for(int i = 0; i<str.length(); i++){
            switch(stmt){
                case start :
                    line[i] == '1' ? stmt=s1 : stmt=s2;
                    break;
                case s1 : // 1
                    line[i] == '1' ? stmt=err : stmt=s3;
                    break;
                case s2 : // 0
                    line[i] == '1' ? stmt=s4 : stmt=err;
                    break;
                case s3 : // 10
                    line[i] == '1' ? stmt=err : stmt=s5;
                    break;
                case s4 : // 01
                    line[i] == '1' ? stmt=s1 : stmt=s2;
                    break;
                case s5 : // 100
                    line[i] == '1' ? stmt=s6 : stmt=s5;
                    break;
                case s6: // 100+1
                    line[i] == '1' ? stmt=s7 : stmt=s2;
                    break;
                case s7 : // 100+1+
                    line[i] == '1' ? stmt=s7 : stmt=s8;
                    break;
                case s8 : // 100+1+10
                    line[i] == '1' ? stmt=start : stmt=s5;
                    break;
            }
            if(stmt == err) break;
        }
        if(err <= stmt && stmt <= s3 || stmt == s8 || stmt == s5) 
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}