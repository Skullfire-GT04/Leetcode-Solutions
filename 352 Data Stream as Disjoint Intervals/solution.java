import java.util.ArrayList;


class SummaryRanges{

    ArrayList<int[]> intervals;

    public SummaryRanges(){
        this.intervals = new ArrayList<>();
    }

    private int searchInsertIndex(int start){
        int l = 0, r = this.intervals.size() - 1;
        while(l <= r){
            int index = (l + r) / 2;
            if(this.intervals.get(index)[0] < start && this.intervals.get(index)[1] < start) l = index + 1;
            else if(this.intervals.get(index)[0] > start) r = index - 1;
            else if(this.intervals.get(index)[0] <= start && this.intervals.get(index)[1] >= start) return -1; 
        }
        return l;
    }

    private void checkMergeIntervals(int index){
        if(index - 1 >= 0){
            if(this.intervals.get(index - 1)[0] <= this.intervals.get(index)[0] && this.intervals.get(index - 1)[1] + 1 == this.intervals.get(index)[1]){
                this.intervals.get(index - 1)[1] = this.intervals.get(index)[1];
                this.intervals.remove(index);
                index--;
            }
        }
        while(index + 1 < this.intervals.size()){
            if(this.intervals.get(index + 1)[0] <= this.intervals.get(index)[1] || this.intervals.get(index + 1)[0] == this.intervals.get(index)[1] + 1){
                this.intervals.get(index)[1] = Math.max(this.intervals.get(index + 1)[1], this.intervals.get(index)[1]);
                this.intervals.remove(index + 1);
            }else break;
        }
    }

    public void addNum(int value){
        int insertIndex = this.searchInsertIndex(value);
        if(insertIndex < 0) return;
        int[] temp = {value, value};
        this.intervals.add(insertIndex, temp);
        this.checkMergeIntervals(insertIndex);
    }

    public int[][] getIntervals(){
        int[][] out = new int[this.intervals.size()][2];
        for(int i = 0; i < this.intervals.size(); i++){
            out[i] = this.intervals.get(i);
        }
        return out;
    }
}


class solution{

    static void printIntervals(int[][] intervals){
        System.out.print("[ ");
        for(int index = 0; index < intervals.length; index++){
            int[] interval = intervals[index];
            System.out.print("[ ");
            for(int i = 0; i < interval.length; i++){
                System.out.print(interval[i]);
                if(i + 1 < interval.length) System.out.print(", ");
            }
            System.out.print(" ]");
            if(index + 1 < intervals.length) System.out.print(", ");
        }
        System.out.println(" ]");
    }

    public static void main(String[] args){

        SummaryRanges ranges = new SummaryRanges();
        ranges.addNum(1);
        printIntervals(ranges.getIntervals());
        ranges.addNum(3);
        printIntervals(ranges.getIntervals());
        ranges.addNum(7);
        printIntervals(ranges.getIntervals());
        ranges.addNum(2);
        printIntervals(ranges.getIntervals());
        ranges.addNum(6);
        printIntervals(ranges.getIntervals());
        ranges.addNum(8);
        printIntervals(ranges.getIntervals());
    }

}