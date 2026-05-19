
const maxArea = (height) => {
    let n = height.length, l = 0, r = n -1;
    let max_area = 0;
    while(l < r){
        max_area = Math.max(Math.min(height[l], height[r]) * (r - l), max_area);
        if(height[l] < height[r]) l++;
        else r--;
    }
    return max_area;
}

console.log(maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]))