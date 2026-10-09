#include <iostream>
using namespace std;

class Node {
public:
    int id;
    string name, food;
    Node *next;

    Node(int i, string n, string f) {
        id = i;
        name = n;
        food = f;
        next = NULL;
    }
};

class FoodQueue {
    Node *front, *rear;
    int id = 1;

public:
    FoodQueue() {
        front = rear = NULL;
    }

    void placeOrder() {
        string name, food;

        cout << "Enter customer name: ";
        cin >> name;
        cout << "Enter food item: ";
        cin >> food;

        Node *n = new Node(id, name, food);

        if (rear == NULL)
            front = rear = n;
        else {
            rear->next = n;
            rear = n;
        }

        cout << "\nOrder placed successfully!";
        cout << "\nOrder ID: " << id++ << endl;
    }

    void deliverOrder() {
        if (front == NULL) {
            cout << "\nNo orders in the queue.\n";
            return;
        }

        Node *temp = front;

        cout << "\nDelivering Order";
        cout << "\nOrder ID: " << temp->id;
        cout << "\nCustomer: " << temp->name;
        cout << "\nFood Item: " << temp->food << endl;

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "\nNo pending orders.\n";
            return;
        }

        Node *temp = front;

        cout << "\n--- Pending Food Orders ---\n";

        while (temp != NULL) {
            cout << "Order ID: " << temp->id
                 << " | Customer: " << temp->name
                 << " | Food: " << temp->food << endl;
            temp = temp->next;
        }
    }

    void nextOrder() {
        if (front == NULL) {
            cout << "\nNo pending orders.\n";
            return;
        }

        cout << "\nNext Order";
        cout << "\nOrder ID: " << front->id;
        cout << "\nCustomer: " << front->name;
        cout << "\nFood Item: " << front->food << endl;
    }
};

int main() {
    FoodQueue q;
    int ch;

    do {
        cout << "\n===== FOOD DELIVERY ORDER QUEUE =====\n";
        cout << "1. Place Order\n";
        cout << "2. Deliver Order\n";
        cout << "3. Display Pending Orders\n";
        cout << "4. View Next Order\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1: q.placeOrder(); break;
        case 2: q.deliverOrder(); break;
        case 3: q.display(); break;
        case 4: q.nextOrder(); break;
        case 5: cout << "\nThank you!\n"; break;
        default: cout << "\nInvalid choice!\n";
        }
    } while (ch != 5);

    return 0;
}
