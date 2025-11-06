# Math (수학)

## 개념
수학적 원리와 공식을 이용하여 문제를 해결하는 유형입니다.

## 주요 주제

### 정수론
- **소수 판정**: 에라토스테네스의 체
- **최대공약수(GCD)**: 유클리드 호제법
- **최소공배수(LCM)**: LCM = (a × b) / GCD(a, b)
- **모듈러 연산**: (a + b) mod m = ((a mod m) + (b mod m)) mod m

### 조합론
- **순열(Permutation)**: nPr = n! / (n-r)!
- **조합(Combination)**: nCr = n! / (r! × (n-r)!)
- **중복 조합**: n+r-1Cr
- **비둘기집 원리**: n+1개의 물건을 n개의 상자에 넣으면 적어도 하나의 상자에는 2개 이상

### 기하
- **직선의 방정식**: y = ax + b
- **두 점 사이의 거리**: √((x₂-x₁)² + (y₂-y₁)²)
- **CCW (Counter Clock Wise)**: 세 점의 방향성 판단
- **컨벡스 헐(Convex Hull)**: 점들을 포함하는 최소 볼록 다각형

### 수열
- **등차수열**: a_n = a₁ + (n-1)d
- **등비수열**: a_n = a₁ × r^(n-1)
- **피보나치 수열**: F(n) = F(n-1) + F(n-2)

## 유용한 공식

```java
// 최대공약수 (유클리드 호제법)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 최소공배수
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// 거듭제곱 (분할 정복)
long power(long a, long b) {
    if (b == 0) return 1;
    long half = power(a, b / 2);
    if (b % 2 == 0) return half * half;
    return half * half * a;
}

// 소수 판정
boolean isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
```

## 풀이한 문제

| 번호 | 문제 제목 | 세부 알고리즘 | 난이도 | 링크 |
|------|-----------|--------------|--------|------|
| - | - | - | - | - |

<!-- 문제를 추가할 때마다 아래 형식으로 추가하세요 -->
<!-- | 1978 | 소수 찾기 | 에라토스테네스의 체 | Silver 5 | [바로가기](./BOJ_1978) | -->
