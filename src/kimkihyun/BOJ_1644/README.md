# �Ҽ��� ������

## Ǯ�̹��

1. �Ҽ��� �������� ���ϱ� ���ؼ��� �Ҽ��� ����� ����Ʈ�� �ʿ��ϰ� �����ߴ�. �׸��Ͽ� �Ʒ��� ���� `�����佺�׳׽��� ü` �˰����� ����Ͽ� �Ҽ� ����Ʈ�� ���ߴ�.
    ```python
    def prime_list(n):
        sieve = [True] * n

        m = int(n**0.5)
        for i in range(2,m+1):
            if sieve[i] == True:
                for j in range(i+i,n,i):
                    sieve[j] = False
        return [i for i in range(2,n) if sieve[i] == True]
        
    prime = prime_list(N+1)
    ```

2. ������ �Ҽ� ����Ʈ�� `prime`�� �������� `��������` �˰����� ����Ͽ� �������� ���ϰ��� �����ߴ�.
    - start index�� end index�� ���� ó������ prime ����Ʈ�� �˻��Ѵ�.
    - �̶�, sum(prime[start:end+1])�� ���� �־��� �Է��� n ���� ���� ��� sum(prime[start:end+1]) ���� �÷��� �ϹǷ� end += 1
    - sum(prime[start:end+1])�� ���� �־��� �Է��� n ���� Ŭ ��� sum(prime[start:end+1]) ���� �ٿ��� �ϹǷ� start += 1
    - sum(prime[start:end+1])�� n�� ���� ��� start:end+1 �̻��� ���������� ���̻� ���� �����Ƿ� start += 1 �ϰ� result += 1�� ���ش�.
  - �� ������ ���� �� result�� ����ϸ� �ȴ�.

## �ƽ��� ��
�ٸ� ������� ����� �ð��� ���� ������ 340ms ������ ������ �ذ��� ����� �ִ�. �� ȿ�������� �ڵ带 ������ �ʿ䰡 �־�δ�.

## ����
![1644](./1644.JPG)