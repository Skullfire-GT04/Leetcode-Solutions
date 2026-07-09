const reverse = (x) => {
    let divisor = 1;
    let digits = [];
    let isNegative = x < 0;
    x = Math.abs(x);
    while(Math.trunc(x / divisor) > 0){
        digits.push(Math.trunc(x / divisor) % 10);
        divisor *= 10;
    }
    
    let reversedNum = Number(digits.join(""));
    if(isNegative) reversedNum = -reversedNum;
    if(reversedNum > 2 ** 31 - 1) reversedNum = 0;
    if(reversedNum < -(2 ** 31)) reversedNum = 0;
    return reversedNum;
}

console.log(reverse(12000));

