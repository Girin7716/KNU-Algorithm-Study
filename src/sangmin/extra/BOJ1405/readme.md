<meta name='type' content ='DFS'>
<meta name='BOJ' content='BOJ1405'>
<meta name='difficulty' content='gold5'>
<meta name='url' content='https://www.acmicpc.net/problem/1405'>
<meat name='date' cotent='2021-05-11'>

1. 코드 설명

<hr>

간단한 dfs문제이다. 끝까지 갔다가 돌아오면서 visit 한곳과 visit하지 않은곳을 check해준다.

조건은 만약 끝까지 간다면 그 확률을 단순히 더해주기만 하면된다.

그러기 위해서 dfs의 구조를 현재 x,y 현재 단계(level), 이때까지 구한 확률(p)를 인자로 받기로 하였다.
```c++
    void dfs(int x, int y, int level, double p){
    if(map[y][x]) // visit
        return;
    if(level == n) {// 성공
        result+=p;
        return;
    }
    map[y][x] = true;
    for(int dir = 0; dir < 4; dir++){
       int nx = x + dx[dir];
       int ny = y + dy[dir];
       if(nx<=START+n && nx>=START-n && ny<=START+n && ny>=START-n){
           dfs(nx,ny,level+1, p * (weight[dir]/100));
       }
    }
    map[y][x] = false;
    }
```
dfs 하면서 가는 도중 현재 x,y가 방문한 map이라면 그대로 돌아가준다.

이 때, 절대 visit을 해제해주면 안된다. 이 map은 이때까지 오면서 방문한 map이기 때문이다.

반대로 만약 현재 단계가 내가 이동할수있는 최대 범위라면 이때까지 중복 없이 성공적으로 온것이기 때문에 확률을 더해준다.

또한 한 지점에서 dfs가 끝나면 그 지점의 visit은 풀어줘야한다.

2. 느낀점

<hr>

문제는 간단했지만.

출력 형식이나 맞지않아 틀리고 처음에 29 x 29개의 map을 fill을 사용해서 false로 바꾸니 계속해서 n이 초기화 되어 틀렸다.

그 외에는 딱 현재 난이도에 어울리는 문제라고 생각한다.