# �޴� ������

## Ǯ�� ���

�Է����� �־����� orders�� ���� ������ ������ ���ش�(�������ϱ� �� �ʿ� ���µ�)

�� ���� �Է����� �־��� course�� ���Ҹ�ŭ orders�� ���ҿ� combination�� ���Ѵ�. �̶�, order�� ���ĺ������� ��ġ�Ǿ���Ѵ�. �׸���, �ش� combination�� key�� ������ ��ųʸ��� �����ؼ� ������ count�Ѵ�.
```python
order = ''.join(list(sorted(list(order))))
rems = list(combinations(order,c))
for rem in rems:
    comb[rem] = comb.get(rem,0) + 1
```

�� ��, comb�� ���� �� ��ųʸ��� continue, �ƴ� ��� max_value�� Ȯ���ؼ� 1�ϰ�� continue, �� ���� ���� max_value�� ���� ���� ������ key�� answer�� �߰����ָ� �ȴ�.

</details>