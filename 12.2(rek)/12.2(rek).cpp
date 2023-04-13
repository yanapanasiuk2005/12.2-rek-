#include <iostream>
using namespace std;

typedef int Info;

struct Elem
{
    Elem* link;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
int dequeue(Elem*& first, Elem*& last);
void print(Elem* current);
bool is_sublist(Elem* L1current, Elem* L2current);

void enqueue(Elem*& first, Elem*& last, Info value)
{
    if (first == NULL) {
        first = new Elem;
        first->info = value;
        first->link = NULL;
        last = first;
    }
    else {
        last->link = new Elem;
        last = last->link;
        last->info = value;
        last->link = NULL;
    }
}

int dequeue(Elem*& first, Elem*& last)
{
    if (first == NULL) {
        return NULL;
    }
    else {
        Elem* tmp = first;
        Info value = first->info;
        first = first->link;
        if (first == NULL)
            last = NULL;
        delete tmp;
        return value;
    }
}

void print(Elem* current) {
    if (current != NULL) {
        cout << current->info << " ";
        print(current->link);
    }
    else {
        cout << endl;
    }
}

bool is_sublist(Elem* L1current, Elem* L2current) {
    if (L1current == NULL) {
        return true;
    }
    else if (L2current == NULL) {
        return false;
    }
    else if (L1current->info == L2current->info) {
        return is_sublist(L1current->link, L2current->link);
    }
    else {
        return is_sublist(L1current, L2current->link);
    }
}

int main()
{
    Elem* L2first = NULL,
        * L2last = NULL;

    for (int i = 1; i <= 10; i++)
    {
        enqueue(L2first, L2last, i);
    }

    cout << "L2: ";
    print(L2first);


    Elem* L1first = NULL,
        * L1last = NULL;

    for (int i = 4; i <= 8; i++)
    {
        enqueue(L1first, L1last, i);
    }

    cout << "L1: ";
    print(L1first);

    bool result = is_sublist(L1first, L2first);
    if (result == 1)
        cout << "yes";
    else
        cout << "no";

    while (L1first != NULL)
        dequeue(L1first, L1last);

    while (L2first != NULL)
        dequeue(L2first, L2last);


    return 0;
}

