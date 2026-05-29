

const longestCommonPrefix = (strs) => {
    let len = strs.length;
    if(len < 1) return "";

    let curr_prefix = strs[0];

    for(let i = 0; i < len; i++){
        let word_len = strs[i].length;
        let prefix_len = curr_prefix.length;
        let index = 0;
        while(index < word_len && index < prefix_len && curr_prefix[index] == strs[i][index]) index++;
        curr_prefix = strs[i].substring(0, index);
    }
    return curr_prefix;
}

console.log(longestCommonPrefix(["dog", "racecar", "car"]));

