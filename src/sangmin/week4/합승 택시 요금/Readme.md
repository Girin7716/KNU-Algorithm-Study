1. 코드 설명
<hr>
다익스트라는 단순히 저번에 했던 알고리즘 문제 중 우선순위 큐를 이용한 다익스트라 문제가 있기 때문에 설명하지 않겠다.

경우를 크게 두가지로 나눌 수 있다.
1. 처음부터 같이 타고 가지 않는 경우
2. 중간 어느 지점까지 같이 타고 가다가 나누어서 가는 경우

1번의 경우에는 상당히 쉽다.
단순히 시작점으로부터 다익스트라를 실행해서 s->a, s->b를 더해주면 요금이 나온다.

문제는 2번인데,
결국 시작점에서 출발하는건 똑같지만 어느 최종적으로 어느 node에서 node->a, node->b가 될 것이다.
그렇다면 어느 노드를 어떻게 거쳐서 가기보다는 어느 노드까지의 최단 거리가 필요했다.
결국 시작점으로부터 다익스트라를 실행해야 하는데 그 다음에는 그 노드에서 a와 b로 가야했다.

이는 모든 노드에 대해서 다익스트라를 실행하기보다는 a와 b에서 다익스트라를 실행한다.
그렇게되면 a와 b에서의 모든 노드에 대해 최단거리가 나오게 된다.

그 후에는 매우 쉽다.
s -> node, node -> a, node -> b 를 모든 node에 대해 실시해주고 이 3가지의 값을 전부 더한 것 중 최소가 결국 택시 요금의 최소 요금이 될 것이다.

2. 느낀점
<hr>
다행히 정확도 면에서는 쉽게 통과를 했다. 우선순위큐를 이용하니까 속도도 매우 빨랐지만 문제는 효율성 검토에 있었다.
계속 몇몇 테스트 케이스가 통과하지 못했다. 문제는 구현의 문제가 아닌 초기화의 문제였다. 이때까지 생각없이 dist를  MAX까지 전부해주었기 때문에 시간, 공간적인 면에서 오래 걸렸던 것 같다. fill을 노드까지 해주는것으로 문제를 해결했다.
