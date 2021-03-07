1. 코드 설명
<hr>
kruskal 알고리즘을 사용해 minimum spanning tree, maximum spanning tree를 찾는 문제이다.
kruskal 알고리즘을 사용하기 위해선 먼저 간선이 value에 따라 sorting되어 있어야한다.
하지만 input value는 0, 1밖에 없기 때문에 간선의 갯수 m만큼 입력 받되, 0(오르막길)은 front를 이용하여 앞에, 1(내리막길)은 rear를 이용하여 뒤에서 부터 입력받아 준다.

이렇게 되면 sorting은 nodes배열 안에 해결이 된다.

그 후에는 kruskal 알고리즘을 실행하는데, kruskal 알고리즘과 union find를 하기위해 각 노드의 부모를 나타낸 p배열을 이용하여 union을 찾아주고 만약 그 union 끼리의 부모가 같지 않으면 합쳐준다.

그래프는 결국 tree로 나타 낼 수 있기 때문에 오르막길에서 내리막길 (0 -> 1, nodes배열 0 -> m) 순으로 진행하다보면
cycle을 만들지않는 오르막길이 전부 선택 될 것이고 오르막길이 끝난다면 내리막길을 선택해준다.

minimum spanning tree는 maximum spanning tree의 역순으로 진행해준다.

2. 느낀점
<hr>
kruskal 알고리즘은 쉽게 해결했으나 부모를 설정하는 부분에 있어 계속 오류가 났다. 단순한 계산 실수였는데 그것도 모르고 계속해서 제출하여 괜히 오답률을 늘렸다. 다음부터는 신중하게 제출해야 할 것 같다.
