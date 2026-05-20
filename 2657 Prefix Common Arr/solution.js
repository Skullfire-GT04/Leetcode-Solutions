const findThePrefixCommonArray = (A, B) => {
    let n = A.length;

    let i = 0;
    let common_count = 0;
    let seenA = {}, seenB = {};
    let out = []
    while(i < n){
        seenA[A[i]] = 1;
        seenB[B[i]] = 1;

        if(A[i] === B[i]){
            common_count++;
        }
        else{
            if(seenA[B[i]])common_count++;
            if(seenB[A[i]]) common_count++;
        }
        out.push(common_count);
        
        i++;
    }
    return out;
}


console.log(findThePrefixCommonArray([2, 3, 1], [3, 1, 2]));