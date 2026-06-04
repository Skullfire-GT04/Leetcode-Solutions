const uniquePaths = (m, n) => {
    let dp = [];
    for(let i = 0; i < m; i++){
        let temp = [];
        for(let j = 0; j < n; j++){
            temp.push(0);
        }
        dp.push(temp);
    }
    dp[0][0] = 1;
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(j - 1 >= 0) dp[i][j] += dp[i][j - 1];
            if(i - 1 >= 0) dp[i][j] += dp[i - 1][j];
        }
    }
    return dp[m - 1][n - 1];
}

console.log(uniquePaths(3, 2));