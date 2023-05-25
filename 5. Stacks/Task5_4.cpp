#include <iostream>
using namespace std;

struct stack   // Creating a stack structure
{
    char inf;
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
{ // удаление
    char i = h -> inf;
    stack *r = h;
    h = h -> next;
    delete r;
    return i;
}
bool isVowel(char c) {  // Function defining vowels
    if (c=='a' || c=='e' || c=='o' || c=='u' || c=='i' || c=='y') return true;
    else return false;
}

int main()
{
    char a, b;
    stack *head = NULL;                // Initialize the pointer to the stack
    cout << "n = ";
    int n; cin >> n; char x;
    cout << "Enter letters: \n";
    for (int i = 0; i < n; ++i) {  
        cin >> x;
        push(head, x);
    }
    stack *vowelsHead = NULL; int counter_vow = 0;  // Pointer to the stack of vowels + counter
    stack *consonantsHead = NULL; int counter_con = 0; // Pointer to stack consonants + counter
    for (int i = 0; i < n; ++i) {
        x = pop(head);  // Taking out the elements from the main stack
        if (isVowel(x)) { push(vowelsHead, x); counter_vow++; } // Distribute them along the walls of vowels and consonants
        else { push(consonantsHead, x); counter_con++; }
    }
    for (int i = 0; i < counter_vow; ++i) {
        x = pop(vowelsHead); // Adding all vowels to the resulting stack
        push(head, x);
    }
    for (int i = 0; i < counter_con; ++i) {
        x = pop(consonantsHead); // Adding all consonants to the resulting stack
        push(head, x);
    }
    stack *tempHead = NULL;
    for (int i = 0; i < n; ++i) {  // Turning the steak over for correct output
        x = pop(head);
        push(tempHead, x);
    }
    cout << "Result: ";
    for (int i = 0; i < n; ++i) {
        x = pop(tempHead);
        cout << x << ' '; 
    }
}