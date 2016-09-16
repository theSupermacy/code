var bst = require ('./BST');

var bstree= new bst();
bstree.insert(2);
bstree.insert(3);
bstree.insert(256);
bstree.insert(1);
bstree.insert(255);
bstree.insert(-1);
bstree.insert(-1222)

console.log(bstree.getMin());
