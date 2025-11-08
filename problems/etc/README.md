# ETC (기타)

## 개념
특정 카테고리로 분류하기 어려운 다양한 알고리즘과 기법들을 다루는 유형입니다.

## 포함되는 주제

### 1. 투 포인터 (Two Pointers)
- 배열에서 두 개의 포인터를 이용한 탐색
- 시간복잡도: O(n)
- 예: 두 수의 합, 부분합 문제

```java
int left = 0, right = 0;
while (right < n) {
    // 조건에 따라 포인터 이동
    if (sum < target) {
        sum += arr[right++];
    } else {
        sum -= arr[left++];
    }
}
```

### 2. 슬라이딩 윈도우 (Sliding Window)
- 고정된 크기의 윈도우를 이동하며 탐색
- 예: 구간 합, 최대/최소값 찾기

### 3. 비트마스킹 (Bitmask)
- 비트 연산을 이용한 집합 표현
- 메모리 효율적, 빠른 연산
```java
// 비트 연산
int set = 0;
set |= (1 << i);      // i번째 원소 추가
set &= ~(1 << i);     // i번째 원소 제거
boolean has = (set & (1 << i)) != 0; // i번째 원소 확인
```

### 4. 누적 합 (Prefix Sum)
- 배열의 구간 합을 O(1)에 계산
```java
// 누적 합 배열 생성
int[] prefixSum = new int[n + 1];
for (int i = 1; i <= n; i++) {
    prefixSum[i] = prefixSum[i-1] + arr[i];
}

// 구간 [left, right]의 합
int sum = prefixSum[right] - prefixSum[left-1];
```

### 5. 분할 정복 (Divide and Conquer)
- 문제를 작은 문제로 분할하여 해결
- 예: 병합 정렬, 퀵 정렬, 이진 탐색

### 6. 재귀 (Recursion)
- 함수가 자기 자신을 호출
- 기저 조건(Base Case) 필수
```java
int factorial(int n) {
    if (n <= 1) return 1;  // 기저 조건
    return n * factorial(n - 1);
}
```

### 7. 정규표현식 (Regex)
- 문자열 패턴 매칭
```java
String pattern = "^[a-zA-Z0-9]+$";
boolean matches = str.matches(pattern);
```

### 8. 비둘기집 원리 (Pigeonhole Principle)
- n+1개의 물건을 n개의 상자에 넣으면 적어도 하나의 상자에는 2개 이상

### 9. Meet in the Middle
- 탐색 공간을 절반으로 나누어 탐색
- 시간복잡도를 O(2^n)에서 O(2^(n/2))로 감소

### 10. 애드혹 (Ad-hoc)
- 특별한 알고리즘 없이 창의적인 아이디어로 해결
- 수학적 관찰, 패턴 찾기

## 풀이한 문제

| 번호 | 문제 제목 | 세부 알고리즘 | 난이도 | 상태 | 링크 |
|------|-----------|--------------|--------|------|------|
| - | - | - | - | - | - |

<!-- 문제를 추가할 때마다 아래 형식으로 추가하세요 -->
<!-- | 2003 | 수들의 합 2 | 투 포인터 | Silver 4 | [바로가기](./BOJ_2003) | -->
