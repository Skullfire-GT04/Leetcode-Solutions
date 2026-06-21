
const maxIceCream = (costs, coins) => {

    let min_val = costs[0];
    let max_val = costs[0];

    for(let cost of costs){
        if(cost < min_val) min_val = cost;
        if(cost > max_val) max_val = cost;
    }
    let temp = [];
    for(let i = min_val; i <= max_val; i++){
        temp.push(0);
    }

    for(let cost of costs){
        temp[cost - min_val]++;
    }
    
    let out = 0;
    for(let i = 0; i < temp.length; i++){
        if(coins - (i + min_val) < 0) break;

        for(let j = 0; j < temp[i]; j++){
            if(coins - (i + min_val) >= 0){
                out++;
                coins -= (i + min_val);
            }else break;
        }
    }
    

    return out;
}


let answer = maxIceCream([4,7,6,4,4,2,2,4,8,8], 41);
console.log(`Max number of ice creams : ${answer}`);