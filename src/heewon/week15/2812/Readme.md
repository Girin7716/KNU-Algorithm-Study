스택을 이용하는데, top에 있는 값이 다음에 넣을 값보다 작으면 top에 있는 값을 pop하고<br>
다음에 넣을 값을 push 한다.<br><br>

처음에 Stack<Integer> stack = new Stack<>(); 에서 <Integer>을 넣는 것을 깜빡했더니<br>
peek()한 결과가 Object여서 비교하는데 문제가 생겼었다.<br><br>
  
또 for문 다음에 while을 이용해서 pop하지않고 if을 이용해서 pop했더니 예제3에서 문제가 생겼다.<br>
while문을 이용해서 그 앞에 있는 값들까지 비교를 해줬더니 문제를 해결할 수 있었다.
