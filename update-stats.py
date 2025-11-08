#!/usr/bin/env python3
import os
import re
from collections import defaultdict

# 색상 코드
GREEN = '\033[0;32m'
BLUE = '\033[0;34m'
YELLOW = '\033[1;33m'
CYAN = '\033[0;36m'
NC = '\033[0m'

def tier_to_number(tier):
    """티어를 숫자로 변환"""
    if not tier or tier == 'Unrated' or tier == '-':
        return 0

    parts = tier.split()
    if len(parts) < 2:
        return 0

    rank = parts[0]
    try:
        level = int(parts[1])
    except (ValueError, IndexError):
        level = 3

    tier_map = {
        'Bronze': 1,
        'Silver': 6,
        'Gold': 11,
        'Platinum': 16,
        'Diamond': 21,
        'Ruby': 26
    }

    base = tier_map.get(rank, 0)
    if base == 0:
        return 0

    return base + (5 - level)

def number_to_tier(num):
    """숫자를 티어로 변환"""
    if num == 0:
        return 'Unrated'
    elif num <= 5:
        return f'Bronze {6 - num}'
    elif num <= 10:
        return f'Silver {11 - num}'
    elif num <= 15:
        return f'Gold {16 - num}'
    elif num <= 20:
        return f'Platinum {21 - num}'
    elif num <= 25:
        return f'Diamond {26 - num}'
    else:
        return f'Ruby {31 - num}'

def main():
    print(f'{BLUE}📊 통계 업데이트 중...{NC}')

    tier_count = defaultdict(int)
    status_count = defaultdict(int)
    total_problems = 0
    tier_sum = 0
    tier_problems = 0

    # 모든 카테고리 README 파일 탐색
    problems_dir = 'problems'
    for category in os.listdir(problems_dir):
        readme_path = os.path.join(problems_dir, category, 'README.md')

        if not os.path.isfile(readme_path):
            continue

        with open(readme_path, 'r', encoding='utf-8') as f:
            for line in f:
                # 주석 처리된 행 건너뛰기
                if line.strip().startswith('<!--'):
                    continue

                # 테이블 행 파싱
                if '|' not in line:
                    continue

                parts = [p.strip() for p in line.split('|')]
                if len(parts) < 7:  # 상태 컬럼 추가로 7개
                    continue

                # 빈 행이나 헤더 건너뛰기
                number = parts[1]
                if number == '-' or number == '번호' or not number:
                    continue

                # 숫자가 아니면 건너뛰기
                if not number.isdigit():
                    continue

                difficulty = parts[4]
                status = parts[5]
                total_problems += 1

                # 상태별 카운트
                if '✅' in status:
                    status_count['completed'] += 1
                elif '⏳' in status:
                    status_count['in_progress'] += 1
                elif '❌' in status:
                    status_count['failed'] += 1

                # 티어 추출
                if difficulty and difficulty != '-':
                    tier_name = difficulty.split()[0] if difficulty.split() else None

                    if tier_name:
                        tier_count[tier_name] += 1

                        # 완료된 문제만 평균 계산에 포함
                        if '✅' in status:
                            tier_num = tier_to_number(difficulty)
                            if tier_num > 0:
                                tier_sum += tier_num
                                tier_problems += 1

    # 평균 티어 계산
    if tier_problems > 0:
        avg_tier_num = tier_sum // tier_problems
        avg_tier = number_to_tier(avg_tier_num)
    else:
        avg_tier = 'Unrated'

    print(f'{GREEN}✓ 통계 계산 완료{NC}')
    print(f'{CYAN}총 문제 수: {total_problems}{NC}')
    print(f'{CYAN}완료: {status_count.get("completed", 0)}개 | 푸는 중: {status_count.get("in_progress", 0)}개 | 실패: {status_count.get("failed", 0)}개{NC}')
    print(f'{CYAN}평균 티어 (완료된 문제 기준): {avg_tier}{NC}')

    # README.md 업데이트
    readme_file = 'README.md'

    with open(readme_file, 'r', encoding='utf-8') as f:
        content = f.read()

    # 통계 섹션 생성
    stats_section = f"""## 진행 상황

총 문제 수: **{total_problems}개**

### 상태별 문제 수
- ✅ **완료**: {status_count.get('completed', 0)}개
- ⏳ **푸는 중**: {status_count.get('in_progress', 0)}개
- ❌ **실패**: {status_count.get('failed', 0)}개

### 티어별 문제 수
"""

    # 티어별 정렬 및 출력
    for tier in ['Bronze', 'Silver', 'Gold', 'Platinum', 'Diamond', 'Ruby']:
        count = tier_count.get(tier, 0)
        if count > 0:
            stats_section += f'- **{tier}**: {count}개\n'

    stats_section += f'\n### 평균 티어 (완료된 문제 기준)\n**{avg_tier}** ({tier_problems}개 문제 기준)\n'

    # 진행 상황 섹션 교체
    pattern = r'## 진행 상황.*?(?=## 참고 자료)'
    new_content = re.sub(pattern, stats_section + '\n', content, flags=re.DOTALL)

    with open(readme_file, 'w', encoding='utf-8') as f:
        f.write(new_content)

    print(f'{GREEN}✓ README.md 업데이트 완료{NC}')
    print()

if __name__ == '__main__':
    main()
