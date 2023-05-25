#include <iostream>
using namespace std;

struct list {
    int inf;
    list *next;
    list *prev;
};

void push(list *&h, list *&t, int x) { // Inserting an item at the end of the list
    list *r = new list; // Creating a new element
    r->inf = x; // Fill in the information field of the new element
    r->next = NULL; // Fill in the reference field of the new element
    if (!h && !t) { // If the list is empty
        r->prev = NULL; // r will be the first element
        h = r; // Head of p will refer to r
    }
    else {
        t->next = r; // Next one for the tail for the tail is r
        r->prev = t; // Previous element for r will be t
    }
    t = r; // Tail will point to k
}

void del_node(list *&h, list *&t, list *r) {  // Function removes the item referenced by reuters from the list
    if (r == h && r == t) // If there is one item in the list
        h = t = NULL;
    else if (r == h) { // if need to delete the first item in the list
        h = h->next; // then we shift the head h by one element
        h->prev = NULL;
    }
    else if (r == t) { // If we delete the last element
        t = t->prev; // Shift the tail one element to the left
        t->next = NULL;
    }
    else { // Case when the item being deleted is in the middle of the list
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}

void insert_after(list *&h, list *&t, list *r, int y) {
    list *p = new list; 
    p->inf = y;
    if (r == t) { // We insert after the tail
        p->next = NULL; 
        p->prev = r; 
        r->next = p;
        t = p; // now the tail - p
    }
    else {    // Insert it in the middle of the list
        r->next->prev = p; 
        p->next = r->next;
        p->prev = r; 
        r->next = p;
    }
}

void print(list *&h, list *&t) {  
    list *p = h; 
    while (p) { 
        cout << p->inf << " "; 
        p = p->next; 
    }
}

void result(list *&h, list *&t) {  
    list *p = h; // Pointer to the head
    while(p) {
        int srednee = 0; int counter = 0;
        list *k = p->next; // Saving the pointer to the next element
        list *j = p;
        while (j) {
            list *q = j->next;
            srednee += j->inf; counter++;
            j = q;
        }
        srednee = srednee/counter; 
        if (p->inf < srednee) del_node(h, t, p);
        p = k;
    }
}

int main() {
    int n, y;
    list *h = NULL; 
    list *t = NULL;
    cout << "n = ";
    cin >> n; 
    for (int i = 0; i < n; i++) { 
        cin >> y;
        push(h, t, y); 
    }
    result(h, t);
    print(h, t); 
}