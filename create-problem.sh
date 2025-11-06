#!/bin/bash

# 색상 정의
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# 사용 가능한 카테고리
CATEGORIES=("dp" "graph" "greedy" "implementation" "math" "string" "data-structure" "binary-search" "bfs-dfs" "backtracking" "sorting" "simulation" "etc")
CATEGORY_NAMES=("다이나믹 프로그래밍" "그래프" "그리디" "구현" "수학" "문자열" "자료구조" "이분탐색" "BFS/DFS" "백트래킹" "정렬" "시뮬레이션" "기타")

echo ""
echo -e "${CYAN}╔════════════════════════════════════════╗${NC}"
echo -e "${CYAN}║     백준 문제 생성 도구 (Java)        ║${NC}"
echo -e "${CYAN}╚════════════════════════════════════════╝${NC}"
echo ""

# 1. 카테고리 선택
echo -e "${BLUE}📁 카테고리를 선택하세요:${NC}"
for i in "${!CATEGORIES[@]}"; do
    printf "  ${YELLOW}%2d${NC}. %-20s (${CYAN}%s${NC})\n" $((i+1)) "${CATEGORIES[$i]}" "${CATEGORY_NAMES[$i]}"
done
echo ""

while true; do
    echo -e "${YELLOW}카테고리 번호를 입력하세요 (1-${#CATEGORIES[@]}):${NC}"
    read -r CATEGORY_NUM

    if [[ "$CATEGORY_NUM" =~ ^[0-9]+$ ]] && [ "$CATEGORY_NUM" -ge 1 ] && [ "$CATEGORY_NUM" -le "${#CATEGORIES[@]}" ]; then
        CATEGORY="${CATEGORIES[$((CATEGORY_NUM-1))]}"
        CATEGORY_NAME="${CATEGORY_NAMES[$((CATEGORY_NUM-1))]}"
        break
    else
        echo -e "${RED}❌ 1부터 ${#CATEGORIES[@]} 사이의 숫자를 입력하세요.${NC}"
    fi
done

echo -e "${GREEN}✓ 선택됨: ${CATEGORY} (${CATEGORY_NAME})${NC}"
echo ""

# 2. 백준 번호 입력
while true; do
    echo -e "${YELLOW}백준 문제 번호를 입력하세요:${NC}"
    read -r BOJ_NUMBER

    if ! [[ "$BOJ_NUMBER" =~ ^[0-9]+$ ]]; then
        echo -e "${RED}❌ 백준 번호는 숫자여야 합니다.${NC}"
        continue
    fi

    # 디렉토리 존재 여부 확인
    PROBLEM_DIR="problems/${CATEGORY}/BOJ_${BOJ_NUMBER}"
    if [ -d "$PROBLEM_DIR" ]; then
        echo -e "${RED}❌ 이미 존재하는 문제입니다: ${PROBLEM_DIR}${NC}"
        echo -e "${YELLOW}다른 번호를 입력하세요.${NC}"
        continue
    fi

    break
done

echo -e "${GREEN}✓ 백준 번호: ${BOJ_NUMBER}${NC}"
echo ""

# 3. 문제 제목 입력
echo -e "${YELLOW}문제 제목을 입력하세요:${NC}"
read -r PROBLEM_TITLE

if [ -z "$PROBLEM_TITLE" ]; then
    PROBLEM_TITLE="문제 제목"
fi

echo -e "${GREEN}✓ 문제 제목: ${PROBLEM_TITLE}${NC}"
echo ""

# 4. 세부 알고리즘 입력 (선택 사항)
echo -e "${YELLOW}세부 알고리즘을 입력하세요 (선택, Enter로 건너뛰기):${NC}"
echo -e "${CYAN}예시: 위상정렬, 다익스트라, 메모이제이션, 이분탐색, BFS 등${NC}"
read -r SUB_ALGORITHM

