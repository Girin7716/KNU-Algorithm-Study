1. 코드 설명
<hr>

    0 ~ 9까지 감소하는 수 : 9개

   10 ~ 19까지 감소하는 수 : 1
   20 ~ 29까지 : 2 = 1 + 1
   30 ~ 39 : 3 = 1 + 1 + 1
   40 ~ 49 : 4 = 1 + 1 + 1
   50 ~ 59 : 5
   60 ~ 69 : 6
   70 ~ 79 : 7
   80 ~ 89 : 8
   90 ~ 99 : 9 (90에서 9칸 만큼 갈 수 있음)

   100 ~ 199 : 0
   200 ~ 299 : 1 
   300 ~ 399 : 1 + 2
   400 ~ 499 : 1 + 2 + 3
   500 ~ 599 : 1 + 2 + 3 + 4
   600 ~ 699 : 1 + 2 + 3 + 4 + 5
   700 ~ 799 : 1 + 2 + 3 + 4 + 5 + 6
   800 ~ 899 : 1 + 2 + 3 + 4 + 5 + 6 + 7
   900 ~ 999 : 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8

   1000 ~ 1999 : 0
   2000 ~ 2999 : 0
   3000 ~ 3999 : 1
   4000 ~ 4999 : 1 + (1+2)
   5000 ~ 5999 : 1 + (1+2) + (1+2+3)
   6000 ~ 6999 : 1 + (1+2) + (1+2+3) + (1+2+3+4)
   7000 ~ 7999 : 1 + (1+2) + (1+2+3) + (1+2+3+4) + (1+2+3+4+5)
   8000 ~ 8999 : 1 + (1+2) + (1+2+3) + (1+2+3+4) + (1+2+3+4+5) + (1+2+3+4+5+6)
   9000 ~ 9999 : 1 + (1+2) + (1+2+3) + (1+2+3+4) + (1+2+3+4+5) + (1+2+3+4+5+6) + (1+2+3+4+5+6+7)

   ...
   ...

   10000 ~ 40000 : 0
   100000 ~ 500000 : 0
   1000000 ~ 6000000 : 0
   10000000 ~ 70000000 : 0
   100000000 ~ 800000000 : 0
   1000000000 ~ 9000000000 : 0

그렇다면 map[i][j] = map[i-1][j] + map[i-1][j-1]이 된다.

만약 이를 배열로 나타낸다면 행이 맨 앞의 숫자이고

열이 해당 숫자의 자리수일때

   1   1   0   0   0   0   0   0   0   0 
   1   2   1   0   0   0   0   0   0   0 
   1   3   3   1   0   0   0   0   0   0 
   1   4   6   4   1   0   0   0   0   0 
   1   5  10  10   5   1   0   0   0   0 
   1   6  15  20  15   6   1   0   0   0 
   1   7  21  35  35  21   7   1   0   0 
   1   8  28  56  70  56  28   8   1   0 
   1   9  36  84 126 126  84  36   9   1

해당 표의 뜻은 만약 map[4][3] = 6인데, 4로 시작하는 세자리수에는 감소하는 수가 6개 존자한다는 뜻이다.

이를 이용해 만약 N번째 감소하는 수에서 점점 배열을 빼가면서 N이 0 이하가 되었을때 해당 칸이 감소하는 수의 자리수와 해당 자리수에 해당하는 숫자를 뜻한다.

이를 계속해서 반복해주면 결국 N번째 감소하는 수가 나오게 된다.

2. 느낀점
<hr>

풀어봤던 문젠데 전혀 나아진게 없다.

DP로도 푸는 방법이 있는것 같던데 다시한번 살펴봐야겠다.