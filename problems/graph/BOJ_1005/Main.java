import java.io.*;
import java.util.*;

public class Main {
    static int N, K, target;
    static int[] workTimes;
    static ArrayList<Integer>[] edges;
    static int[] loads;
    public static void main(String[] args) throws IOException {
        BufferedReader br;
        try {
            br = new BufferedReader(new FileReader("input.txt"));
        } catch (Exception e) {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());

        for(int i=0;i<T;i++){
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            workTimes = new int[N+1];
            loads = new int[N+1];
            edges = new ArrayList[N+1];

            for(int j=1;j<=N;j++){
                int time = Integer.parseInt(st.nextToken());
                workTimes[j] = time;
                edges[j] = new ArrayList<>();
            }
            for(int j=1;j<=K;j++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                edges[a].add(b);
                loads[b]++;
            }
            st = new StringTokenizer(br.readLine());
            target = Integer.parseInt(st.nextToken());
        }

        br.close();
    }

    static void solve(int now, int time, Queue<Integer> q){
        for(int i=1;i<=N;i++){
            if(loads[i] == 0){
                q.add(i);

                
            }
        }
    }
}
