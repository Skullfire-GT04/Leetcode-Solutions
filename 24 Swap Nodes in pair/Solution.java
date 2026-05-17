class ListNode{
    int val;
    ListNode next;
    ListNode(){};
    ListNode(int val) {this.val = val;}
    ListNode(int val, ListNode next) {this.val = val; this.next = next;}

    @Override
    public String toString(){
        StringBuilder builder = new StringBuilder();

        builder.append("{ ");
        ListNode curr = this;
        while(curr != null){
            builder.append(curr.val);
            curr = curr.next;
            if(curr != null) builder.append(", ");
        }
        builder.append(" }");

        return builder.toString();
    }
}

class Solution{

    public static ListNode swapPairs(ListNode head){
        if(head == null) return null;
        if(head.next == null) return head;

        ListNode out = head.next;
        ListNode curr_node = head, leftNode = null, old_next = null;
        ListNode[] temp = new ListNode[2];
        int count = 0;
        while(curr_node != null){
            temp[count++] = curr_node;
            curr_node = curr_node.next;
            if(count == 1 && leftNode != null){
                leftNode.next = curr_node;
            }
            if(count == 2){
                old_next = temp[1].next;
                temp[1].next = temp[0];
                leftNode = temp[0];
                count = 0;
            }
        }
        if(count == 1){
            leftNode.next = old_next;
        }else{
            leftNode.next = null;
        }

        return out;
    }

    public static void main(String[] args){
        ListNode a = new ListNode(4);
        ListNode b = new ListNode(3, a);
        ListNode c = new ListNode(2, b);
        ListNode d = new ListNode(1, c);

        System.out.println(d);
        System.out.println(swapPairs(c));
    }
}