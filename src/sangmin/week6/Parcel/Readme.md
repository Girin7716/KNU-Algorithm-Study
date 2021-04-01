1. 코드 설명
<hr>
n1 + n2 + n3 + n4 = w를 변형하여
n1 + n2 = w - n3 - n4를 구하는 문제이다.

일단 n3  , n4를 for문을 통해 배열 1 ~ n까지 두가지 수의 조합을 전부 구한다.

그 n3 + n4가 w보다 크면 제외하고, 만약 w - n3 - n4를 했더니 n1 + n2가 나온다면 YES를 출력하고 종료한다.

만약 n3를 정하고 n4를 n까지 조합했는데 나오지 않는다면, 

이 n3, n4가 n1 + n2가 되어서 ary를 true를 바꾸어준다.

즉 배열의 계속 오른쪽으로 이동하면서 n3, n4를 정해주고 만약 나올 수 있는 값이 없다면 이제 이 n3, n4를 더한값을 n1 + n2로 해주겠다는 뜻이다.

2. 느낀점
<hr>
처음에는 dfs문제인가 싶었지만 dfs로 구현하자니 배열을 더한 값을 저장하기 힘들어서 포기했다. 결국 인터넷의 도움을 받아 해결하였다.