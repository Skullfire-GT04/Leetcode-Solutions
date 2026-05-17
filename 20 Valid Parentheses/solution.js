const isValid = (s) => {
    if(s.length % 2 !== 0) return false;
    let normal_open = 0, square_open = 0, curly_open = 0;
    let expected_closing = [];
    
    for(let i = 0; i < s.length; i++){
        switch(s[i]){
            case '(':
                normal_open++;
                expected_closing.push(")");
                break;
            case '[':
                square_open++;
                expected_closing.push("]");
                break;
            case '{':
                curly_open++;
                expected_closing.push('}');
                break;
            case ')':
                if(expected_closing.pop() !== ')') return false;
                break;
            case ']':
                if(expected_closing.pop() !== ']') return false;
                break;
            case '}':
                if(expected_closing.pop() !== '}') return false;
                break;
        }
    }
    return expected_closing.length === 0;
}

console.log(isValid("{([])}"))