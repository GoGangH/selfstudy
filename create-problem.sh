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

# 6. 템플릿 선택
echo -e "${YELLOW}Java 템플릿을 선택하세요:${NC}"
echo -e "  ${CYAN}1${NC}. 간단한 템플릿 (Scanner + System.out.println) - 프로그래머스, 일반 코딩테스트"
echo -e "  ${CYAN}2${NC}. 빠른 템플릿 (BufferedReader/Writer) - 백준, 대용량 입출력"
echo ""

while true; do
    echo -e "${YELLOW}템플릿 번호를 입력하세요 (1-2):${NC}"
    read -r TEMPLATE_TYPE

    if [[ "$TEMPLATE_TYPE" == "1" || "$TEMPLATE_TYPE" == "2" ]]; then
        break
    else
        echo -e "${RED}❌ 1 또는 2를 입력하세요.${NC}"
    fi
done

if [ "$TEMPLATE_TYPE" == "1" ]; then
    TEMPLATE_NAME="간단한 템플릿 (Scanner)"
else
    TEMPLATE_NAME="빠른 템플릿 (BufferedReader)"
fi

echo -e "${GREEN}✓ 템플릿: ${TEMPLATE_NAME}${NC}"
echo ""

# 확인 메시지
echo -e "${CYAN}═══════════════════════════════════════${NC}"
echo -e "${BLUE}📝 입력 정보 확인:${NC}"
echo -e "  • 카테고리: ${CYAN}${CATEGORY}${NC} (${CATEGORY_NAME})"
echo -e "  • 백준 번호: ${CYAN}${BOJ_NUMBER}${NC}"
echo -e "  • 문제 제목: ${CYAN}${PROBLEM_TITLE}${NC}"
echo -e "  • 세부 알고리즘: ${CYAN}${SUB_ALGORITHM}${NC}"
echo -e "  • 난이도: ${CYAN}${DIFFICULTY}${NC}"
echo -e "  • 템플릿: ${CYAN}${TEMPLATE_NAME}${NC}"
echo -e "${CYAN}═══════════════════════════════════════${NC}"
echo ""

# 7. 최종 확인
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
mkdir -p "${PROBLEM_DIR}/input"

# Java 파일 생성
JAVA_FILE="${PROBLEM_DIR}/Main.java"

if [ "$TEMPLATE_TYPE" == "1" ]; then
    # 간단한 템플릿 (Scanner)
    cat > "$JAVA_FILE" << 'EOF'
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 코드 작성

        sc.close();
    }
}
EOF
else
    # 빠른 템플릿 (BufferedReader/Writer)
    cat > "$JAVA_FILE" << 'EOF'
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));

        // 코드 작성

        br.close();
    }
}
EOF
fi

# 테스트 케이스 파일 생성
INPUT_FILE1="${PROBLEM_DIR}/input/input1.txt"
INPUT_FILE2="${PROBLEM_DIR}/input/input2.txt"
OUTPUT_FILE1="${PROBLEM_DIR}/input/output1.txt"
OUTPUT_FILE2="${PROBLEM_DIR}/input/output2.txt"

cat > "$INPUT_FILE1" << 'EOF'
EOF

cat > "$INPUT_FILE2" << 'EOF'
EOF

cat > "$OUTPUT_FILE1" << 'EOF'
EOF

cat > "$OUTPUT_FILE2" << 'EOF'
EOF

# test.sh 스크립트 생성
TEST_SCRIPT="${PROBLEM_DIR}/test.sh"
cat > "$TEST_SCRIPT" << 'EOF'
#!/bin/bash

# 색상 정의
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

echo ""
echo -e "${CYAN}╔════════════════════════════════════════╗${NC}"
echo -e "${CYAN}║        테스트 케이스 실행 도구        ║${NC}"
echo -e "${CYAN}╚════════════════════════════════════════╝${NC}"
echo ""

# 컴파일
echo -e "${BLUE}🔨 컴파일 중...${NC}"
javac Main.java

if [ $? -ne 0 ]; then
    echo -e "${RED}❌ 컴파일 실패${NC}"
    exit 1
fi

echo -e "${GREEN}✓ 컴파일 완료${NC}"
echo ""

# input 폴더에 있는 모든 테스트 케이스 파일 찾기
if [ ! -d "input" ]; then
    echo -e "${RED}❌ input 폴더가 없습니다.${NC}"
    exit 1
fi

TEST_FILES=($(ls input/input*.txt 2>/dev/null | sort -V))

