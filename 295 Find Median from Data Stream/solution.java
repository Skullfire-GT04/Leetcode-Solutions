import java.util.ArrayList;


    
class MedianFinder{

    ArrayList<Integer> nums;

    public MedianFinder(){
        this.nums = new ArrayList<>();
    }

    public void addNum(int num){
        if(this.nums.isEmpty()){
            this.nums.add(num);
            return;
        }
        int l = 0, r = this.nums.size() - 1;
        while(l <= r){
            int index = (l + r) / 2;
            if(this.nums.get(index) < num) l = index + 1;
            else if(this.nums.get(index) > num) r = index - 1;
            else{
                this.nums.add(index, num);
                return;
            }
        }
        this.nums.add(l, num);
    }

    public double findMedian(){
        double out = 0;
        if(this.nums.size() % 2 != 0){
            out += this.nums.get((int) (this.nums.size() / 2));
        }
        else{
            int index = this.nums.size() / 2;
            out += this.nums.get(index);
            out += this.nums.get(index - 1);
            out /= 2;
        }
        return out;
    }
};


class solution{

    public static void main(String[] args) {
        MedianFinder finder = new MedianFinder();
        finder.addNum(-1);
        System.out.println(finder.findMedian());
        finder.addNum(-2);
        System.out.println(finder.findMedian());
        finder.addNum(3);
        System.out.println(finder.findMedian());
    }
}

