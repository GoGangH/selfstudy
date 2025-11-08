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

        # 실제 출력을 임시 파일에 저장
        echo "$ACTUAL_OUTPUT" > /tmp/actual_output.txt

        # 비교
        if diff -q /tmp/actual_output.txt "$OUTPUT_FILE" > /dev/null 2>&1; then
            echo -e "${GREEN}✅ 통과!${NC}"
            ((PASSED++))
        else
            echo -e "${RED}❌ 실패!${NC}"
            echo -e "${YELLOW}[차이점]${NC}"
            diff /tmp/actual_output.txt "$OUTPUT_FILE" || true
            ((FAILED++))
        fi

        # 임시 파일 삭제
        rm -f /tmp/actual_output.txt
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
