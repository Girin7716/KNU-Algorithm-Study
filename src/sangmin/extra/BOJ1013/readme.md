<meta name='type' content ='구현'>
<meta name='BOJ' content='BOJ1013'>
<meta name='difficulty' content='gold5'>
<meta name='url' content='https://www.acmicpc.net/problem/1013'>
<meat name='date' cotent='2021-05-09'>
1. 코드 설명
<hr>
정규표현식은 DFA로 나타낼수있다. 따라서 컴파일러 시간에 배운 DFA를 구현하여 현재 들어오는 char이 1인지 0인지에 따라 자동적으로 구분되게 만들었다.

+ 말고도 정규표현식에는 *, ? 등의 기호가 있지만 해당 문제에서는 + 와 |, ()+만 사용했기 때문에 해당 세개의 문자를 설명하겠다.

먼저 +는 앞의 문자가 반드시 한번 이상은 반복된다는 뜻이다. 100+ 면 앞의 10은 고정이고 뒤의 0이 한번 이상은 무조건 나와야 한다는 뜻이다. 따라서 100+ 는 10이나 1, 11, 101, 10등의 문자가 올수없다.

| 는 익숙한 or 기호이다. a+ | b는 a, aa, aaa, 나 b 문자 둘중 하나라는 뜻이다.

그렇다면 ( a | b )+ 가 된다면 어떻게 될까? (a 나 b 둘중하나)가 반드시 한번이상 반복되어야 하기 때문에 a, ab, abbababab 등 a와 b로 조합할수있는 모든 문자가 다 나오게된다.

그렇다면 문제의 ( 100+1+ | 01 )+ 는 100+1+ 와 01로 조합할수 있는 모든 문자열이다.

각각의 상태에 따라 state를 만들어준다.

```c++
	switch(stmt){
	case  start :
	line[i] == '1' ? stmt=s1 : stmt=s2;
	break;
	case  s1 : // 1
	line[i] == '1' ? stmt=err : stmt=s3;
	break;
	case  s2 : // 0
	line[i] == '1' ? stmt=s4 : stmt=err;
	break;
	case  s3 : // 10
	line[i] == '1' ? stmt=err : stmt=s5;
	break;
	case  s4 : // 01
	line[i] == '1' ? stmt=s1 : stmt=s2;
	break;
	case  s5 : // 100
	line[i] == '1' ? stmt=s6 : stmt=s5;
	break;
	case  s6: // 100+1
	line[i] == '1' ? stmt=s7 : stmt=s2;
	break;
	case  s7 : // 100+1+
	line[i] == '1' ? stmt=s7 : stmt=s8;
	break;
	case  s8 : // 100+1+10
	line[i] == '1' ? stmt=start : stmt=s5;
	break;
	}
```
여기서 err 상태로 들어가면 바로 종료하고, 만약 문장이 끝났는데 final state(s4, s6, s7)가 아니라면 NO를

err 상태가 아니거나 s4, s6, s7인 상태이면 YES를 출력해준다.

2. 느낀점
<hr>
컴파일러 수업을 들었다면 무난히 풀수있는 문제였지만 만약에 몰랐다면 실전에서 나올 경우 모르면 당해라라는 마인드의 문제인것같다.

정규표현식은 컴파일러를 제외하고도 많이 사용되니까 공부할필요가있는것 같다.