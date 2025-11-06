# String (문자열)

## 개념
문자열 처리와 관련된 알고리즘을 다루는 유형입니다.

## 주요 알고리즘

### 문자열 검색
- **브루트 포스**: O(nm) - 모든 위치에서 패턴 비교
- **KMP (Knuth-Morris-Pratt)**: O(n+m) - 접두사-접미사 테이블 활용
- **라빈-카프**: O(n+m) - 해싱을 이용한 검색
- **보이어-무어**: 실제로 가장 빠른 문자열 검색

### 문자열 처리
- **트라이(Trie)**: 문자열 집합을 트리 구조로 저장
- **아호-코라식**: 여러 패턴을 동시에 검색
- **접미사 배열(Suffix Array)**: 문자열의 모든 접미사를 정렬
- **LCS (Longest Common Subsequence)**: 최장 공통 부분 수열
- **LCP (Longest Common Prefix)**: 최장 공통 접두사

### 기타
- **팰린드롬(Palindrome)**: 앞뒤가 똑같은 문자열
- **애너그램(Anagram)**: 철자 순서를 바꾸면 같은 문자열
- **매니커의 알고리즘**: O(n) 팰린드롬 검색

## Java 문자열 메서드

```java
String s = "Hello World";

// 길이
s.length();

// 문자 접근
s.charAt(0);

// 부분 문자열
s.substring(0, 5);

// 문자열 비교
s.equals("Hello");
s.compareTo("Hello");

// 검색
s.indexOf("World");
s.contains("World");

// 변환
s.toUpperCase();
s.toLowerCase();
s.trim();
s.replace("World", "Java");

// 분리
s.split(" ");

// StringBuilder (문자열 조작 시 효율적)
StringBuilder sb = new StringBuilder();
sb.append("Hello");
sb.append(" World");
sb.toString();
```

## 시간복잡도 주의사항
- String 연결 연산(+): O(n) - 새 문자열 객체 생성
- StringBuilder.append(): O(1) - 가변 버퍼 사용
- 문자열 비교: equals()는 O(n), ==는 O(1) (참조 비교)

## 풀이한 문제

| 번호 | 문제 제목 | 세부 알고리즘 | 난이도 | 링크 |
|------|-----------|--------------|--------|------|
| - | - | - | - | - |

<!-- 문제를 추가할 때마다 아래 형식으로 추가하세요 -->
<!-- | 9935 | 문자열 폭발 | KMP | Gold 4 | [바로가기](./BOJ_9935) | -->
