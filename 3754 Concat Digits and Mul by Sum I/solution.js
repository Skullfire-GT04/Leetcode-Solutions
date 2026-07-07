

const sumAndMultiply = (n) => {
    let string_rpr = String(n);
    let temp = "";
    let sum = 0;
    for(let i = 0; i < string_rpr.length; i++){
        let num = Number(string_rpr[i]);
        if(!num) continue;
        temp += String(num);
        sum += num;
    }
    let reversed = "";
    for(let i = 0; i < temp.length; i++){
        reversed += temp[i];
    }
    return Number(reversed) * sum;
}

console.log(sumAndMultiply(10000))