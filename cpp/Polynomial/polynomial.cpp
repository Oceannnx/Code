// // C++ implementation of the above approach
// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// // Node structure containing powerer
// // and coefficient of variable
// struct Node {
// 	int coeff, power;
// 	Node* next;
// };

// // Function add a new node at the end of list
// Node* addnode(Node* start, int coeff, int power)
// {
// 	// Create a new node
// 	Node* newnode = new Node;
// 	// newnode->coeff = coeff;
// 	newnode->power = power;
// 	newnode->next = NULL;

// 	// If linked list is empty
// 	if (start == NULL)
// 		return newnode;

// 	// If linked list has nodes
// 	Node* ptr = start;
// 	while (ptr->next != NULL)
// 		ptr = ptr->next;
// 	ptr->next = newnode;

// 	return start;
// }

// // Function To Display The Linked list
// void printList(struct Node* ptr)
// {
// 	while (ptr->next != NULL) {
// 		cout << ptr->coeff << "x^" << ptr->power ;
// 	if( ptr->next!=NULL && ptr->next->coeff >=0)
// 		cout << "+";

// 		ptr = ptr->next;
// 	}
// 	cout << ptr->coeff << "\n";
// }

// // Function to add coefficients of
// // two elements having same powerer
// void removeDuplicates(Node* start)
// {
// 	Node *ptr1, *ptr2, *dup;
// 	ptr1 = start;

// 	/* Pick elements one by one */
// 	while (ptr1 != NULL && ptr1->next != NULL) {
// 		ptr2 = ptr1;

// 		// Compare the picked element
// 		// with rest of the elements
// 		while (ptr2->next != NULL) {

// 			// If powerer of two elements are same
// 			if (ptr1->power == ptr2->next->power) {

// 				// Add their coefficients and put it in 1st element
// 				ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
// 				dup = ptr2->next;
// 				ptr2->next = ptr2->next->next;

// 				// remove the 2nd element
// 				delete (dup);
// 			}
// 			else
// 				ptr2 = ptr2->next;
// 		}
// 		ptr1 = ptr1->next;
// 	}
// }

// Node* polyadd(Node* poly1, Node* poly2)
// {
//     Node* result = NULL;
//     Node* temp, *prev = NULL;

//     while (poly1 != NULL && poly2 != NULL) {
//         if (poly1->power == poly2->power) {
//             int coeff = poly1->coeff + poly2->coeff;
//             if (coeff != 0) {
//                 temp = addnode(NULL, coeff, poly1->power);
//                 if (prev == NULL)
//                     result = temp;
//                 else
//                     prev->next = temp;
//                 prev = temp;
//             }
//             poly1 = poly1->next;
//             poly2 = poly2->next;
//         }
//         else if (poly1->power > poly2->power) {
//             temp = addnode(NULL, poly1->coeff, poly1->power);
//             if (prev == NULL)
//                 result = temp;
//             else
//                 prev->next = temp;
//             prev = temp;
//             poly1 = poly1->next;
//         }
//         else {
//             temp = addnode(NULL, poly2->coeff, poly2->power);
//             if (prev == NULL)
//                 result = temp;
//             else
//                 prev->next = temp;
//             prev = temp;
//             poly2 = poly2->next;
//         }
//     }

//     // Add remaining elements of poly1 to result
//     while (poly1 != NULL) {
//         temp = addnode(NULL, poly1->coeff, poly1->power);
//         if (prev == NULL)
//             result = temp;
//         else
//             prev->next = temp;
//         prev = temp;
//         poly1 = poly1->next;
//     }

//     // Add remaining elements of poly2 to result
//     while (poly2 != NULL) {
//         temp = addnode(NULL, poly2->coeff, poly2->power);
//         if (prev == NULL)
//             result = temp;
//         else
//             prev->next = temp;
//         prev = temp;
//         poly2 = poly2->next;
//     }

//     // Remove any duplicates in the result
//     removeDuplicates(result);

//     return result;
// }

// // Function two Multiply two polynomial Numbers
// Node* multiply(Node* poly1, Node* poly2,
// 			Node* poly3)
// {

// 	// Create two pointer and store the
// 	// address of 1st and 2nd polynomials
// 	Node *ptr1, *ptr2;
// 	ptr1 = poly1;
// 	ptr2 = poly2;
// 	while (ptr1 != NULL) {
// 		while (ptr2 != NULL) {
// 			int coeff, power;

// 			// Multiply the coefficient of both
// 			// polynomials and store it in coeff
// 			coeff = ptr1->coeff * ptr2->coeff;

// 			// Add the powerer of both polynomials
// 			// and store it in power
// 			power = ptr1->power + ptr2->power;

// 			// Invoke addnode function to create
// 			// a newnode by passing three parameters
// 			poly3 = addnode(poly3, coeff, power);

// 			// move the pointer of 2nd polynomial
// 			// two get its next term
// 			ptr2 = ptr2->next;
// 		}

// 		// Move the 2nd pointer to the
// 		// starting point of 2nd polynomial
// 		ptr2 = poly2;

// 		// move the pointer of 1st polynomial
// 		ptr1 = ptr1->next;
// 	}

// 	// this function will be invoke to add
// 	// the coefficient of the elements
// 	// having same powerer from the resultant linked list
// 	removeDuplicates(poly3);
// 	return poly3;
// }

