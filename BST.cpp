#include<iostream>
using namespace std;
namespace bst{
struct node {
	int data;
	struct node* left;
	struct node* right;
};
class BST {
	struct node* root =NULL;
	public :
       		struct node* getRoot();
		void insert(int);
		int findMax();
		int findMin();
		void inorderTraverse(struct node*);
	private :
		BST(){
		root = NULL;
		}
};

struct node* BST::getRoot(){
	return root;
}
void BST::inorderTraverse(struct node* root){
	if(root!=NULL){
		inorderTraverse(root->left);
		cout<<root->data<<" ";
		inorderTraverse(root->right);
	}
}


void BST::insert(int data){
	struct node* test = new node();
	struct node* localRoot = root;
	test->data = data;
	test->right = NULL;
	test->left = NULL;
	if(root==NULL){
		root = test;
	}
	else
	{
		while(1){
			if(data > localRoot->data){
				localRoot= localRoot->right;
				if(localRoot==NULL) {
					localRoot = test;
					break;
				}
			}
			else if (data < localRoot->data){
				localRoot = localRoot->left;
				if(localRoot ==NULL){
					localRoot = test;
					break;
				}
			}
			else
				break;
		}
	}
return;
}

int BST::findMax(){
	struct node * testNode= root;
	while(testNode->right) testNode = testNode->right;
	return testNode->data;
}

int BST::findMin(){
	struct node * testNode = root;
	while(testNode->left) testNode = testNode->left;
	return testNode-> data;
}
}
