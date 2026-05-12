
const isPalindrome = (x) => {
    let str_rpr = String(x);
    let len = str_rpr.length;
    let left = 0, right = len - 1;
    while(str_rpr[left] == str_rpr[right] && left < right){
        left++;
        right--;
    }
    return (len % 2 === 0) ? left == right + 1 : left == right;
}

let a = 21
console.log(isPalindrome(a));