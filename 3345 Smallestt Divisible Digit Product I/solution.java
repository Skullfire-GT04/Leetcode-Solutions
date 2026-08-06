

class SmallestNumber{

    public static int getProductOfDigits(int num){
        String str_rpr = String.valueOf(num);
        int product = 1;
        for(int i = 0; i < str_rpr.length(); i++){
            product *= str_rpr.charAt(i) - '0';
        }
        return product;
    }

    public static int smallestNumber(int n, int t){
        int product = getProductOfDigits(n);
        int num = n;
        while(product % t != 0){
            product = getProductOfDigits(++num);
        }
        return num;
    }

    public static void main(String[] args){
        System.out.println(smallestNumber(15, 3));
    }
}