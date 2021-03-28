# ���� �˻�



## Ǯ�� ���

������ ��Ȯ���� �䱸�ϴ� ������ �ϴ� ����Ž���� dictionary�� ���÷ȴ�.

�׸��� ���,����,���,�ҿ�Ǫ���� ����� ���� ���� ��� �̿� ���� ��� ����� ���� dictionary�� key�� �־��־���.
```python
dict_keys(['jbjp', 'jbjc', 'jbj-', 'jbsp', 'jbsc', 'jbs-', 'jb-p', 'jb-c', 'jb--', 'jfjp', 'jfjc', 'jfj-', 'jfsp', 'jfsc', 'jfs-', 'jf-p', 'jf-c', 'jf--', 'j-jp', 'j-jc', 'j-j-', 'j-sp', 'j-sc', 'j-s-', 'j--p', 'j--c', 'j---', 'pbjp', 'pbjc', 'pbj-', 'pbsp', 'pbsc', 'pbs-', 'pb-p', 'pb-c', 'pb--', 'pfjp', 'pfjc', 'pfj-', 'pfsp', 'pfsc', 'pfs-', 'pf-p', 'pf-c', 'pf--', 'p-jp', 'p-jc', 'p-j-', 'p-sp', 'p-sc', 'p-s-', 'p--p', 'p--c', 'p---', 'cbjp', 'cbjc', 'cbj-', 'cbsp', 'cbsc', 'cbs-', 'cb-p', 'cb-c', 'cb--', 'cfjp', 'cfjc', 'cfj-', 'cfsp', 'cfsc', 'cfs-', 'cf-p', 'cf-c', 'cf--', 'c-jp', 'c-jc', 'c-j-', 'c-sp', 'c-sc', 'c-s-', 'c--p', 'c--c', 'c---', '-bjp', '-bjc', '-bj-', '-bsp', '-bsc', '-bs-', '-b-p', '-b-c', '-b--', '-fjp', '-fjc', '-fj-', '-fsp', '-fsc', '-fs-', '-f-p', '-f-c', '-f--', '--jp', '--jc', '--j-', '--sp', '--sc', '--s-', '---p', '---c', '----'])
```
- �̶�

```python
rem = [['j','p','c','-'],['b','f','-'],['j','s','-'],['p','c','-']]
for x in list(product(*rem)):
    info_dict[''.join(x)] = []
```

�̷������� �ڵ带 ����������, �������� product�� ����ؼ� ������Ʈ�� ���� ����ϴ°� �����ߴ�.

�� ��, �Է����� �־��� infos�� ���� ���� ���·� �ٲٰ� �� 16���� ���� '-'�� ��ġ�� ���ڸ� key�� �־��ְ� ������ value�� �־��־���.

```python
for info in infos:
    rem = info.split()
    string = ''
    for i in range(5):
        if i == 4:
            for k in range(5):
                for j in combinations(range(1,5),k):
                    temp = list(string)
                    for x in j:
                        temp[x-1] = '-'
                    info_dict[''.join(temp)].append(int(rem[i]))
        string+=rem[i][0]
```

�׷��� key�� �ش��ϴ� �������� �����Ǿ��ִµ� �̸� ����Ž������ ������ �ľ��ϱ� ���ؼ� ������������ sorting���־���.

```python
for key in info_dict.keys():
    info_dict[key].sort()
```
����������, �Է����� �־��� query�� ���� ���� ��ó�� ��, �ش� key�� �ش��ϴ� (value ����Ʈ ���� - query���� �־��� ����)�� answer�� �߰����ָ� �ȴ�.

```python
for qry in query:
    temp = qry.split(' and ')
    temp = temp[:3] + temp[3].split()
    score = temp[4]
    string = ''
    for i in range(4):
        string+=temp[i][0]
    answer.append(len(info_dict[string])-bisect_left(info_dict[string],int(score)))
```


## ������

1. dictionary�� Ȱ���ϴ� ���� �ͼ�������.
2. combination, products ������ �ͼ�������.

