#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct stack {  // Creating a stack structure
    int inf;
    stack *next;
};

void push_stack(stack *&h, int x) { // Function of adding an element to the stack
    stack *r = new stack;
    r -> inf = x;
    r -> next = h;
    h = r;
}

char pop_stack(stack *&h) {  // Function of extracting an element from the stack
    int i = h -> inf;
    stack *r = h;
    h = h -> next;
    delete r;
    return i;
}

struct queue { // Creating a queue structure
    int inf;
    queue *next;
};

void push_queue(queue *&h, queue *&t, int x) { // Function of adding an item to the queue
    queue *r = new queue; 
    r->inf = x;           
    r->next = NULL;       
    if (!h && !t) {       
        h = t = r;
    }
    else {
        t->next = r; 
        t = r;       
    }
}

int pop_queue(queue *&h, queue *&t) {  // Function of extracting an item from the queue
    int i = h->inf; 
    queue *r = h;      
    h = h->next;      
    if (!h) t = NULL;      
    delete r;          
    return i;          
}

void DFS(int x, int n, stack *&current, vector<vector<int>>& Gr, vector<int>& a) {
    a[x] = 1;                        // Marking the original vertex as visited
    push_stack(current, x);          // Adding the current vertex to the stack
    cout << x << ' ';               
    bool fl = false; int y;         
    while (current) {                
        x = current->inf;            // Extracting the value of the current vertex
        for (int i = 0; i < Gr[x].size(); ++i) {  // Pass through all the vertices adjacent to it
            if (a[Gr[x][i]] == 0) { 
                y = Gr[x][i];     
                fl = true;          
                break;               
            }
        }
        if (fl == true) {            // If there is an unprocessed new vertex
            a[y] = 1;                // Mark it visited
            push_stack(current, y); 
            cout << y << ' ';        
            fl = false;             
        }
        else pop_stack(current);     // Removing the last vertex from the queue
    }
    if (find(a.begin(), a.end(), 0) != a.end()) {  // If the result leaves unprocessed vertices
        for (int i = 0; i < n; ++i) {   // Find the first such vertex
            if (a[i] == 0) DFS(i, n, current, Gr, a);
        }
    }
}

void BFS(int x, int n, queue *&h, queue *&t, vector<vector<int>>& Gr, vector<int>& a) { 
    a[x] = 1;                 // Mark the first vertex visited
    push_queue(h, t, x);      // Adding it to the queue
    cout << x << ' ';         // Output the visited vertex
    int y;                    // Initializing a variable for new vertices
    while (h && t) {          // While the queue is not empty
        x = pop_queue(h, t);  // Extracting the head of the queue
        for (int i = 0; i < Gr[x].size(); ++i) {    // Pass through all the vertices adjacent to this
            if (a[Gr[x][i]] == 0) {                 // If one of the vertices is not visited
                y = Gr[x][i];                   
                a[y] = 1;                          
                push_queue(h, t, y);                // Adding it to the queue
                cout << y << ' ';                  
            }
        }
    }
    if (find(a.begin(), a.end(), 0) != a.end()) {   // If, as a result, some vertices remain unvisited
        for (int i = 0; i < n; ++i) {               // Finding an unvisited vertex
            if (a[i] == 0) BFS(i, n, h, t, Gr, a);  // We run BFS for it
        }
    }
}

int main() {
    int n; n = 7;         
    stack *current = NULL;  
    queue *h = NULL, *t = NULL; 
    vector<int> a(n);           // Vector for visited vertices
    vector<vector<int>> Gr (n); // Adjacency list
    int x; x = 0;           
    Gr[0] = {1, 2, 4, 5};  
    Gr[1] = {0, 3};
    Gr[2] = {0, 5};
    Gr[3] = {1};
    Gr[4] = {0, 6};
    Gr[5] = {0, 2, 6};
    Gr[6] = {4, 5};
    cout << "Example of Graph: " << endl;
    cout << "n = " << n << endl;
    cout << "root = " << x << endl;
    cout << "Adjacency list: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (auto c : Gr[i]) {
            cout << c << ' ';
        }
        cout << endl;
    }
    cout << endl << "RESULT " << endl;  
    cout << "DFS: "; 
    DFS(x, n, current, Gr, a);
    cout << endl;
    for (int i = 0; i < n; ++i) {  // Clearing the list of visited vertices
        a[i] = 0;
    }
    cout << "BFS: ";  
    BFS(x, n, h, t, Gr, a);
}