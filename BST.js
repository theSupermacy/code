function Node(val) {
    this.data = val;
    this.left = null;
    this.right = null;
    this.count = 0;
}

function BST(options) {
    if (!options) options = {};
    this.root = null;
    this.limit = options.limit ? options.limit : 10000;
    this.count = 0;
    this.inorderTraverseArr = [];
}

function Heap() {
    this.length = 0;
    this.minHeap = [-1];
    this.maxHeap = [-1];
}

function inorderTraverse(node, self) {
    if (node) {
        inorderTraverse(node.left, self);
        for (var i = 0; i <= node.count; i++)
            self.inorderTraverseArr.push(node.data);
        inorderTraverse(node.right, self);
    } else return;
};
BST.prototype.print = function() {
    inorderTraverse(this.root, this);
    return this.inorderTraverseArr;
};
BST.prototype.consist = function(data) {
    if (!data) return {
        error: 'Give Some Data'
    }
    if (this.inorderTraverseArr.indexOf(data) > -1) return true;
    else return false;
}

BST.prototype.insert = function(data) {
    if (this.count > this.limit) return {
        error: 'limit exceeded'
    }
    if (data == null) return {
        error: 'No value Given'
    }
    var localVertices = new Node(data);
    var localRoot = this.root;

    if (localRoot == null) this.root = localVertices;
    else {
        while (1) {
            if (data > localRoot.data) {
                if (localRoot.right === null) {
                    localRoot.right = localVertices;
                    break;
                }
                localRoot = localRoot.right;
            } else if (data < localRoot.data) {
                if (localRoot.left === null) {
                    localRoot.left = localVertices;
                    break;
                }
                localRoot = localRoot.left;
            } else {
                localRoot.count++;
                break;
            }
        }
    }
    this.count++;
    return;
}
BST.prototype.getMax = function() {
    if (this.root == null) return {
        'error': 'No element in the Binary Search Tree'
    };
    var localRoot = this.root;
    var max;
    while (localRoot.right != null) {
        localRoot = localRoot.right;
    }
    max = localRoot.data;
    return max;
}

BST.prototype.getMin = function() {
    if (this.root == null) return {
        'error': 'No element in the Binary Search Tree'
    };
    var localRoot = this.root;
    var min;

    while (localRoot.left) {
        localRoot = localRoot.left;
    }
    min = localRoot.data;
    return min;
}
BST.prototype.getRoot = function() {
    return this.root
}

function insertHeap(data, self) {
    self.minHeap.push(data);
    self.length++;
    percup(self);
}
function _getMin(self){
  return self.minHeap[1];
}
function percup(self) {
    var length = self.length;
    var arr = self.minHeap;
    while(length>1){
      console.log(arr[length],arr[Math.floor(length/2)],'dekh raha hun  ');
      if(arr[length]>=arr[Math.floor(length/2)]) break;
      console.log('aaya main',length)
      var temp = arr[length];

      arr[length] = arr[Math.floor(length/2)];
      arr[Math.floor(length/2)]=temp;
      length = Math.floor(length/2);
    }
    self.minHeap=arr;
}
Heap.prototype.insert=function(data){
  if(!data) return {'error':'No Data is available to Insert'};
  insertHeap(data,this);
}
Heap.prototype.getMin=function(){
  console.log(this)
  return _getMin(this);
}
module.exports = Heap;
