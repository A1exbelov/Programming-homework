#include <iostream>
using namespace std;

struct stack   // Creating a stack structure
{
    int inf;
    stack *next;
};

void push(stack *&h, int x) // Function of adding an element to the stack
{ // вставка
    stack *r = new stack;
    r -> inf = x;
    r -> next = h;
    h = r;
}

char pop(stack *&h)  // Function of extracting an element from the stack
{
    int i = h -> inf;
    stack *r = h;
    h = h -> next;
    delete r;
    return i;
}

int main()
{
    char a, b;
    stack *head = NULL; // Initialize the pointer to the stack
    cout << "n = ";
    int n; cin >> n; int x;
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {  
        cin >> x;
        push(head, x);
    }
    stack *tempHead = NULL; // Pointer to a temporary stack
    int minim = 1e9, maxim = -1e9;
    for (int i = 0; i < n; ++i) { // Pass through the glass and find the maximum and minimum elements
        x = pop(head);
        if (x > maxim) maxim = x;
        if (x < minim) minim = x;
        push(tempHead, x);   // Adding all the elements to the temporary stack
    }
    int counter = n;
    for (int i = 0; i < n; ++i) {
        x = pop(tempHead);  // Getting the elements from the temporary stack
        if (x == maxim) {   // If we find the maximum element, then we insert the minimum in front of it
            push(head, minim);
            counter++;
        }
        push(head, x);  // Insert the element itself into place
    }
    for (int i = 0; i < counter; ++i) {  // The stack is ready, but for output we add two more cycles that turn it over
        x = pop(head);
        push(tempHead, x);
    }
    cout << "Result: ";
    for (int i = 0; i < counter; ++i) {
        x = pop(tempHead);
        cout << x << ' '; 
    }
}