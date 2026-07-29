

public class solution {
    
    public static String smallestPalindrome(String s){
        int[] char_count = new int[26];
        StringBuilder out = new StringBuilder();
        for(int i = 0; i < s.length(); i++){
            char_count[s.charAt(i) - 'a']++;
        }
        char middle_character = 'A';
        for(int i = 0; i < 26; i++){
            if(char_count[i] % 2 != 0){
                middle_character = (char) (i + 'a');
                char_count[i]--;
            }
            int used = 0;
            while(used < char_count[i]){
                out.append((char)(i + 'a'));
                used++;
                char_count[i]--;
            }
        }
        if(middle_character != 'A') out.append(middle_character);
        for(int i = 25; i >= 0; i--){
            while(char_count[i] > 0){
                out.append((char)(i + 'a'));
                char_count[i]--;
            }
        }
        return out.toString();
    }

    public static void main(String[] args){
        String temp  = "ssddcddss";
        System.out.println("Smallest lexicographically permutation of " + temp + " : " + smallestPalindrome(temp));
    }

}
