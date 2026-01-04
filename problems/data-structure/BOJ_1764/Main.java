import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br;
        int n, m;
        HashMap<String, Integer> pq = new HashMap<>();
        TreeSet<String> result = new TreeSet<>();

        try {
            br = new BufferedReader(new FileReader("input.txt"));
        } catch (Exception e) {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for(int i=0;i<n;i++){
            String name = br.readLine();
            pq.put(name, 1);
        }

        for(int i=0;i<m;i++){
            String name = br.readLine();
            if(pq.getOrDefault(name, 0).equals(1)){
                result.add(name);
            }
        }
        br.close();

        System.out.println(result.size());
        if(result.size() == 0) return;
        String lastElement = result.last();
        for(String name : result){
            if(name.equals(lastElement)) {
                System.out.print(name);
            } else {
                System.out.println(name);
            }
        }
    }
}
