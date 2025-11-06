# Data Structure (자료구조)

## 개념
데이터를 효율적으로 저장하고 관리하기 위한 구조입니다.
문제 특성에 맞는 자료구조를 선택하는 것이 중요합니다.

## 주요 자료구조

### 선형 자료구조
- **배열(Array)**: 고정 크기, 인덱스 접근 O(1)
- **연결 리스트(Linked List)**: 동적 크기, 삽입/삭제 O(1)
- **스택(Stack)**: LIFO (Last In First Out)
- **큐(Queue)**: FIFO (First In First Out)
- **덱(Deque)**: 양쪽 끝에서 삽입/삭제 가능

### 비선형 자료구조
- **트리(Tree)**: 계층적 구조
  - 이진 트리, 이진 탐색 트리(BST)
  - AVL 트리, 레드-블랙 트리
  - 세그먼트 트리, 펜윅 트리
- **힙(Heap)**: 최댓값/최솟값을 빠르게 찾는 완전 이진 트리
- **그래프(Graph)**: 정점과 간선으로 이루어진 구조
- **해시 테이블(Hash Table)**: 키-값 쌍, 평균 O(1) 접근

### 고급 자료구조
- **유니온 파인드(Union-Find)**: 서로소 집합
- **트라이(Trie)**: 문자열 검색
- **세그먼트 트리**: 구간 쿼리
- **우선순위 큐(Priority Queue)**: 힙 기반

## Java 자료구조 클래스

```java
// List
ArrayList<Integer> list = new ArrayList<>();
LinkedList<Integer> linkedList = new LinkedList<>();

// Stack & Queue
Stack<Integer> stack = new Stack<>();
Queue<Integer> queue = new LinkedList<>();
Deque<Integer> deque = new ArrayDeque<>();

// Set
HashSet<Integer> set = new HashSet<>();
TreeSet<Integer> treeSet = new TreeSet<>();

// Map
HashMap<String, Integer> map = new HashMap<>();
TreeMap<String, Integer> treeMap = new TreeMap<>();

// Priority Queue
PriorityQueue<Integer> pq = new PriorityQueue<>(); // 최소 힙
PriorityQueue<Integer> maxPq = new PriorityQueue<>(Collections.reverseOrder()); // 최대 힙
```

## 풀이한 문제

| 번호 | 문제 제목 | 세부 알고리즘 | 난이도 | 링크 |
|------|-----------|--------------|--------|------|
| - | - | - | - | - |

<!-- 문제를 추가할 때마다 아래 형식으로 추가하세요 -->
<!-- | 10828 | 스택 | 스택 | Silver 4 | [바로가기](./BOJ_10828) | -->
