
const romanToInt = (s) => {
    let obj_mapping = {
        'I' : 1,
        'V' : 5,
        'X' : 10,
        'L' : 50,
        'C' : 100,
        'D' : 500,
        'M' : 1000
    }

    let vals = [1000, 500, 100, 50, 10, 5, 1];
    let last_seen_val = 1001;
    let i = 0, n = s.length;
    let out = 0;
    while(i < n){
        if(obj_mapping[s[i]] < last_seen_val){
            if(i + 1 < n && obj_mapping[s[i + 1]] > obj_mapping[s[i]]){
                out += obj_mapping[s[i + 1]] - obj_mapping[s[i]];
                i += 2;
                continue;
            }else{
                out += obj_mapping[s[i]];
                last_seen_val = obj_mapping[s[i]];
            }
        }else out += last_seen_val;
        i++;
    }
    return out;
}

console.log(romanToInt(
 "IV"
));