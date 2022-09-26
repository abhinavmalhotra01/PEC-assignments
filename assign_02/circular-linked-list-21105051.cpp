// circular linked list



// Question -1 :
/* While traversing a single-circular linked list, which condition establishes that the traversing element/variable has reached the first element ?  */


/* answer --


/** while traversing the list we keep on iterating the list until we reach a node which is pointing to head, we have completed a loop in the list and have reached its' first element
// this node will be in the next pointer of the last node of the linear list and since, the list is circular in nature it will point to the first element

Hence , while traversing the linked list , as soon as our temp pointer starts pointing to the address of our head node (first element) , we haved reached the first element of the list
*/

/* The condition for it is :

// code :

node*temp = head -> next;
while(temp!=head){  // this the condition
temp=temp->next; }  // updating temp ptr so that it may reach to the desired node

// when temp comes out of the loop , it would be pointing to the head of the list

this condition keeps check that while traversing the list we have reached the first element again , since in a circular list, the last element will point to the head





 /*another way (tougher to implment) can be to create a visited array (as we do in graph theory)
 in this visited array we may map the linked list nodes with respect to index of the array and assign boolean values to the array elements , 
 we can keep on iterating on the list unless we encounter a node which has already been marked visited in the array - since we were iteratring the list linearly and encountered a node, which has been already visited means
 we have reached the first node, since after the linear traversal of the list , the last node will point to the head and head has already been visited
 
 // hence the condition 
 while( vis[i]!=false ){temp=temp->next;vis[i]=true;}
 finds the element which has been visited already and since, we reached it through linear traversal ,it is the start of the list(the first element from which, we began iterating the list)
 */



// Question -2 :
/* What are the practical applications of a circular linked list? (Try to find applications in your respective fields */
 
 
 /*
 Answer :

1. Implementaion of queue :
			   Useful for implementation of a queue. Unlike the standard implementation, 
			   we don’t need to maintain two-pointers for the front and rear if we use a circular linked list.
			   We can maintain a pointer to the last inserted node and the front can always be obtained as next of last

2. Advanced Data Structres: 
			   Circular Doubly Linked Lists are used for the implementation of advanced data structures like the Fibonacci Heap.

3. Snake mobile Game :
		      The circular linked list stores the x,y position of each point in the snake's body.
		      The head of the list is the snake's head.
		      The tail is its tail.
                      And the really nice property is that as we advance the head to a new position, the list wraps around because it is circular. This erases the tail, and leaves all other body parts as they are.
		      So we get the movement of the whole snake simply by adding a new head positio

4. Media Playe :
	        A media playlist that repeats endlessly where the “tail” song node would point to the first song in the CL

5. Multiplayer Games :
		      All the Players are kept in a Circular Linked List and the pointer keeps on moving forward as a player's chance ends.

6. Computer Networking :
                        Circular Linked List can also be used in computer networks for token scheduling 

7. Looping Playlist in youtube : 
				At the end of the playlist , it is linked to the head of the playlist and hence the loop continues..

*/

// thankyou

// Abhinav Malhotra
// ECE
// 21105051
