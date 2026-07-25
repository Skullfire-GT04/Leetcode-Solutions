

const searchInsert = (nums, target) => {
    let l = 0, r = nums.length;
    while(l <= r){
        let index = Math.floor((l + r) / 2);
        if(nums[index] === target) {
            return index;
        }
        else{
            if(nums[index] < target){
                l = index + 1;
            }else r = index - 1;
        }
    }
    
    return l;
}

console.log(searchInsert([1, 3], 2))