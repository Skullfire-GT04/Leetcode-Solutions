

const minElement = (nums) => {
    let len = nums.length;
    let curr_min = Number.MAX_SAFE_INTEGER;
    for(let i = 0; i < len; i++){
        let temp = String(nums[i]);
        let curr_num = 0;
        for(let ch of temp){
            curr_num += Number.parseInt(ch);
        }
        if(curr_num < curr_min) curr_min = curr_num;
    }
    return curr_min
}



console.log(minElement([1, 2, 3, 4]));
