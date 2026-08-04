var countRatioSubarrays = function(nums, a, b) {
    let odd_count = [], even_count = [];
    let odds = 0, evens = 0;
    for(let i = 0; i < nums.length; i++){
        if(nums[i] % 2 == 0){
            evens++;
        }else{
            odds++;
        }
        even_count.push(evens)
        odd_count.push(odds);
    }
    console.log(even_count, odd_count);
    let valids = 0;
    for(let i = 0; i < nums.length; i++){
        for(let j = i; j < nums.length; j++){
            let even = 0, odd = 0;
            if(i - 1 >= 0){
                even = even_count[j] - even_count[i - 1];
                odd = odd_count[j] - odd_count[i - 1];
            }else{
                even = even_count[j];
                odd = odd_count[j];
            }
            if(odd > 0 && even / odd <= a / b) valids++;
        }
    }
    return valids;
}

let nums = [2,2,1];
let a = 3, b = 1;

console.log(countRatioSubarrays(nums, a, b));