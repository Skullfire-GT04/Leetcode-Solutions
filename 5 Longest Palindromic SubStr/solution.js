
const longestPalindrome = (s) => {
    let palindrome_centers = [];
    let max_len = 1;
    for(let i = 0; i < s.length; i++){
        palindrome_centers.push([i]);
        if(i + 1 < s.length){
            if(s[i] === s[i + 1]){
                palindrome_centers.push([i, i + 1]);
                max_len = 2;
            }
        }
    }
    let new_accepted_len = max_len;        
    while(true){
        let index = 0;
        let found_one = false;
        while(index < palindrome_centers.length){
            let left = palindrome_centers[index][0] - 1;
            let right = palindrome_centers[index][palindrome_centers[index].length - 1] + 1;
            
            if(left >= 0 && right < s.length && s[left] === s[right]){
                palindrome_centers[index].unshift(left);
                palindrome_centers[index].push(right);
                found_one = true;
                new_accepted_len = Math.max(palindrome_centers[index].length, new_accepted_len);
            }
            index++;
        }
        palindrome_centers = palindrome_centers.filter((arr) => arr.length >= new_accepted_len - 1);
        if(!found_one) break;
    }
    let out = "";

    let index = 0;
    for(let i = 0; i < palindrome_centers.length; i++) if(palindrome_centers[i].length > palindrome_centers[index].length) index = i;

    for(let i = 0; i < palindrome_centers[index].length; i++){
        out += s[palindrome_centers[index][i]];
    }
    return out;
}

console.log(longestPalindrome("aaaaa"));