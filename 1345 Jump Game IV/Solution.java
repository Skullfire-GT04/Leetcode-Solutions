import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

class MinJumps{

    public static int minJumps(int[] arr){
        int distance = 0;

        int n = arr.length;
        boolean[] visited = new boolean[n];
        for(int i = 0; i < n; i++) visited[i] = false;

        HashMap<Integer, ArrayList<Integer>> val_map = new HashMap<>();
        for(int i = 0; i < n; i++){
            if(val_map.containsKey(arr[i])){
                val_map.get(arr[i]).add(i);
            }else{
                ArrayList<Integer> temp = new ArrayList<>();
                temp.add(i);
                val_map.put(arr[i], temp);
            }
        }

        Queue<Integer> to_be_visited = new LinkedList<>();
        int nodes_remaining = 1;
        to_be_visited.add(0);
        while(!to_be_visited.isEmpty()){
            int curr_node = to_be_visited.poll();
            if(curr_node == n - 1) break;
            visited[curr_node] = true;
            nodes_remaining--;

            if(curr_node + 1 < n && !visited[curr_node + 1]) to_be_visited.add(curr_node + 1);
            if(curr_node - 1 >= 0 && !visited[curr_node - 1]) to_be_visited.add(curr_node - 1);
            if(val_map.get(arr[curr_node]) != null){
                for(int index : val_map.get(arr[curr_node])){
                    if(!visited[index])
                    to_be_visited.add(index);
                }
            }
            val_map.remove(arr[curr_node]);

            if(nodes_remaining == 0){
                nodes_remaining = to_be_visited.size();
                distance++;
            }
        }
        
        return distance;
    }

    public static void main(String[] args) {
        System.out.println(minJumps(new int[]{100}));

    }
}