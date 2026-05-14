class ListNode{
    int val;
    ListNode next;
    ListNode() {this.val = 0;}
    ListNode(int val) {this.val = val;}
    ListNode(int val, ListNode next) {this.val = val; this.next = next;}

    @Override
    public String toString(){
        StringBuilder builder = new StringBuilder();

        builder.append("{ ");
        ListNode curr_node = this;
        while(curr_node != null){
            builder.append(curr_node.val);
            curr_node = curr_node.next;
            if(curr_node != null) builder.append(", ");
        }
        builder.append(" }");

        return builder.toString();
    }
}

class Solution {
    
    public static ListNode reverseKGroup(ListNode head, int k){
        ListNode out = null;

        ListNode[] tmp = new ListNode[k];
        ListNode curr_node = head, new_node = null, left_node = null;
        int index = 0;
        while(curr_node != null){
            tmp[index] = curr_node;
            index++;
            curr_node = curr_node.next;

            if(index == k){
                new_node = tmp[index - 1];
                if(left_node != null){
                    left_node.next = new_node;
                }
                if(out == null){
                    out = tmp[index - 1];
                }
                for(int i = index - 2; i >= 0; i--){
                    new_node.next = tmp[i];
                    new_node = new_node.next;
                }
                left_node = new_node;
                index = 0;
            }
        }
        if(index != 0){
            new_node = left_node;
            for(int i = 0; i < index; i++){
                new_node.next = tmp[i];
                new_node = new_node.next;
            }
        }else left_node.next = null;
        return out;
    }


    public static void main(String[] args) {
        ListNode a = new ListNode(5);
        ListNode b = new ListNode(4, a);
        ListNode c = new ListNode(3, b);
        ListNode d = new ListNode(2, c);
        ListNode e = new ListNode(1, d);

        System.out.println(e);

        ListNode tmp = reverseKGroup(e, 5);
        System.out.println(tmp);
    }
}
