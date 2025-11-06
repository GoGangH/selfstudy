# Sorting (정렬)

## 개념
데이터를 특정 순서대로 나열하는 알고리즘입니다.

## 주요 정렬 알고리즘

| 알고리즘 | 평균 시간복잡도 | 최악 시간복잡도 | 공간복잡도 | 안정성 |
|---------|----------------|----------------|-----------|-------|
| 버블 정렬 | O(n²) | O(n²) | O(1) | O |
| 선택 정렬 | O(n²) | O(n²) | O(1) | X |
| 삽입 정렬 | O(n²) | O(n²) | O(1) | O |
| 퀵 정렬 | O(n log n) | O(n²) | O(log n) | X |
| 병합 정렬 | O(n log n) | O(n log n) | O(n) | O |
| 힙 정렬 | O(n log n) | O(n log n) | O(1) | X |
| 계수 정렬 | O(n+k) | O(n+k) | O(k) | O |

## Java 정렬

### 배열 정렬
```java
// 기본 정렬 (오름차순)
int[] arr = {5, 2, 8, 1, 9};
Arrays.sort(arr);

// 내림차순 (Integer[] 필요)
Integer[] arr = {5, 2, 8, 1, 9};
Arrays.sort(arr, Collections.reverseOrder());

// 부분 정렬
Arrays.sort(arr, 0, 3); // 인덱스 0~2만 정렬
```

### 리스트 정렬
```java
List<Integer> list = new ArrayList<>();
Collections.sort(list); // 오름차순
Collections.sort(list, Collections.reverseOrder()); // 내림차순
```

### 커스텀 정렬
```java
// Comparable 구현
class Student implements Comparable<Student> {
    int id;
    int score;

    @Override
    public int compareTo(Student o) {
        return this.score - o.score; // 점수 오름차순
    }
}

// Comparator 사용
Arrays.sort(arr, new Comparator<Student>() {
    @Override
    public int compare(Student s1, Student s2) {
        if (s1.score != s2.score) {
            return s2.score - s1.score; // 점수 내림차순
        }
        return s1.id - s2.id; // 같으면 id 오름차순
    }
});

// 람다식
Arrays.sort(arr, (s1, s2) -> {
    if (s1.score != s2.score) return s2.score - s1.score;
    return s1.id - s2.id;
});
```

## 정렬 선택 가이드
- **작은 데이터**: 삽입 정렬
- **일반적인 경우**: 퀵 정렬, 병합 정렬
- **안정성 필요**: 병합 정렬
- **메모리 제약**: 힙 정렬
- **범위가 작은 정수**: 계수 정렬

## 정렬의 안정성
- **안정 정렬**: 같은 값의 순서가 유지됨
- **불안정 정렬**: 같은 값의 순서가 바뀔 수 있음

## 풀이한 문제

| 번호 | 문제 제목 | 난이도 | 링크 |
|------|-----------|--------|------|
| - | - | - | - |

<!-- 문제를 추가할 때마다 아래 형식으로 추가하세요 -->
<!-- | 2750 | 수 정렬하기 | Bronze 2 | [바로가기](./BOJ_2750) | -->
