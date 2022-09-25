// I will be submitting the assignment in C++ code
// Doubly linked list to represent a family 

#include <bits/stdc++.h>
using namespace std;
#define int long long

// in order to create a new datatype to represent the nodes of the linked list
// i will be creating a class for the same

class family_node{
	// so that the objects of the class can be initiallized out of the class-- the properties will be declared public

public:
	string name; // to take the inout  of the name of the family member
	int age;	// to take age of the member as input
	family_node*next;	// in order to link the next node to the current node (to store the address pointer of the next node to the current node)
	family_node*prev;	// in order to link the prev node to the current node (to store the address pointer of the prev node to the current node)

	// creating a constructor for the objects 
	family_node(string name,int age){
		
		// to store the name and age , given by the user in the current object
		this->name=name;
		this->age=age;
		
		// initializing the prev and next poibnters to NULL - will be updating them in insertion function
		prev=NULL;
		next=NULL;
		
	}

};


// to insert new node at the tail of the linked list

void insert_member(family_node*&head,string name,int age){ // declaring it void so that we dont have to return anything and can simply append the new node
	family_node*temp=head; // inorder to traverse the list
	family_node*new_node = new family_node(name,age); // dynamically creating a new node and initiallizing it with the input values

	// to insert in an emty list
	// if the list is empty- head would be poiting to NULL
	if(temp==NULL){
		head=new_node; // now the head will point to the new_node
	}

	// other case-- inserting in an non-empty list
	else{
		while(temp->next!=NULL){
			temp=temp->next;  // in order to reach the tail of the linked list
		}
		// now temp will be pointing to the tail of the linked list

		temp->next = new_node; //to link the 2 nodes(tail,new_node)
		new_node->prev=temp; //  to link temp and new_node through prev pointer to maintain the doubly nature of the list

	}
}


// to insert the node at the beginning of the linked list

void insert_begin(family_node*&head,string name,int age){

	family_node*new_node= new family_node(name,age);  // dynamically creating a new node and inserting the input data in it

	// inserting a new node at the beginning means to insert it at the head
	
	new_node->next=head; // to insert the newnode at the starting, we need to put head at the next pointer of the new_node
	head->prev=new_node;  // to maintain the doubly nature of the list, new_node is linked to the prev pointer of the head
	head=new_node;  // updating the head pointer to new_node 

// now , new_node is the new head of our linked list
}


// to print the linked list from the head
void print_ll(family_node*head){
	
	family_node*temp=head; // using a temp pointer to traverse the linked list
	
	while(temp->next!=NULL){ // using temp->next inorder to avoid segmentation fault, and print the list in a better manner
		cout<<"{Name:"<<temp->name<<" Age:"<<temp->age<<"}"<<"<->";
		temp=temp->next;
	}

	if(temp->next==NULL){
		cout<<"{Name:"<<temp->name<<" Age:"<<temp->age<<"}";
	}

	cout<<endl;
}


// in order to print the linked list from tail(end of the ll)

void print_end(family_node*head){
	family_node*temp = head;  // using a temp pointer to traverse the linked list
	
	while(temp->next!=NULL){
		temp=temp->next; // to reach the tail of the linked list
	}

	while(temp->prev!=NULL){ // traversing through prev pointer to reach head fromn tail
		cout<<"{Name:"<<temp->name<<" Age:"<<temp->age<<"}"<<"<->";
		temp=temp->prev; // updating the temp pointer after every print
	}

	if(temp->prev==NULL){ // at head pointer
		cout<<"{Name:"<<temp->name<<" Age:"<<temp->age<<"}";
	}

	cout<<endl;
}


// to delete a node at any index (note: we are excluding the deletion of the last element(it will be dealt with later on))

void delete_i(family_node*head, int i){
	if(i==0){ // deleting the node at the first index (head of the ll)
		
		family_node*temp=head;
		head=temp->next; // assignning head to the 2nd element of the list
		head->prev=NULL;  // removing the link between the 2nd element and 1st node
		delete temp; // deleting the node dynamically to deallocate the memory
	}

	else{ // at any index , except for head and tail of the list
		family_node*temp = head;
		for(int j=0;j<i;j++){
			temp=temp->next; // to reach the ith node of the list
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		// removing the link between the immediate neighbours of the target node
		delete temp;
	}
}

// to delete the tail node of the list
void del_last(family_node*&head){
	family_node*temp = head; // temp pointer to traverse the ll
	while(temp->next!=NULL){
		temp=temp->next; // to reach the tail of the ll
	}
	// now the temp has reached tail of the ll
	temp->prev->next =NULL; // we just need to remove the address of the tail node from the next pointer of the second_last node
	delete temp; // deleting the tail dynamically 
}



// an example to use the linked list defined above-- source code

int32_t main(){

	family_node*head = NULL; // initializing an empty list

	cout<<"Enter the number of Family members: ";
	int family_size;
	cin>>family_size; // taking the input of the size of the family

	// to take input of the datas of the family members
	for(int i=0;i<family_size;i++){
		string name;
		int age;
		
		cout<<"Enter the name of the "<<i+1<<"th member ";
		cin>>name;
		cout<<"Enter the age of the "<<i+1<<"th member ";
		cin>>age;

		// inserting the data in the doubly family linked list
		insert_member(head,name,age); // inserting from end of the lost
	}
	cout<<endl;


	// printing the data of the family members in the form of a linked list
	cout<<"The Doubly Family linked list is :"<<endl;
	print_ll(head);

}
//Abhinav Malhotra //ECE // 21105051

// Bonus Question :
/*
Try to find a way to link the family members' doubly-linked list based on their relationship. (Is it possible?)

--

*In my opinion, in order to link the nodes with respect to the relation , we can take the relation as the input and while inserting a new node we
 may link the nodes wrt to the relation , in this view, a family graph might be created
	*another way can be to take the input in form of the levels of a family tree , ie, taking the input generation wise and inserting the nodes
	 in the list level wise as in an generic tree
		*another observation can be that the average age of one generation has to be  greater than its successors (although , this approach might have some exceptions)
*/		
