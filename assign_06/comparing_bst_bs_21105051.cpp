// I will be submitting my code in c++

// abhinav 
// ece 
// 21105051


#include<bits/stdc++.h>  // including all the header files once
using namespace std;  // using namespace for limiting scope of variables and std namespace for compiler to find common instructions


// since tree is not a predefined data-type like array , we will create a class for it

class Node{
public: // so that the content can be accessed outside class also
	int data;
	Node*left;
	Node*right;

	Node(int data){
		this->data = data;
		left=NULL;
		right=NULL;
	}
};


// in order to insert data in bst :
Node*insert_node(Node*root,int data){ // we will require the root as input to identify the tree
	if(root==NULL){
		Node*new_node = new Node(data); // creating a new node dynamically 
		root = new_node;
		return root;  // if root was NULL initially , this is the first node in tree so we make it root
	}

	if(data>root->data){  // if data of new node is greater than root , we will insert in right
		root->right=insert_node(root->right,data);
	}
	else if(data<root->data){    // if data of new node is less than root , we will insert in left
		root->left=insert_node(root->left,data);
	}
	else{return root;}


	return root; // returning root after insertion
}



// making a function to print the tree

void print_tree(Node*root){
	queue<Node*> q; // creating a queue containing pointers to nodes
	q.push(root) ; // pushing the root of tree into queue
	q.push(NULL);

	while(!q.empty()){
		Node*temp = q.front();  // taking the front node from queue  
		q.pop();  // removing the front elem

		if(temp==NULL){
			cout<<endl;
			if(!q.empty()){q.push(NULL);}  // pushing NULL for the last node in queue
		}
		else{
			cout<<temp->data<<" ";  // printing the node data
			// pushing the left and right node of the temp if they exist
			if(temp->left){q.push(temp->left);}
			if(temp->right){q.push(temp->right);}
		}
	}

}


// making a function to get minimum value in a Binary Search Tree

Node* min_value(Node* node){  // we can start from any node and find the minimum value in the subtree with this node as root 
	// but to find min in whole bst , root should be passed
	// minimum value will exist in left , so we will keep on going in left until it is NULL (doesn't exist)
	Node*current= node;  
	while(current&&current->left !=NULL){
		current=current->left;
	}
	return current;  // this node has no Left hence it is minimum in bst
}


// making a function to delete a node in bst

Node* delete_node(Node*root , int key){
	if(root==NULL){
		return root;
	}

	if(key < root->data){
		// recursive call on left subtree if key value is less than current node value
		root->left = delete_node(root->left,key);  
	}

	else if(key > root->data){
		// recursive call on right subtree if key value is greater than current node value
		root->right = delete_node(root->right , key);
	}

	else{
		if(root->left == NULL && root->right == NULL){  
			// if the required node is leaf , we can simply return NUll , since nothing else will be affected in bst
			return NULL;
		}

		else if(root->left == NULL){
			// if left is NULL , we need to shift the right child to the parent to current node 
			Node*temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			// if right is NULL , we need to shift the left child to the parent to current node
			Node*temp = root->left;
			free(root);
			return temp;
		}
 		// if node has both left and right children , we will need to find the minimum value in right child subtree and replace the current node with that value
		Node*temp = min_value(root->right);
		root->data = temp->data;
		root->right = delete_node(root->right , temp->data);
	}

	return root;  // returning root after deletion of required value
}



// function to print an array
void print_array(int arr[] , int n){ // taking array as input
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}	


int main(){
	    //Taking number of element in array as input
    int n;
    cout<<"\nEnter number elements in the ARRAY to form BST:";cin>>n;
    int arr[n];
    cout<<"\nEnter elements of the array to form BST:";
    //Taking elements of array as input
    for(int i=0;i<n;i++){cin>>arr[i];}
    //printing the array
    cout<<"\nArray:[";print_array(arr,n);cout<<"]";
    cout<<endl;

    //root is the top most node of Binary Search Tree
    Node*root=NULL;
    //Inserting element of the array in Binary Search Tree
    for(int i=0;i<n;i++){
        root=insert_node(root,arr[i]);
    }
    //Displaying Binary Search Tree using Level Order Traversal
    cout<<"\nBinary Search Tree using Level Order Traversal\n"<<endl;
    print_tree(root);

    //key is the data to be deleted from Binary Search Tree
    int key;
    cout<<"\nEnter data to be deleted from BST:";cin>>key;
    //deleting key from Binary Search Tree
    root=delete_node(root,key);
    //Displaying Binary Search Tree after deletion of key
    cout<<"\nBinary Search Tree after deleting:"<<key<<endl;
    cout<<endl;
    print_tree(root);
}



/*
If an array has n elements and all elements are inserted in binary
search tree than the tree has space complexity of O(n) and 
the array has also the space complexity of O(n)
*/


/*
	Abhinav Malhotra
	ECE
	21105051
*/