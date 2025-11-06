#!/bin/bash

# 색상 정의
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# 사용 가능한 카테고리
CATEGORIES=("dp" "graph" "greedy" "implementation" "math" "string" "data-structure" "binary-search" "bfs-dfs" "backtracking" "sorting" "simulation" "etc")

# 함수: 카테고리 목록 출력
print_categories() {
    echo -e "${BLUE}사용 가능한 카테고리:${NC}"
    for i in "${!CATEGORIES[@]}"; do
        printf "  %2d. %s\n" $((i+1)) "${CATEGORIES[$i]}"
    done
}

# 함수: 사용법 출력
print_usage() {
    echo -e "${YELLOW}사용법:${NC}"
    echo "  ./create-problem.sh <카테고리> <백준번호> [문제제목]"
    echo ""
    echo -e "${YELLOW}예시:${NC}"
    echo "  ./create-problem.sh dp 1234"
    echo "  ./create-problem.sh dp 1234 \"피보나치 수\""
    echo ""
    print_categories
}

# 인자 확인
if [ $# -lt 2 ]; then
    print_usage
    exit 1
fi

CATEGORY=$1
BOJ_NUMBER=$2
PROBLEM_TITLE=${3:-""}

# 문제 제목이 없으면 입력받기
if [ -z "$PROBLEM_TITLE" ]; then
    echo -e "${YELLOW}문제 제목을 입력하세요:${NC}"
    read -r PROBLEM_TITLE
fi

# 난이도 입력받기
echo -e "${YELLOW}난이도를 입력하세요 (예: Bronze 5, Silver 3, Gold 1, Platinum 5):${NC}"
read -r DIFFICULTY

# 카테고리 유효성 검사
if [[ ! " ${CATEGORIES[@]} " =~ " ${CATEGORY} " ]]; then
    echo -e "${RED}❌ 잘못된 카테고리입니다: ${CATEGORY}${NC}"
    echo ""
    print_categories
    exit 1
fi

# 백준 번호 유효성 검사
if ! [[ "$BOJ_NUMBER" =~ ^[0-9]+$ ]]; then
    echo -e "${RED}❌ 백준 번호는 숫자여야 합니다: ${BOJ_NUMBER}${NC}"
    exit 1
fi

# 디렉토리 경로 설정
PROBLEM_DIR="problems/${CATEGORY}/BOJ_${BOJ_NUMBER}"

# 디렉토리 존재 여부 확인
if [ -d "$PROBLEM_DIR" ]; then
    echo -e "${RED}❌ 이미 존재하는 문제입니다: ${PROBLEM_DIR}${NC}"
    exit 1
fi

# 디렉토리 생성
mkdir -p "$PROBLEM_DIR"

# Java 파일 생성
JAVA_FILE="${PROBLEM_DIR}/Main.java"

cat > "$JAVA_FILE" << 'EOF'
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 코드 작성

        bw.flush();
        bw.close();
        br.close();
    }
}
EOF

# README 파일 생성
README_FILE="${PROBLEM_DIR}/README.md"

cat > "$README_FILE" << EOF
# [${BOJ_NUMBER}번] ${PROBLEM_TITLE}

## 문제 링크
https://www.acmicpc.net/problem/${BOJ_NUMBER}

## 문제 분류
- ${CATEGORY}

## 알고리즘
\`\`\`
여기에 알고리즘 설명 작성
\`\`\`

## 풀이
\`\`\`
여기에 풀이 설명 작성
\`\`\`

## 시간복잡도
\`\`\`
O(?)
\`\`\`

## 공간복잡도
\`\`\`
O(?)
\`\`\`
EOF

# 카테고리 README 업데이트
CATEGORY_README="problems/${CATEGORY}/README.md"

# 테이블에 새 행 추가 (빈 행 바로 위에 추가)
if [ -f "$CATEGORY_README" ]; then
    # 임시 파일 생성
    TEMP_FILE=$(mktemp)

    # 새로운 테이블 행 생성
    NEW_ROW="| ${BOJ_NUMBER} | ${PROBLEM_TITLE} | ${DIFFICULTY} | [바로가기](./BOJ_${BOJ_NUMBER}) |"

    # 빈 행(| - | - | - | - |) 바로 위에 새 행 추가
    awk -v new_row="$NEW_ROW" '
    {
        if ($0 ~ /^\| - \| - \| - \| - \|$/) {
            print new_row
        }
        print $0
    }
    ' "$CATEGORY_README" > "$TEMP_FILE"

    # 원본 파일 교체
    mv "$TEMP_FILE" "$CATEGORY_README"

    echo -e "${GREEN}✅ ${CATEGORY}/README.md 업데이트 완료!${NC}"
fi

# 성공 메시지
echo -e "${GREEN}✅ 문제 생성 완료!${NC}"
echo ""
echo -e "${BLUE}📂 디렉토리:${NC} ${PROBLEM_DIR}"
echo -e "${BLUE}📄 Java 파일:${NC} ${JAVA_FILE}"
echo -e "${BLUE}📄 README:${NC} ${README_FILE}"
echo ""
echo -e "${YELLOW}다음 단계:${NC}"
echo "  1. ${JAVA_FILE} 파일에 코드 작성"
echo "  2. ${README_FILE} 파일에 문제 정보 작성"
echo "  3. javac Main.java && java Main 으로 실행"
