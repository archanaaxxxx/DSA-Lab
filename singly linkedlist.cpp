#include <iostream>
#include <cstdlib>
using namespace std;
struct node { 
    int data;
    node* next;
};
class LinkedList {
    node* head = NULL;
public:
    void insertAtBeginning(int val) 
    {
        node* newNode = (node*)malloc(sizeof(node)); 
        
        if (newNode == NULL)
         {
            cout << "Out of memory\n";
            return;
        }

        newNode->data = val;

        if (head == NULL) 
        {
            newNode->next = NULL;
            head = newNode;
        } 
        else 
        {
            newNode->next = head;
            head = newNode;
        }

        cout << "Inserted " << val << " at the beginning\n";
    }

    void display()
     {
        if (head == NULL)
         {
            cout << "List is empty\n";
            return;
        }

        node* temp = head;
        
        cout << "Elements in the list are: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
       }

    void insertAtPos(int pos, int val)
     {
        node* newNode = (node*)malloc(sizeof(node));
        if (newNode == NULL)
         {
            cout << "Out of memory\n";
            return;
        }

        newNode->data = val;

        node* temp = head;
        for (int i = 1; i <= pos - 1; i++)
         {
            temp = temp->next;
            if (temp == NULL) 
			{
                cout << "Invalid position\n";
                free(newNode);
                return;
            }
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Inserted " << val << " at pos " << pos << endl;
    }

    void deleteAtPos(int pos) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        node* temp = head;
        if (pos == 0) {
            head = head->next;
            cout << "Deleted " << temp->data << endl;
            free(temp);
            return;
        }
        node* prev = NULL;
        for (int i = 1; i <= pos; i++) {
            prev = temp;
            temp = temp->next;
           
            if (temp == NULL)
             {
                cout << "Invalid position\n";
                return;
            }
        }
        prev->next = temp->next;
        cout << "Deleted " << temp->data << endl;
        free(temp);
    }
};
int main() {
    int choice, val, pos;
    LinkedList list1;
    while (1) {
        cout << "\n -------- Linked List Menu -----------\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Display the list\n";
        cout << "3. Insert at specified position\n";
        cout << "4. Delete from specified position\n";
        cout << "5. Exit\n";
        cout << "--------------------------------------\n";
        cout << "Enter your choice:\t";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the data: ";
                cin >> val;
                list1.insertAtBeginning(val);
                break;
            case 2:
                list1.display();
                break;
            case 3:
                cout << "Enter the pos (starts at 0): ";
                cin >> pos;
                if (pos < 0) {
                    cout << "Invalid position\n";
                    break;
                }
                cout << "Enter the data: ";
                cin >> val;
                if (pos == 0)
                    list1.insertAtBeginning(val);
                else
                    list1.insertAtPos(pos, val);
                break;
            case 4:
                cout << "Enter the pos: ";
                cin >> pos;
                if (pos < 0) {
                    cout << "Invalid position\n";
                    break;
                }
                list1.deleteAtPos(pos);
                break;
            case 5:
                exit(0);
            default:
                cout << "Wrong choice\n";
        }
    }
    return 0;
}