if [ ${#TEST_FILES[@]} -eq 0 ]; then
    echo -e "${RED}❌ input 폴더에 테스트 케이스가 없습니다.${NC}"
    exit 1
fi

echo -e "${BLUE}📝 총 ${#TEST_FILES[@]}개의 테스트 케이스를 실행합니다.${NC}"
echo ""

# 테스트 결과 통계
PASSED=0
FAILED=0

# 각 테스트 케이스 실행
for TEST_FILE in "${TEST_FILES[@]}"; do
    TEST_NAME=$(basename "$TEST_FILE")
    TEST_NUM=$(echo "$TEST_NAME" | sed 's/input\([0-9]*\)\.txt/\1/')
    OUTPUT_FILE="input/output${TEST_NUM}.txt"

    echo -e "${CYAN}═══════════════════════════════════════${NC}"
    echo -e "${YELLOW}📌 테스트 케이스: ${TEST_NAME}${NC}"
    echo -e "${CYAN}═══════════════════════════════════════${NC}"

    # 입력 데이터 표시
    echo -e "${BLUE}[입력]${NC}"
    cat "$TEST_FILE"
    echo ""

    # input.txt에 복사
    cp "$TEST_FILE" input.txt

    # 실행 및 출력 캡처
    echo -e "${BLUE}[실제 출력]${NC}"
    ACTUAL_OUTPUT=$(java Main)
    echo "$ACTUAL_OUTPUT"
    echo ""

    # 예상 출력 파일이 있으면 비교
    if [ -f "$OUTPUT_FILE" ] && [ -s "$OUTPUT_FILE" ]; then
        echo -e "${BLUE}[예상 출력]${NC}"
        cat "$OUTPUT_FILE"
        echo ""

        # 실제 출력을 임시 파일에 저장 (앞뒤 공백 제거)
        echo "$ACTUAL_OUTPUT" | sed 's/^[[:space:]]*//;s/[[:space:]]*$//' > /tmp/actual_output.txt

        # 예상 출력도 앞뒤 공백 제거
        sed 's/^[[:space:]]*//;s/[[:space:]]*$//' "$OUTPUT_FILE" > /tmp/expected_output.txt

        # 비교
        if diff -q /tmp/actual_output.txt /tmp/expected_output.txt > /dev/null 2>&1; then
            echo -e "${GREEN}✅ 통과!${NC}"
            ((PASSED++))
        else
            echo -e "${RED}❌ 실패!${NC}"
            echo -e "${YELLOW}[차이점]${NC}"
            diff /tmp/actual_output.txt /tmp/expected_output.txt || true
            ((FAILED++))
        fi

        # 임시 파일 삭제
        rm -f /tmp/actual_output.txt /tmp/expected_output.txt
    else
        echo -e "${YELLOW}⚠️  예상 출력 파일이 없습니다 (${OUTPUT_FILE})${NC}"
    fi

    echo ""

done

# input.txt 정리
rm -f input.txt

echo -e "${CYAN}╔════════════════════════════════════════╗${NC}"
echo -e "${CYAN}║            테스트 결과 요약            ║${NC}"
echo -e "${CYAN}╚════════════════════════════════════════╝${NC}"
echo -e "${GREEN}✅ 통과: ${PASSED}개${NC}"
echo -e "${RED}❌ 실패: ${FAILED}개${NC}"
echo -e "${BLUE}📊 전체: ${#TEST_FILES[@]}개${NC}"
echo ""

if [ $FAILED -eq 0 ] && [ $PASSED -gt 0 ]; then
    echo -e "${GREEN}╔════════════════════════════════════════╗${NC}"
    echo -e "${GREEN}║       🎉 모든 테스트 통과! 🎉        ║${NC}"
    echo -e "${GREEN}╚════════════════════════════════════════╝${NC}"
else
    echo -e "${YELLOW}╔════════════════════════════════════════╗${NC}"
    echo -e "${YELLOW}║          테스트 완료               ║${NC}"
    echo -e "${YELLOW}╚════════════════════════════════════════╝${NC}"
fi
echo ""
EOF

chmod +x "$TEST_SCRIPT"

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
- 상태: ⏳ 푸는 중

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
    NEW_ROW="| ${BOJ_NUMBER} | ${PROBLEM_TITLE} | ${SUB_ALGORITHM} | ${DIFFICULTY} | ⏳ | [바로가기](./BOJ_${BOJ_NUMBER}) |"

    # 빈 행(| - | - | - | - | - | - |) 바로 위에 새 행 추가
    awk -v new_row="$NEW_ROW" '
    {
        if ($0 ~ /^\| - \| - \| - \| - \| - \| - \|$/) {
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
echo -e "  • 입력 파일: ${CYAN}${PROBLEM_DIR}/input/input1.txt, input2.txt${NC}"
echo -e "  • 출력 파일: ${CYAN}${PROBLEM_DIR}/input/output1.txt, output2.txt${NC}"
echo -e "  • 테스트 스크립트: ${CYAN}${TEST_SCRIPT}${NC}"
echo -e "  • README: ${CYAN}${README_FILE}${NC}"
echo -e "  • 카테고리 목록에 자동 추가됨"
echo ""
# 통계 업데이트
echo -e "${BLUE}📊 통계 업데이트 중...${NC}"
python3 update-stats.py 2>/dev/null || echo -e "${YELLOW}⚠️  통계 업데이트를 건너뛰었습니다.${NC}"
echo ""

echo -e "${YELLOW}📌 다음 단계:${NC}"
echo -e "  ${CYAN}1.${NC} cd ${PROBLEM_DIR}"
echo -e "  ${CYAN}2.${NC} input/input1.txt, input2.txt에 테스트 입력 작성"
echo -e "  ${CYAN}3.${NC} input/output1.txt, output2.txt에 예상 출력 작성"
echo -e "  ${CYAN}4.${NC} 코드 작성: vim Main.java 또는 IDE에서 열기"
echo -e "  ${CYAN}5.${NC} 테스트 실행: ./test.sh"
echo -e "  ${CYAN}6.${NC} README.md에 풀이 작성"
echo ""