if [ -z "$SUB_ALGORITHM" ]; then
    SUB_ALGORITHM="-"
    echo -e "${GREEN}✓ 세부 알고리즘: 지정 안함${NC}"
else
    echo -e "${GREEN}✓ 세부 알고리즘: ${SUB_ALGORITHM}${NC}"
fi
echo ""

# 5. 난이도 입력
echo -e "${YELLOW}난이도를 입력하세요:${NC}"
echo -e "${CYAN}예시: Bronze 5, Silver 3, Gold 1, Platinum 5, Diamond 1${NC}"
read -r DIFFICULTY

if [ -z "$DIFFICULTY" ]; then
    DIFFICULTY="Unrated"
fi

echo -e "${GREEN}✓ 난이도: ${DIFFICULTY}${NC}"
echo ""

# 확인 메시지
echo -e "${CYAN}═══════════════════════════════════════${NC}"
echo -e "${BLUE}📝 입력 정보 확인:${NC}"
echo -e "  • 카테고리: ${CYAN}${CATEGORY}${NC} (${CATEGORY_NAME})"
echo -e "  • 백준 번호: ${CYAN}${BOJ_NUMBER}${NC}"
echo -e "  • 문제 제목: ${CYAN}${PROBLEM_TITLE}${NC}"
echo -e "  • 세부 알고리즘: ${CYAN}${SUB_ALGORITHM}${NC}"
echo -e "  • 난이도: ${CYAN}${DIFFICULTY}${NC}"
echo -e "${CYAN}═══════════════════════════════════════${NC}"
echo ""

# 6. 최종 확인
echo -e "${YELLOW}위 정보로 문제를 생성하시겠습니까? (y/n):${NC}"
read -r CONFIRM

if [[ ! "$CONFIRM" =~ ^[yY]$ ]]; then
    echo -e "${RED}❌ 문제 생성이 취소되었습니다.${NC}"
    exit 0
fi

echo ""
echo -e "${BLUE}🔨 문제 생성 중...${NC}"

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
- 카테고리: ${CATEGORY_NAME}
- 세부 알고리즘: ${SUB_ALGORITHM}
- 난이도: ${DIFFICULTY}

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
    NEW_ROW="| ${BOJ_NUMBER} | ${PROBLEM_TITLE} | ${SUB_ALGORITHM} | ${DIFFICULTY} | [바로가기](./BOJ_${BOJ_NUMBER}) |"

    # 빈 행(| - | - | - | - | - |) 바로 위에 새 행 추가
    awk -v new_row="$NEW_ROW" '
    {
        if ($0 ~ /^\| - \| - \| - \| - \| - \|$/) {
            print new_row
        }
        print $0
    }
    ' "$CATEGORY_README" > "$TEMP_FILE"

    # 원본 파일 교체
    mv "$TEMP_FILE" "$CATEGORY_README"
fi

# 성공 메시지
echo ""
echo -e "${GREEN}╔════════════════════════════════════════╗${NC}"
echo -e "${GREEN}║          ✅ 생성 완료!                 ║${NC}"
echo -e "${GREEN}╚════════════════════════════════════════╝${NC}"
echo ""
echo -e "${BLUE}📂 생성된 파일:${NC}"
echo -e "  • 디렉토리: ${CYAN}${PROBLEM_DIR}${NC}"
echo -e "  • Java 파일: ${CYAN}${JAVA_FILE}${NC}"
echo -e "  • README: ${CYAN}${README_FILE}${NC}"
echo -e "  • 카테고리 목록에 자동 추가됨"
echo ""
echo -e "${YELLOW}📌 다음 단계:${NC}"
echo -e "  ${CYAN}1.${NC} cd ${PROBLEM_DIR}"
echo -e "  ${CYAN}2.${NC} 코드 작성: vim Main.java 또는 IDE에서 열기"
echo -e "  ${CYAN}3.${NC} 컴파일 및 실행: javac Main.java && java Main"
echo -e "  ${CYAN}4.${NC} README.md에 풀이 작성"
echo ""