// // Driver Code
// int main()
// {
// 	Node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

//     int choice, coefficient, power;

//     cout << "Enter polynomial 1 : ";
//     cin >> choice;
//     for(int i = 0; i <choice; i++){
//         cout << "Enter coefficient : ";
//         cin >> coefficient;
//         cout << "Enter power : ";
//         cin >> power;
//         poly1 = addnode(poly1, coefficient, power);
//     }
//     cout << "Enter polynomial 2 : ";
//     cin >> choice;
//     for(int i = 0; i <choice; i++){
//         cout << "Enter coefficient : ";
//         cin >> coefficient;
//         cout << "Enter power : ";
//         cin >> power;
//         poly2 = addnode(poly2, coefficient, power);
//     }

// 	// poly1 = addnode(poly1, 3, 3);
// 	// poly1 = addnode(poly1, 6, 1);
// 	// poly1 = addnode(poly1, -9, 0);

// 	// poly2 = addnode(poly2, 9, 3);
// 	// poly2 = addnode(poly2, -8, 2);
// 	// poly2 = addnode(poly2, 7, 1);
// 	// poly2 = addnode(poly2, 2, 0);

// 	// Displaying 1st polynomial
// 	cout << "1st Polynomial:- ";
// 	printList(poly1);

// 	// Displaying 2nd polynomial
// 	cout << "2nd Polynomial:- ";
// 	printList(poly2);

// 	// calling multiply function

// 	// Displaying Resultant Polynomial
// 	cout << "Resultant add Polynomial:- ";
// 	printList(polyadd(poly1, poly2));
//     cout << "Resultant multi Polynomial:- ";
// 	printList(multiply(poly1, poly2, poly3));

// 	return 0;
// }
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node
{
    int coeff, power;
    Node *next;
};

Node *addnode(Node *start, int coeff, int power)
{
    Node *newnode = new Node;
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->next = NULL;

    if (start == NULL)
        return newnode;

    Node *ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;

    return start;
}

void printList(struct Node *ptr)
{
    while (ptr->next != NULL)
    {
        cout << ptr->coeff << "x^" << ptr->power;
        if (ptr->next != NULL && ptr->next->coeff >= 0)
            cout << "+";

        ptr = ptr->next;
    }
    cout << ptr->coeff << "\n";
}

void removeDuplicates(Node *start)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        while (ptr2->next != NULL)
        {

            if (ptr1->power == ptr2->next->power)
            {

                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;

                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

Node *polyadd(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    Node *temp, *prev = NULL;

    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->power == poly2->power)
        {
            int coeff = poly1->coeff + poly2->coeff;
            if (coeff != 0)
            {
                temp = addnode(NULL, coeff, poly1->power);
                if (prev == NULL)
                    result = temp;
                else
                    prev->next = temp;
                prev = temp;
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->power > poly2->power)
        {
            temp = addnode(NULL, poly1->coeff, poly1->power);
            if (prev == NULL)
                result = temp;
            else
                prev->next = temp;
            prev = temp;
            poly1 = poly1->next;
        }
        else
        {
            temp = addnode(NULL, poly2->coeff, poly2->power);
            if (prev == NULL)
                result = temp;
            else
                prev->next = temp;
            prev = temp;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL)
    {
        temp = addnode(NULL, poly1->coeff, poly1->power);
        if (prev == NULL)
            result = temp;
        else
            prev->next = temp;
        prev = temp;
        poly1 = poly1->next;
    }

    while (poly2 != NULL)
    {
        temp = addnode(NULL, poly2->coeff, poly2->power);
        if (prev == NULL)
            result = temp;
        else
            prev->next = temp;
        prev = temp;
        poly2 = poly2->next;
    }

    removeDuplicates(result);

    return result;
}

Node *multiply(Node *poly1, Node *poly2,
               Node *poly3)
{

    Node *ptr1, *ptr2;
    ptr1 = poly1;
    ptr2 = poly2;
    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            int coeff, power;

            coeff = ptr1->coeff * ptr2->coeff;

            power = ptr1->power + ptr2->power;

            poly3 = addnode(poly3, coeff, power);

            ptr2 = ptr2->next;
        }

        ptr2 = poly2;

        ptr1 = ptr1->next;
    }

    removeDuplicates(poly3);
    return poly3;
}

int main()
{
    Node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

    int choice, coefficient, power;

    cout << "Enter polynomial 1 : ";
    cin >> choice;
    for (int i = 0; i < choice; i++)
    {
        cout << "Enter coefficient : ";
        cin >> coefficient;
        cout << "Enter power : ";
        cin >> power;
        poly1 = addnode(poly1, coefficient, power);
    }
    cout << "Enter polynomial 2 : ";
    cin >> choice;
    for (int i = 0; i < choice; i++)
    {
        cout << "Enter coefficient : ";
        cin >> coefficient;
        cout << "Enter power : ";
        cin >> power;
        poly2 = addnode(poly2, coefficient, power);
    }

    cout << "1st Polynomial : ";
    printList(poly1);

    cout << "2nd Polynomial :  ";
    printList(poly2);

    cout << "Result of add Polynomial : ";
    printList(polyadd(poly1, poly2));
    cout << "Result of multi Polynomial : ";
    printList(multiply(poly1, poly2, poly3));

    return 0;
}