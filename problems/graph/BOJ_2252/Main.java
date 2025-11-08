import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        // 진입 차수 배열
        int[] indegree = new int[N + 1];

        // 그래프 (인접 리스트)
        ArrayList<Integer>[] graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }

        // 간선 정보 입력
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            graph[A].add(B);
            indegree[B]++;
        }

        br.close();

        // 위상 정렬 (큐 사용)
        Queue<Integer> queue = new LinkedList<>();

        // 진입 차수가 0인 노드를 큐에 추가
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
            }
        }

        StringBuilder result = new StringBuilder();

        // 위상 정렬 수행
        while (!queue.isEmpty()) {
            int current = queue.poll();
            result.append(current).append(" ");

            // 현재 노드와 연결된 노드들의 진입 차수 감소
            for (int next : graph[current]) {
                indegree[next]--;

                // 진입 차수가 0이 되면 큐에 추가
                if (indegree[next] == 0) {
                    queue.offer(next);
                }
            }
        }

        System.out.println(result.toString().trim());
    }
}
