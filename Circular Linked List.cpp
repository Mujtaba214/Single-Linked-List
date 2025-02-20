#include <iostream>
#include <cstdlib> // For malloc() and free()
using namespace std;

struct LLNode {
    int data;
    LLNode *next;
};

LLNode *list = NULL;

void insert() {
    LLNode *ptr = (LLNode *)malloc(sizeof(LLNode)); 
    cout << "Insert a value: ";
    cin >> ptr->data;
    ptr->next = NULL;

    if (list == NULL) { 
        list = ptr; 
        ptr->next = list; 
    } else {
        LLNode *curr = list;
        while (curr->next != list) { 
            curr = curr->next;
        }
        curr->next = ptr; 
        ptr->next = list; 
    }
}

void print() {
    LLNode *curr = list;
    if (list == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    
    cout << "Circular List: ";
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != list); 
    cout << endl;
}

void search(int toSearch) {
    if (list == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    LLNode *curr = list;
    do {
        if (curr->data == toSearch) {
            cout << "Value " << toSearch << " found in the list." << endl;
            return;
        }
        curr = curr->next;
    } while (curr != list);

    cout << "Value " << toSearch << " not found in the list." << endl;
}

void deleteVal(int todel) {
    if (list == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    LLNode *curr = list, *prev = NULL;

    if (list->data == todel) {
        LLNode *temp = list;
        LLNode *last = list;

        while (last->next != list) {
            last = last->next;
        }
        
        if (list->next == list) { 
            list = NULL;
        } else {
            list = list->next; 
            last->next = list; 
        }
        free(temp);
        return;
    }

    while (curr->next != list) {
        if (curr->data == todel) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == todel) {
        prev->next = list;
        free(curr);
    }
}

int main() {
    insert();
    insert();
    insert();
    print();

    int searchVal;
    cout << "Enter value to search: ";
    cin >> searchVal;
    search(searchVal);

    int valToDelete;
    cout << "Enter value to delete: ";
    cin >> valToDelete;
    deleteVal(valToDelete);
    print();

    return 0;
}
