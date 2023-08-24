package Networking;
import java.util.*;
public class test {
    public static String findOrder(String [] dict, int N, int K){
        ArrayList<Integer> []graph=new ArrayList[K];
        for(int i=0;i<K;i++){
            graph[i]=new ArrayList<>();
        }
        for(int i=0;i<N-1;i++){
            String s1=dict[i];
            String s2=dict[i+1];
            int len1=s1.length();
            int len2=s2.length();
            int minLen= Math.min(len1, len2);

            for(int j=0;j<minLen;j++){
                int c1=s1.charAt(j);
                int c2=s2.charAt(j);
                if(c1!=c2) {
                    graph[c1 - 'a'].add(c2 - 'a');
                    break;
                }
            }
        }
        Queue<Integer>q=new LinkedList<>();
        int[]indegree=new int[K];
        for(int i=0;i<K;i++){
            for(int adj:graph[i]){
                indegree[adj]++;
            }
        }

        for(int i=0;i<K;i++){
            if(indegree[i]==0){
                q.add(i);
            }
        }
        // System.out.println(q.size());
        String ans="";
        while(!q.isEmpty()){
            int node=q.remove();
            char c=(char)('a'+node);
            // System.out.println(c);
            ans=ans+c;
            for(int adj:graph[node]){
                indegree[adj]--;
                if(indegree[adj]==0){
                    q.add(adj);
                }
            }
        }
        // System.out.println(ans);
        if(ans.length()==K)
            return 1+"";
        return 0+"";
    }
    static boolean isValid(int mid,int[]ct,int[]rc,long budget){
        PriorityQueue<Integer>pq=new PriorityQueue<>(Collections.reverseOrder());
        int len=ct.length;
        int i=0,j=0;
        int max=Integer.MIN_VALUE;
        int sum=0;
        while(j<len){
            pq.add(ct[j]);
            System.out.println(pq);
            sum+=rc[j];
            if((j-i+1)==mid){
                System.out.println("hello");
                int curr=pq.peek();
                System.out.println(curr);
                max=Math.max(max,curr+(mid)*sum);

                if(curr==ct[i]) pq.remove();
                sum-=rc[i];
                i++;
            }
            j++;
        }
        System.out.println(mid+" "+max);
        return max<=budget;
    }
    public static void main(String[] args) {
        TreeSet<Integer>hs=new TreeSet<>();
        int[]ar1={8,76,74,9,75,71,71,42,15,58,88,38,56,59,10,11};
        int[]ar2={1,92,41,63,22,37,37,8,68,97,39,59,45,50,29,37};
        isValid(3,ar1,ar2,412);
        Queue<Integer>q=new LinkedList<>();
//        q.forEach(System.out::println);
//        String ans=findOrder(new String[]{"baa", "abcd", "abca" ,"cab" ,"cada"},5,4);
//        System.out.println(ans);
    }
}
