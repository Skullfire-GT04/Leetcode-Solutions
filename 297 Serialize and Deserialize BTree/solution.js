

class TreeNode{
    constructor(val){
        this.val = val;
        this.left = this.right = null;
    }
}



const serialize = (root) => {
    let nodes = [];
    let parents = [];
    let left_right_map = [];
    let out = "";
    let index = 0;
    nodes.push(root);
    parents.push(-1);
    left_right_map.push('l');
    while(nodes.length){
        let curr_node = nodes.splice(0, 1)[0];
        let parent = parents.splice(0, 1)[0];
        let rl_map = left_right_map.splice(0, 1)[0];
        out += String(curr_node.val);
        out += ";";
        out += String(parent);
        out += ";"
        out += rl_map;

        if(curr_node.left){
            nodes.push(curr_node.left);
            parents.push(index);
            left_right_map.push('l');
        }
        if(curr_node.right){
            nodes.push(curr_node.right);
            parents.push(index);
            left_right_map.push('r');
        }

        if(nodes.length) out += ","
        index++;
    }
    return out;
}

const deserialize = (data) => {
    let index = 0;
    let nodes = [];
    
    while(index < data.length){
        let val_start_index = index;
        while(index < data.length && data[index] != ';') index++;
        let val = Number(data.slice(val_start_index, index));
        index++;
        let parent_start_index = index;
        while(index < data.length && data[index] != ';') index++;
        let parent = Number(data.slice(parent_start_index, index));
        index++;
        let rl_map = data[index];
        while(index < data.length && data[index] != ',') index++;
        index++;

        let curr_node = new TreeNode(val);
        nodes.push(curr_node);
        if(parent >= 0){
            let parent_node = nodes[parent];
            if(rl_map == 'l'){
                parent_node.left = curr_node;
            }else{
                parent_node.right = curr_node;
            }
        }
    }
    return nodes[0];
}

let a = new TreeNode(1);
let b = new TreeNode(2);
let c = new TreeNode(3);
let d = new TreeNode(4);
let e = new TreeNode(5);
a.left = b;
a.right = c;
c.left = d;
c.right = e;

console.log(a);
console.log(deserialize(serialize(a)))
