# ģ�� ��Ʈ��ũ

## Ǯ�� ���

ó������ BFS�� ���� �ذ��ҷ��� ������ �ð��ʰ��� �߻��ߴ�.

�� ��, disjoint set���� ������ �ذ��ϰ��� �߰�, �� ��¸��� parent�� �������� answer�� ã������������ �� ���� �ð��ʰ�.

��ųʸ��� ����Ͽ� disjoint set�� �����ߴ�. �̶�, union_parent���� �θ��� ������ ������ b�� �θ� �ǵ��� �Ͽ���.

�׷��� �־��� input���� ģ�� ��Ʈ��ũ�� ���� ���� ������ �� �θ�� ������ ���̰�, �� �θ��� number�� ã���� �ȴ�(�׷��Ƿ� number ��ųʸ��� �����ؼ� union�Ҷ����� �ش� ģ�� ��Ʈ��ũ�� ���ڵ��� ���ߴ�.)
```python
def union_parent(parent,a,b):
    a = find_parent(parent,a)
    b = find_parent(parent,b)

    if a!=b:
        parent[b] = a
        number[a] += number[b]
```

## ������

��ųʸ��� Ȱ���ϴ� ���� disjoint set�� Ȱ����� �ͼ�������.

</details>