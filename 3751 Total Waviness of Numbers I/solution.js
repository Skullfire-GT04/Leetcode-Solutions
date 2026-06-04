
const totalWaviness = (num1, num2) => {
    let total_waves = 0;
    for(let i = num1; i <= num2; i++){
        temp = String(i);
        for(let j = 0; j < temp.length; j++){
            if(j - 1 >= 0 && j + 1 < temp.length){
                let left_num = Number(temp[j - 1]);
                let right_num = Number(temp[j + 1]);
                if(temp[j] > left_num && temp[j] > right_num) {
                    total_waves++;
                }
                if(temp[j] < left_num && temp[j] < right_num) total_waves++;
            }
        }
    }
    return total_waves;
}


console.log(totalWaviness(5872, 5921));