// I will be submitting this assignment in c++
// circular linked list



// Question -1 :
/* While traversing a single-circular linked list, which condition establishes that the traversing element/variable has reached the first element ?  */


/* answer --


/** while traversing the list we keep on iterating the list until we reach a node whose next pointer is head and hence, we reach a loop junction in the list 
// this node will be the last node of the linear list and since it is pointing to head, it is causing the loop in the list
hence we need to find the node which points to the head of the list i.e. while(temp->next!=head){temp=temp->next;}
once temp comes out of the loop , it will be at the last element and its next pointer would be pointing to head(first element)

all in all : We Know that in circular linked list last node of linked list points to head of that linked list,
hence we can check if any node points to head of linked list then that node is the end of circular linked list
*/

/* hence , the condition for it is :

"  while(temp->next!=head){  // this the condition
temp=temp->next; }  "  // updating temp ptr so that it may reach to the desired node

this condition keeps check that while traversing the list we have reached the first element again
since, in a circular linked list , the last node of the list points to the head of the linked list , so we check whether any node points to the 
head or not , the node which does so is the end of our list*/


 /*another way (tougher to implment) can be to create a visited array (as we do in graph theory)
 in this visited array we may map the linked list nodes with respect to index of the array and assign boolean values
 to the array elements , we can keep on iterating on the list unless we encounter a node which has already been marked 
 visited in the array - since we were iteratring the list linearly and encountered a  node, which has been already visited means
 we have reached a point in the list, at which, the circle is formed
 in this approach we will just finally end on the starting node itself and is independent of the state that whether that node is head or not
 // hence the condition :( vis[i]!=false ) finds the element which has been visited already and since, we reached it through linear traversal ,it is the start of the list(the first element from which, we began iterating the list)
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
