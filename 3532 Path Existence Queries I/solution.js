
const pathExistenceQueries = (n, nums, maxDiff, queries) => {

    let parents = [];
    for(let i = 0; i < n; i++){
        parents.push(i);
    }

    for(let i = 0; i < n - 1; i++){
        if(Math.abs(nums[i] - nums[i + 1]) <= maxDiff){
            parents[i + 1] = parents[i];
        }
    }
    console.log(parents);
    let out = []
    for(let query of queries){
        out.push(parents[query[0]] === parents[query[1]]);
    }
    return out;
}

console.log(pathExistenceQueries(4, [2, 5, 6, 8], 2, [[0, 1], [0, 2], [1, 3], [2, 3]]));