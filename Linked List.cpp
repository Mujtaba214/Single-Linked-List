#include <iostream>
using namespace std;

struct LLNode {
    int data;
    LLNode *next = NULL;
};

LLNode *list = NULL;

void insert() {
    LLNode *ptr = new LLNode();
    cout << "Insert a value: ";
    cin >> ptr->data;
    ptr->next = NULL;

    if (list == NULL) {
        list = ptr; 
    } else {
        LLNode *curr = list;
        while (curr->next != NULL) { 
            curr = curr->next;
        }
        curr->next = ptr; 
    }
}

void print() {
    LLNode *curr = list;
    if (curr == NULL) {
        cout << "no list";
    } else {
        while (curr != NULL) {
            cout << curr->data << " "; 
            curr = curr->next;
        }
    }
    cout << endl; 
}

int search(int tosearch)
{
    int count=0;
    LLNode *curr = list;
    while(curr!=NULL)
    {
        if(curr->data==tosearch)
        {
            cout<<"value found";
            count++;
            return 0;
        }
        curr=curr->next;
    }

        cout << "value not found";
        return -1;    
}

int main() {
    int searchVal;
    insert();
    insert();
    print();
    cout << "Enter the value you want to search: ";
    cin>>searchVal;
    search(searchVal);
    return 0;
}