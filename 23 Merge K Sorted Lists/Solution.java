import java.util.ArrayList;
import java.util.Collections;

class ListNode{
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) {this.val = val;}
    ListNode(int val, ListNode next) {this.val = val; this.next = next;}

    @Override
    public String toString(){
        StringBuilder builder = new StringBuilder();

        builder.append("[ ");
        ListNode curr_node = this;
        while(curr_node != null){
            builder.append(curr_node.val);
            curr_node = curr_node.next;
            if(curr_node != null) builder.append(", ");
        }
        builder.append(" ]");
        return builder.toString();
    }
}


class SortNode {
    
    public static void merge(ListNode leftNode, ListNode rightNode, ListNode out){
        ListNode l = leftNode, r = rightNode, i = out;
        while(l != null && r != null){
            if(l.val < r.val){
                i.val = l.val;
                l = l.next;
            }else{
                i.val = r.val;
                r = r.next;
            }
            i.next = new ListNode();
            i = i.next;
        }
        while(l != null){
            i.val = l.val;
            l = l.next;
            if(l != null) i.next = new ListNode();
            i = i.next;
        }
        while(r != null){
            i.val = r.val;
            r = r.next;
            if(r != null) i.next = new ListNode();
            i = i.next;
        }

    }

    public static void sortNode(ListNode node){
        ArrayList<Integer> tmp = new ArrayList<>();
        ListNode curr_node = node;
        while(curr_node != null){
            tmp.add(curr_node.val);
            curr_node = curr_node.next;
        }
        Collections.sort(tmp);
        curr_node = node;
        for(int i : tmp){
            curr_node.val = i;
            curr_node = curr_node.next;
        }
    }

    public static ListNode mergeKLists(ListNode[] lists){
        if(lists.length < 1) return null;

        ListNode out = null;
        boolean first_run = true;

        for(ListNode node : lists){
            if(node == null) continue;
            ListNode copy = first_run ? null : out == null ? new ListNode() : out;
            if(first_run) first_run = false;
            out = new ListNode();
            sortNode(node);
            merge(copy, node, out);
        }
        return out;
    }

    public static void main(String[] args) {
        ListNode a = new ListNode(1);
        ListNode b = new ListNode(4, a);
        ListNode c = new ListNode(5, b);

        ListNode d = new ListNode(4);
        ListNode e = new ListNode(1, d);
        ListNode f = new ListNode(3, e);

        ListNode g = new ListNode(2);
        ListNode h = new ListNode(6, g);

        ListNode temp = mergeKLists(new ListNode[]{null, h, f, c});

        // ArrayList<Integer> temp = new ArrayList<>();
        // temp.add(1);
        // temp.add(2);
        // temp.add(2);
        // temp.add(3);
        
        // System.out.println(getMinVal(temp));
        // System.out.println(temp.size());
        // System.out.println(getMinVal(temp));
        // System.out.println(temp.size());

        System.out.println(temp);

        System.out.println();
    }
}
