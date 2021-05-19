<meta name='type' content ='트리'>
<meta name='BOJ' content='BOJ1068'>
<meta name='difficulty' content='gold5'>
<meta name='url' content='https://www.acmicpc.net/problem/1068'>
<meat name='date' cotent='2021-05-19'>

1. 코드 설명

<hr>

트리를 배열로 다루는 문제이다.

각 노드에 맞는 숫자의 배열에는 해당 노드의 부모가 들어있는데, 하나의 노드를 삭제하면 삭제한 노드 밑의 노드가 전부 사라지는 구조이다.

개념은 간단하다. 노드의 개수가 많아봤자 50개이기 때문에 단순 for문으로 하나하나 노드의 부모들을 찾아가며 입력받은 노드가 나오게 되면 해당 노드는 삭제시켜 버리면 된다.

문제에서는 리프노드의 개수를 원했기 때문에 리프노드가 아니라고 판단하면 될것이다.

리프노드는 입력받을때 한번도 입력받지 않는 노드가 될것이다.

여기서 주의해야할점은

    1 -> 2 -> 3

이런 트리가 존재한다면 만약 3번을 삭제한다면 2번은 리프 노드가 된다.

이를 처리하기 위해 따로

    ```cpp
    int targetParent = map[target];
    isParent[targetParent] = false;
    for(int i = 0; i<N; i++){
        if(i != target && map[i] == targetParent)
            isParent[targetParent] = true;
    }
    ``` 

이부분을 처리해주었다.

2. 느낀점

<hr>

리프노드를 삭제하거나 중간 노드를 삭제하는 경우를 잘 나눈다면 어렵지 않은 문제였다.