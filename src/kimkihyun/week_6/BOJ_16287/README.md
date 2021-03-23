# Q16287


## Ǯ�� ���

A+B+C+D = w �� �Ǿ���Ѵ�.

ó������ �׷��� �ܼ��ϰ� combinations�� �̿��ؼ� Ǯ������ �翬�ϰ� �ð��ʰ��� �߻��ߴ�.(�ֳ��ϸ� 5000C4�̱� ����..)(�� 4�� for��)

�� ���� �����Ѱ� dp������ ��� Ǯ����ϴ��� ���� �����ʾƼ� ���ͳݿ� �˻��ؼ� Ǯ�̹���� �˾ƿԴ�.

A+B = w-C-D�� �����Ͽ� 4�� for�� -> 2�� for������ �ٲ���Ѵ�.

������ �Ʒ��� ����.
```python
def check():
    for i in range(n):
        for j in range(i + 1, n):
            if parcel[i] + parcel[j] < w and dp[w - parcel[i] - parcel[j]]:
                return True
        for j in range(i):
            if parcel[i] + parcel[j] < w:
                dp[parcel[i] + parcel[j]] = True

    return False
```
- parcel�� �տ������� �˻縦�Ѵ�.
- i��,i���� ū ������ ���� ���ϰ�, `dp[w-parcel[i]-parcel[j]`�� True�̸� �̹� i���� ���� �ε����� ������ ���� �־��ٴ� �ǹ��̹Ƿ� 'yes' ���
- i��°�� ������ �������� 2���� �̾Ƴ��鼭 �� ������ ���� w ���� �۴ٸ� �ش� ������ dp, �� `dp[parcel[i]+parcel[j]] < w`�̸� True�� �ٲ��ش�.
