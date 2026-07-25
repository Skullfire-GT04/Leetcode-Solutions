

const maxProduct = (n) => {

    let string_num = String(n);
    let nums = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];

    for(let i = 0; i < string_num.length; i++){
        nums[Number(string_num.charAt(i))]++;
    }
    let first_index = 9;
    let second_index = 9;

    while(nums[first_index] < 1) first_index--;
    nums[first_index]--;
    while(nums[second_index] < 1) second_index--;
    return first_index * second_index;
}


console.log(maxProduct(31));