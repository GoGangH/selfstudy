import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static HashMap<Integer, ArrayList<Integer>> edge = new HashMap<>();
    static Queue<Integer> q = new LinkedList<>();
    static int[] edges;
    public static void main(String[] args) throws IOException {
        BufferedReader br;
        try {
            br = new BufferedReader(new FileReader("input.txt"));
        } catch (Exception e) {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        edges = new int[N+1];

        for(int i=0;i<M;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            ArrayList<Integer> load = edge.getOrDefault(a, new ArrayList<Integer>());
            load.add(b);
            edge.put(a, load);
            edges[b]++;
        }

        solve();
    }

    public static void solve(){
        for(int i=1;i<=N;i++){
            if(edges[i] == 0){
                q.add(i);
            }
        }
        while(!q.isEmpty()){
            int now = q.poll();
            System.out.print(now + " ");
            edges[now] = -1;
            ArrayList<Integer> load = edge.getOrDefault(now, new ArrayList<Integer>());
            for(Integer way : load){
                edges[way]--;
                if(edges[way] == 0){
                    q.add(way);
                }
            }
        }
    }
}
