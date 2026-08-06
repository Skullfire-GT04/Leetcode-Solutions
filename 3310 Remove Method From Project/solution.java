import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;


class RemainingMethods{

    public static List<Integer> remainingMethods(int n, int k, int[][] invocations){
        List<Integer> out = new ArrayList<>();
        @SuppressWarnings("unchecked")
        ArrayList<Integer>[] adj_list = new ArrayList[n];
        for(int i = 0; i < n; i++) adj_list[i] = new ArrayList<>();

        if(invocations != null){
            for(int i = 0; i < invocations.length; i++){
                adj_list[invocations[i][0]].add(invocations[i][1]);
            }
        }

        HashMap<Integer, Integer> suspicious_methods = new HashMap<>();
        boolean[] visited = new boolean[n];

        ArrayList<Integer> waiting_methods = new ArrayList<>();
        waiting_methods.add(k);
        while(!waiting_methods.isEmpty()){
            int method = waiting_methods.get(0);
            waiting_methods.remove(0);
            suspicious_methods.put(method, 1);
            for(int i : adj_list[method]){
                if(!visited[i]){
                    visited[i] = true;
                    waiting_methods.add(i);
                }
            }
        }
        boolean used_outside_suspicious_ring = false;
        for(int i = 0; i < n; i++){
            if(suspicious_methods.containsKey(i)) continue;
            for(int method : adj_list[i]){
                if(suspicious_methods.containsKey(method)){
                    used_outside_suspicious_ring = true;
                    break;
                }
            }
            if(used_outside_suspicious_ring) break;
        }

        if(used_outside_suspicious_ring){
            for(int i = 0; i < n; i++) out.add(i);
        }else{
            for(int i = 0; i < n; i++){
                if(suspicious_methods.containsKey(i)) continue;
                out.add(i);
            }
        }
        return out;
    }

    public static void main(String[] args){
        int[][] invocations = {{1, 2}, {0, 1}, {2, 0}};
        List<Integer> remaining_methods = remainingMethods(3, 2, invocations);
        System.err.println("Methods remaining after removing suspicious ones :");
        for(int i : remaining_methods){
            System.err.print(i + " ");
        }
        System.out.println();
    }

}