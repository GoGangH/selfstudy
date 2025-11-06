# Algorithm Study

알고리즘 문제 풀이 및 학습을 위한 저장소입니다.

## 디렉토리 구조

```
.
├── create-problem.sh      # 새 문제 생성 자동화 스크립트
├── problems/              # 백준 문제 풀이
│   ├── dp/               # 다이나믹 프로그래밍
│   ├── graph/            # 그래프
│   ├── greedy/           # 그리디
│   ├── implementation/   # 구현
│   ├── math/             # 수학
│   ├── string/           # 문자열
│   ├── data-structure/   # 자료구조
│   ├── binary-search/    # 이분탐색
│   ├── bfs-dfs/          # BFS/DFS
│   ├── backtracking/     # 백트래킹
│   ├── sorting/          # 정렬
│   ├── simulation/       # 시뮬레이션
│   └── etc/              # 기타
└── algorithm/            # 알고리즘 구현
```

## 사용법

### 새 문제 생성

스크립트를 실행하고 대화형으로 정보를 입력하세요:

```bash
./create-problem.sh
```

**입력 단계:**
1. **카테고리 선택** - 번호로 선택 (1-13)
2. **백준 문제 번호** - 숫자 입력
3. **문제 제목** - 문제 이름 입력
4. **세부 알고리즘** - 선택 사항 (예: 위상정렬, 다익스트라, 메모이제이션)
5. **난이도** - (예: Bronze 5, Silver 3, Gold 1, Platinum 5)
6. **최종 확인** - y/n으로 생성 확인

**자동으로 생성되는 것:**
- 문제 디렉토리: `problems/카테고리/BOJ_번호/`
- Java 템플릿: `Main.java` (BufferedReader/Writer 포함)
- 문제 README: 문제 정보 템플릿
- 카테고리 README에 자동으로 문제 정보 추가

### 사용 가능한 카테고리

1. `dp` - 다이나믹 프로그래밍
2. `graph` - 그래프
3. `greedy` - 그리디
4. `implementation` - 구현
5. `math` - 수학
6. `string` - 문자열
7. `data-structure` - 자료구조
8. `binary-search` - 이분탐색
9. `bfs-dfs` - BFS/DFS
10. `backtracking` - 백트래킹
11. `sorting` - 정렬
12. `simulation` - 시뮬레이션
13. `etc` - 기타

### Java 컴파일 및 실행

```bash
cd problems/카테고리/BOJ_번호
javac Main.java
java Main
```

## 문제 풀이 현황

### Dynamic Programming (DP)
[DP 문제 목록](problems/dp/README.md)

### Graph
[그래프 문제 목록](problems/graph/README.md)

### Greedy
[그리디 문제 목록](problems/greedy/README.md)

### Implementation
[구현 문제 목록](problems/implementation/README.md)

### Math
[수학 문제 목록](problems/math/README.md)

### String
[문자열 문제 목록](problems/string/README.md)

### Data Structure
[자료구조 문제 목록](problems/data-structure/README.md)

### Binary Search
[이분탐색 문제 목록](problems/binary-search/README.md)

### BFS/DFS
[BFS/DFS 문제 목록](problems/bfs-dfs/README.md)

### Backtracking
[백트래킹 문제 목록](problems/backtracking/README.md)

### Sorting
[정렬 문제 목록](problems/sorting/README.md)

### Simulation
[시뮬레이션 문제 목록](problems/simulation/README.md)

### ETC
[기타 문제 목록](problems/etc/README.md)

## 학습 자료

### 알고리즘별 핵심 개념

- **Dynamic Programming**: 중복되는 부분 문제를 해결하여 효율적으로 문제를 푸는 기법
- **Graph**: 정점과 간선으로 이루어진 자료구조와 관련 알고리즘
- **Greedy**: 매 단계에서 최적의 선택을 하는 알고리즘
- **Binary Search**: 정렬된 데이터에서 O(log n) 시간에 탐색
- **BFS/DFS**: 그래프 탐색의 기본 알고리즘

## 진행 상황

총 문제 수: 0개

## 참고 자료

- [백준 온라인 저지](https://www.acmicpc.net/)
- [solved.ac](https://solved.ac/)
