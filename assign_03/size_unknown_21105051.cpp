// to apply linear and binary seach in an array whose size is unknown

/* Name - Abhinav
   SID - 21105051
   Branch - ECE
*/

// i will be  submitting the code in c++

#include<bits/stdc++.h>
using namespace std;
#define int long  long
#define intmax 1000000

// LINEAR SEARCH 

/* in case of linear search , the element must be present in the array
or we might end up in infinite loop (otherwise , the function can also return a garbage value)
however, in case of linked list , this is not the case , since we will terminate the loop with the (temp->next == NULL) condition */


// function to implement the linear search

int linear_search(int arr[] , int z){ // we can also pass array pointer (int*arr)
	// z is the element which needs to be searched

	int j=0;  // considering zero-based indexing 
	while(true){
		if(arr[j]==z){
			return j;
		}
		j++;
	}
}

// BINARY SEARCH

/* bianry search works only on sorted array ( whether increasing or decreasing ) */
/* In the given problem , since the size is unknown , we cant know the right(max_index) value for the search 
In order to solve this problem, we will use a modified binary search 

Firstly , we will find an index i such that k < A[i] and then do binary search from 0 to i
Now, since A[i] > k and all elements above i will be greater than or equal to A[i] hence there is zero possibility that k will be founded there

To implement this , initially we will set left = 0 and right = 1
now if k > A[right]  // means we need to go further than right index to find greater values (and potentially k)
right = right*2 // double the search range 
and now we can do normal binary search on arr[left] to arr[right] to find element k*/


// code for normal binary search :

int binary_search_normal ( int arr[] , int z , int left , int right){
	
	int mid = (left+right)/2;  // mid variable to implement binary search

	while(left<=right){
		if(arr[mid] > z)  // this means z lies to the left of mid
		{
			right = mid - 1;  // reducing our search space
			mid = (left + right)/2;  // updating mid 
		}

		else if(arr[mid] < z)
		{
			left = mid + 1;  // reducing our search space 
			mid = (left + right)/2;  // updating mid
		}
		else
		{
			return mid;  // thjis means that the value has been found so we simply return it
		}
	}
}

// implementation of the above mention approach for the given problem
int binary_search(int arr[] , int z){
	int left = 0;
	int right = 1;

	while(arr[right] < z)  // z lies to right side of our current right pointer
	{
		left = right ;  // updating left pointer since , z will lie above it for the given condition
		right = right * 2;  // doubles the range of our search by updating the right
	}
	// now we have desired / optimal values for left and right 

	return binary_search_normal(arr , z , left , right ) ; // calling normal binary search on the required part of the array
}

int32_t main(){

	int *arr = new int[intmax] ; // dynamically creating the array , since we dont know its' size which is essential for static creation

	int size ;
	cout<<"Enter the number of elements in the array : "<<endl;
	cin>>size;

	cout<<"Enter the elements of the array : "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}

	int z ; // the element which we will be searching
	cout<< "Enter the element you want to search : "<<endl;
	cin>>z;

	char decide ; // to decide whether to do linear or binary search 

	cout<<" Choose the type of search you want to do (linear(L) or binary(B) ) : " <<endl;
	cin>>decide;

	/* Firstly , finding whether the element is present in array or not ( garbage or inf loops will return different values in linear and binary search) */
	int index_linear = linear_search(arr,z);
	int index_binary = binary_search(arr,z);

	if(index_binary!=index_linear)
	{
		cout<<"Element is not present in the array"<<endl;
	}

	else
	{

		// note ::: we are considering zero based indexing 

		
	if(decide=='L'){
		cout<<"OK ! We will do linear search on the array "<<endl;

		cout<<" Index of "<< z << " in the given array is : "<<index_linear<<endl;
	}
	else if (decide=='B'){
		cout<<"OK ! We will do binary search on the array "<<endl;

		cout<<" Index of "<<z<< " in the given array is : "<<index_binary<<endl;
	}
	else {
		cout<<" Please enter valid options :"<<endl;
		cout<< " L for lineary search"<<endl;
		cout<< " B for binary search"<<endl;
	}
    }

// deallocating the dynamically allocated array 
	delete[] arr;
}
