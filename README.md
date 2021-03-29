# :computer: KNU Algorithm Study :computer:

## :closed_book: 알고리즘 사이트

스터디는 다음 알고리즘 사이트에 있는 문제로 진행한다.

[BAEKJOON](https://www.acmicpc.net/) - solved.ac 기준 골드이상

[Programmers](https://programmers.co.kr/learn/challenges?tab=all_challenges) - Level 2 이상

## :orange_book: 진행방식

- **매주 2~3문제**를 정해서 문제풀이를 진행.
- 주마다 돌아가면서 문제 선택
- 푼 문제에 대해서는 해당 **코드**와 함께 **코드 풀이**인 `README.md`를 작성하여 업로드
- 자신이 사용하고 싶은 언어로 풀이(C++,Java,Python...)
- **최대 2시간동안** 고민해서 풀지 못하면 구글에서 답을 찾아보고 로직을 이해한 뒤 **코드 작성 + 코드 풀이 업로드**
  - 이 경우 나중에 다시 풀기 위해 `Week Study`에 자신의 이름을 업로드할 때 [이름_Re](파일경로) 로 수정한다.
  - 추후, 다시 풀게 되면 [이름](파일경로)로 바꾸기.
- Github 활용
  - Repository를 Fork해온다.
  - 문제를 풀고 **문제 단위**로 commit을 한다.
    - ex> git commit -m "2주차_백준_11054_Sol"
    - ex> git commit -m "2주차_백준_11054_Re"
  - `src/개인 폴더/문제사이트_문제 제목/`에 `코드`와 `README.md `를 업로드한다.
  - 각자의 브랜치를 생성하고, 각자의 브랜치로 PR을 보낸다.
    - ex>
      >git branch kihyun (브랜치 생성)<br>
      git checkout kihyun (브랜치로 이동)<br>
      한 문제 올린 후<br>
      git add * (파일 추가)<br>
      git commit -m "0주차_백준_10942_Sol" (추가한 파일 커밋)<br>
      git push origin kihyun (자신의 브랜치에 커밋한 내용 푸쉬)<br>
      깃허브 사이트로 와서 PR버튼 누르기<br>

      ------------------------------------
      
      >관리자가 코드 변경 확인 후 merge<br>
      git checkout master (마스터 브랜치로 이동)<br>
      git pull (변경 내용 로컬에 가져오기)<br>
      git branch -d kihyun (자신이 생성한 브랜치 삭제)<br>
      git push origin :kihyun (깃허브에서도 삭제)<br>
  - 일요일 저녁 9시에 코드 리뷰가 끝나고 master Branch로 Merge한다.
- 특별한 사정을 제외하고, 주 문제를 풀지 않았을 경우 **벌금 ~~~~원**.

## :ledger: 간단 요약

1. 코드 마감 일요일 저녁 9시

2. 각자 코드에 질문사항이나 질문사항 없으면 “확인완료”라고 적기

3. 문제는 일주일당 각자 1문제 출제 (총 4문제)

## :pencil: Week Study

|        |                              1                               |                              2                               |                            3                            |                              
| ------ | :----------------------------------------------------------: | :----------------------------------------------------------: | :-----------------------------------------------------: | 
| 1주차 | [2048(Easy)](https://www.acmicpc.net/problem/12100) | [텀 프로젝트](https://www.acmicpc.net/problem/9466) | [소수의 연속합](https://www.acmicpc.net/problem/1644) |
| 1주차 문제 푼 사람 | [이채현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/Leechaehyun/1%EC%A3%BC%EC%B0%A8_%EB%B0%B1%EC%A4%80_12100) [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week1/BOJ_12100) [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_1/BOJ_12100)| [이채현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/Leechaehyun/1%EC%A3%BC%EC%B0%A8_%EB%B0%B1%EC%A4%80_9466) [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week1/BOJ_9466) [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_1/BOJ_9466)| [이채현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/Leechaehyun/1%EC%A3%BC%EC%B0%A8_%EB%B0%B1%EC%A4%80_1644) [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week1/BOJ_1644) [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_1/BOJ_1644)|
| 2주차 | [욕심쟁이 판다](https://www.acmicpc.net/problem/1937) | [로봇 청소기](https://www.acmicpc.net/problem/4991) | [낚시왕](https://www.acmicpc.net/problem/17143) |
| 2주차 문제 푼 사람 | [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_2/BOJ_1937) [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week2/BOJ_1937) | [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_2/BOJ_4991) [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week2/BOJ_4991)| [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_2/BOJ_17143) [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week2/BOJ_17143)|
| 3주차 | [학교 탐방하기](https://www.acmicpc.net/problem/13418) | [달빛 여우](https://www.acmicpc.net/problem/16118) | [반도체 설계](https://www.acmicpc.net/problem/2352) |
| 3주차 문제 푼 사람 | [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_3/BOJ_13418) [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week3/BOJ_13418)| [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_3/BOJ_16118) [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week3/BOJ_16118) | [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_3/BOJ_2352) [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week3/BOJ_2352) |
| 4주차 | [[1차]추석 트래픽](https://programmers.co.kr/learn/courses/30/lessons/17676) | [합승 택시 요금](https://programmers.co.kr/learn/courses/30/lessons/72413) | [뉴스 클러스터링](https://programmers.co.kr/learn/courses/30/lessons/17677) |
| 4주차 문제 푼 사람 | [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week4/%5B1%EC%B0%A8%5D%EC%B6%94%EC%84%9D%20%ED%8A%B8%EB%9E%98%ED%94%BD) [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_4/P_17676)| [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week4/%ED%95%A9%EC%8A%B9%20%ED%83%9D%EC%8B%9C%20%EC%9A%94%EA%B8%88) [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_4/P_72413)| [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week4/%EB%89%B4%EC%8A%A4%20%ED%81%B4%EB%9F%AC%EC%8A%A4%ED%84%B0%EB%A7%81) [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_4/P_17677)|
| 5주차 | [매출 하락 최소화](https://programmers.co.kr/learn/courses/30/lessons/72416) | [양팔저울](https://www.acmicpc.net/problem/2629) | [순위 검색](https://programmers.co.kr/learn/courses/30/lessons/72412) |
| 5주차 문제 푼 사람 | [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week5/%EB%A7%A4%EC%B6%9C%20%ED%95%98%EB%9D%BD%20%EC%B5%9C%EC%86%8C%ED%99%94) [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_5/P_72416) | [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week5/%EC%96%91%ED%8C%94%EC%A0%80%EC%9A%B8) [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_5/BOJ_2629) | [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week5/%EC%88%9C%EC%9C%84%20%EA%B2%80%EC%83%89) [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_5/P_72412) |
| 6주차 | [Parcel](https://www.acmicpc.net/problem/16287) | [도로포장](https://www.acmicpc.net/problem/1162) | [사회망 서비스](https://www.acmicpc.net/problem/2533) |
| 6주차 문제 푼 사람 | [이채현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/Leechaehyun/1%EC%A3%BC%EC%B0%A8_%EB%B0%B1%EC%A4%80_1644) [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_6/BOJ_16287) | [이채현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/Leechaehyun/1%EC%A3%BC%EC%B0%A8_%EB%B0%B1%EC%A4%80_1644) [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_6/BOJ_1162) | [이채현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/Leechaehyun/1%EC%A3%BC%EC%B0%A8_%EB%B0%B1%EC%A4%80_1644) [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/week_6/BOJ_2533)
| 7주차 | [메뉴 리뉴얼](https://programmers.co.kr/learn/courses/30/lessons/72411) | [주사위 윷놀이](https://www.acmicpc.net/problem/17825) | [친구 네트워크](https://www.acmicpc.net/problem/4195) |
| 7주차 문제 푼 사람 |  |  | 


## :memo: Additional Study

> 개인적으로 알고리즘 문제를 풀면서 좋다고 생각하는 문제를 공유하는 공간.

| 문제     | 푼 사람 |                                                  
| -------- | ----------------------------------------------------- | 
| [가장 긴 바이토닉 부분 수열](https://www.acmicpc.net/problem/11054) | [김기현](https://www.acmicpc.net/problem/9012)      
| [녹색 옷 입은 애가 젤다지?](https://www.acmicpc.net/problem/4485) | [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week3/extra/BOJ_4485)
| [집 구하기](https://www.acmicpc.net/problem/13911) | [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week3/extra/BOJ_13911)
| [가장 긴 증가하는 부분수열](https://www.acmicpc.net/problem/11053) | [이상민](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/sangmin/week3/extra/BOJ_11053)
| [여행경로](https://programmers.co.kr/learn/courses/30/lessons/43164) | [김기현](https://github.com/Girin7716/KNU-Algorithm-Study/tree/master/src/kimkihyun/recommand/Programmers_43164) |

## :boy: Contributors :girl:

| [김기현](https://github.com/girin7716) | [이상민](https://github.com/Sangmeeeee) | [안상준](https://github.com/twknds) |
|-------------------------------------|-----------------------------------------|-------------------------------------|
| [이채현](https://4legs-study.tistory.com/)| [people5](https://github.com/girin7716)     | [people6](https://github.com/girin7716) |
