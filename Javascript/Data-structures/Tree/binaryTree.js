class TreeNode {
  constructor(value) {
    this.value = value;
    this.descendants = [];
  }
}

// create nodes with values
const abe = new TreeNode("Abe");
const homer = new TreeNode("Homer");
const bart = new TreeNode("Bart");
const lisa = new TreeNode("Lisa");
const maggie = new TreeNode("Maggie");

// associate root with is descendants
abe.descendants.push(homer);
homer.descendants.push(bart, lisa, maggie);

console.log(abe.descendants); // ['Homer', 'Bart', 'Lisa', 'Maggie']
console.log(homer.descendants); // ['Bart', 'Lisa', 'Maggie']
