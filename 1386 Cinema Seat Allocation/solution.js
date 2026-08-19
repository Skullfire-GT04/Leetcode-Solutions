

const maxNumberOfFamilies = (n, reservedSeats) => {

    let seat_map = new Object();
    let count = 0;
    for(let seat of reservedSeats){
        if(!((seat[0] - 1) in seat_map)){
            seat_map[seat[0] - 1] = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
            count++;
        }
        seat_map[seat[0] - 1][seat[1] - 1] = 1;
    }
    let out = (n - count) * 2;
    for(let row in seat_map){
        let row_info = seat_map[row];
        if(!row_info[1] && !row_info[2] && !row_info[3] && !row_info[4]){
            out++;
            if(!row_info[5] && !row_info[6] && !row_info[7] && !row_info[8]) out++;
        }else{
            if(!row_info[3] && !row_info[4] && !row_info[5] && !row_info[6]) out++;
            else{
                if(!row_info[5] && !row_info[6] && !row_info[7] && !row_info[8]) out++;
            }
        }
    }
    return out;
};


let reservedSeats = [[1,6],[1,8],[1,3],[2,3],[1,10],[1,2],[1,5],[2,2],[2,4],[2,10],[1,7],[2,5]];
let n = 2;
console.log(maxNumberOfFamilies(n, reservedSeats));