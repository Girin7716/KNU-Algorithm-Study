<meta name='type' content ='findUnion'>
<meta name='BOJ' content='BOJ1967'>
<meta name='difficulty' content='gold5'>
<meta name='url' content='https://www.acmicpc.net/problem/1967'>
<meat name='date' cotent='2021-05-23'>

1. 코드 설명

<hr>

Dijoint set Forest 문제이다.

입력을 받으며 그래프를 만들어 주고, 해당 그래프를 하나의 부모로 전부 묶어 버리면 된다.

중복해서 도시를 방문해도 되고, 경로의 추적이아닌 YES or NO만 출력하면 되는 문제기 때문에 부모 탐색의 시간을 줄이기 위해

```cpp
    int findParent(int start){
        if(parent[start] == start)
            return start;
        return parent[start] = findParent(parent[start]);
    }
```

해당 코드로 깊이가 1인 트리로 만들어 버린다.

그리고 그래프에서 연결되있는 노드들의 부모끼리 서로 연결시켜 주고,

마지막 여행 경로에서 모든 경로에 대해 부모 탐색을 해준다.

만약 서로 다른 부모가 하나라도 나오게 된다면 이는 같은 union이 아니기 때문에 NO를 출력해준다.

만약 전부 다 같다면 YES를 출력해준다.

2. 느낀점

<hr>

Dijoint set Forest문제의 가장 대표적인 문제인것 같다.

주의할점은 모든 노드들의 초기 부모값을 자기 자신으로 지정해주어야한다는 것이다.