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
    int x; int maxim = -1e9; int odd = 0;
    while (h && t)
    {                  // While the original queue is not empty
        x = pop(h, t); // Extracting an item from the queue
        if (x > maxim) maxim = x;  // Find the max number
        if (x%2 == 1) odd = x;   // Find the last number
        push(h_temp, t_temp, x);  // Add numbers in temporary queue
    }
    bool flag = 0;
    while (h_temp && t_temp) {  // While temporary queue is not empty
        x = pop(h_temp, t_temp);
        push(h, t, x); 
        if (x == maxim) { // If the current element is the maximum, then after it we also insert the minimum
            push(h, t, odd);
        }
    }
}
int main()
{
    queue *h = NULL, *t = NULL; // Initializing the queue
    int n; cout << "n = "; cin >> n; 
    int x;
    cout << "Input elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;     
        push(h, t, x); // Add a number in queue
    }
    // Calling a function that changes the queue according to the task
    result(h, t);
    cout << "New queue\n";
    while (h && t)               
        cout << pop(h, t) << " ";
    return 0;
}