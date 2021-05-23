시간초과났었는데 Scanner를 BufferedReader로 바꾸니 해결됨<br>
<strong>앞으로 Scanner말고 BufferedReader 쓰기!!</strong>

배열을 우선 정렬함<br>
포인터를 left, right 두 개로 두고<br>
합이 0보다 크면 right를 왼쪽으로 옮긴다<br>
(오른쪽으로 갈수록 큰 값이니 왼쪽으로 옮기면 합이 적어질 것이기 때문)<br>
반대로 합이 0보다 작으면 left를 오른쪽으로 옮김
