BFS로 풀면 되겠다고 생각했는데 visited를 체크하지 않았더니 메모리초과가 났다<br>
2x로 가는 것은 +1초를 하지 않기 때문에 제일 먼저 수행해보고<br>
그뒤에 앞으로 가는 것이나 뒤로 가는 것을 수행했다.<br><br>

class Point에 distance를 두어서 +1씩 하는 방법이 아닌<br>
result 배열을 따로 두어서 거기에 드는 시간을 저장해두는 방식을 사용했다.<br>
