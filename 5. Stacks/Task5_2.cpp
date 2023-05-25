#include <iostream>
using namespace std;

struct queue
{
    int inf;
    queue *next;
};

void push(queue *&h, queue *&t, int x)
{
    queue *r = new queue; // Creating a new element
    r->inf = x;           // Fill in its information field
    r->next = NULL;       // Fill in the reference field
    if (!h && !t)
    {              // If the queue is empty
        h = t = r; // The head and tail refer to this new element r
    }
    else
    {
        t->next = r; // r will be the next element after the tail of t
        t = r;       // Transfer the tail pointer t to r
    }
}

int pop(queue *&h, queue *&t)
{
    int i = h->inf; // Value of the information field of the head h, i.e. the first element
    queue *r = h;      // Creating a pointer to the head
    h = h->next;       // Moving the pointer h to the next element
    if (!h)            // If h=NULL, i.e. there was one element in the queue
        t = NULL;     
    delete r;        
    return i;        
}

void result(queue *&h, queue *&t)
{
    queue *h_temp = NULL, *t_temp = NULL; // Initializing the temporary queue
    int x; int minim = 1e9;
    while (h && t)
    {                  // While the original queue is not empty
        x = pop(h, t); // Extracting an item from the queue
        if (x < minim) minim = x;
        push(h_temp, t_temp, x);
    }
    while (true) {  
        x = pop(h_temp, t_temp);  // Getting items from the temporary queue
        if (x == minim) break;   // If we find the minimum, then we exit the loop
        else push(h_temp, t_temp, x); // Add elements to the end of the same queue until the minimum one is found
    }
    push(h, t, minim);   // Adding the minimum element to the resulting queue
    while (h_temp && t_temp) {
        x = pop(h_temp, t_temp);  // Rewrite all other elements after the minimum
        push(h, t, x);
    }
}
int main()
{
    queue *h = NULL, *t = NULL;
    int n; cout << "n = "; cin >> n; 
    int x;
    cout << "Input elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;     
        push(h, t, x); // Add a number in queue
    }
    result(h, t);
    cout << "New queue\n";
    while (h && t)
        cout << pop(h, t) << " "; 
    return 0;
}