# 친구 네트워크

## 풀이 방법

처음에는 BFS를 통해 해결할려고 했으나 시간초과가 발생했다.

그 후, disjoint set으로 문제를 해결하고자 했고, 매 출력마다 parent를 뒤져가며 answer을 찾을려고했지만 이 역시 시간초과.

딕셔너리를 사용하여 disjoint set을 구성했다. 이때, union_parent에서 부모의 기준은 무조건 b가 부모가 되도록 하였다.

그러면 주어진 input에서 친구 네트워크를 구할 때에 무조건 한 부모로 동일할 것이고, 그 부모의 number를 찾으면 된다(그러므로 number 딕셔너리도 정의해서 union할때마다 해당 친구 네트워크의 숫자들을 더했다.)
```python
def union_parent(parent,a,b):
    a = find_parent(parent,a)
    b = find_parent(parent,b)

    if a!=b:
        parent[b] = a
        number[a] += number[b]
```

## 느낀점

딕셔너리의 활용하는 법과 disjoint set의 활용법에 익숙해지자.

</details>