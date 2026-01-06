import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br;
        String texts = " ";
        try {
            br = new BufferedReader(new FileReader("input.txt"));
        } catch (Exception e) {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        texts = br.readLine();
        while(!texts.equals(".")){
            System.out.println(checkText(texts));
            texts = br.readLine();
        }

        br.close();
    }

    public static String checkText(String texts){
        Stack<Character> s = new Stack<>();
        for(int i=0;i<texts.length();i++){
            Character t = texts.charAt(i);
            if(t.equals('[') | t.equals(']') | t.equals('(') | t.equals(')')){
                if(t.equals('[') | t.equals('(')){
                    if(t.equals('[')) s.add(']');
                    if(t.equals('(')) s.add(')');
                } else if(t.equals(']') | t.equals(')')){
                    if(s.isEmpty()) return "no";
                    Character temChar = s.pop();
                    if(!t.equals(temChar)){
                        return "no";
                    }
                }
            }
        }
        if(!s.isEmpty()) return "no";
        return "yes";
    }
}
