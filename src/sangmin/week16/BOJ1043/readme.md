1. 코드 설명
<hr>

dijoint set을 이용한 풀이이다.

각각 파티에 참여하는 사람들 중 하나를 부모로 만들고 해당 자식이나 부모와 관련된 사람들을 전부 하나로 묶어주게 된다.

그 멤버 중 하나라도 진실임을 아는 사람이 있다면 그 멤버 전체를 truth로 바꿔주는게 아니라 해당 부모만 truth로 바꿔주어 부모를 통해 연산을 진행한다.

어떤 부모가 진실을 알게되었는지 판단한다면 그 후에는 파티를 돌면서 만약 해당 멤버의 부모가 진실을 알고있는 부모일경우 해당 파티에서는 거짓말을 할수없게 된다.

2. 느낀점
<hr>

disjoint set에 판단까지 겹친 문제였다.

더 깔끔하게 작성할수있을것같기도 하고 더 좋은 코드가 있을것 같아 찾아보도록 해야겠다.