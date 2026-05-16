
const findMin = (nums) => {
    let i = 0;
    while(i < nums.length - 1){
        if(nums[i] > nums[i + 1]) return nums[i + 1];
        i++;
    }
    return Math.min(nums[0], nums[nums.length - 1]);
}

let nums = [1, 1, 3];
console.log(findMin(nums));