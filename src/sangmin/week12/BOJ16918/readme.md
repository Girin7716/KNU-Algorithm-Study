<meta name='type' content ='반복'>
<meta name='BOJ' content='BOJ16918'>
<meta name='difficulty' content='silver1'>
<meta name='url' content='https://www.acmicpc.net/problem/16918'>
<meat name='date' cotent='2021-05-23'>

1. 코드 설명

<hr>

시간에 따른 반복 배열을 구현하는 문제다.

    0초 (초기)
    1초 (초기)
    2초 (없는 위치 설치)
    3초 (0초 설치 터짐)
    4초 (없는 위치 설치)
    5초 (2초 설치 터짐)
    6초 (없는 위치 설치)
    7초 (4초 설치 터짐)
    .....

0 ~ 1초를 제외하고 2초 부터는 짝수일때 없는 범위에 폭탄을 설치하고 홀수일때 현재 시간 - 3초때의 폭탄이 터진다.

따라서 time이 2초일때부터 원하는 N초가 될때까지 해당 작업을 반복하며 map을 체워준다.

bombs 배열에 폭탄이 터지는 시간을 저장해주어 해당 시간일때 폭탄을 터트려 map을 바꾸어준다.

```cpp
    if(time%2 == 1){ // 터짐
        for(int i = 1; i<=R; i++){
            for(int j = 1; j<=C; j++){
                if(bombs[i][j] == time){
                    map[i][j] = '.';
                    bombs[i][j] = 0;
                    for(int dir = 0; dir<4; dir++){
                        map[i+dy[dir]][j+dx[dir]] = '.';
                    }
                }
            }
        }
    }
```

홀수일때 만약 bomb배열 안의 시간과 현재 시간이 같다면 해당 폭탄은 터지는것이기 때문에 상하좌우와 해당 배열 값을 빈칸으로 변경해준다.

```cpp
    for(int i = 1; i<=R; i++){
        for(int j = 1; j<=C; j++){
            if(map[i][j] == '.'){
                bombs[i][j] = time+3;
                map[i][j] = 'O';
            }
        }
    }
```

짝수일때는 map을 돌면서 bombs 배열의 시간을 지정해주고 빈칸을 폭탄으로 채워넣는다.

2. 느낀점

<hr>

구현은 어렵지 않았는데

계속해서 틀렸다고 나오길래 출력 문제인가 싶어 

    cout.tie(NULL);

코드를 작성해주었더니 바로 통과되었다.

습관을 들여야겠다.