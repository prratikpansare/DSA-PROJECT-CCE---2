#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Node {
public:
    int id;
    string name, food;
    int quantity;
    float price, total;
    Node *next;

    Node(int i, string n, string f, int q, float p) {
        id = i;
        name = n;
        food = f;
        quantity = q;
        price = p;
        total = quantity * price;
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

    void generateBill(Node *n) {
        cout << fixed << setprecision(2);

        cout << "\n========== FOOD DELIVERY BILL ==========\n";
        cout << "Order ID       : " << n->id << endl;
        cout << "Customer Name  : " << n->name << endl;
        cout << "Food Item      : " << n->food << endl;
        cout << "Quantity       : " << n->quantity << endl;
        cout << "Price per Item : Rs. " << n->price << endl;
        cout << "----------------------------------------\n";
        cout << "Total Amount   : Rs. " << n->total << endl;
        cout << "========================================\n";
        cout << "Thank you for your order!\n";
    }

    void placeOrder() {
        string name, food;
        int quantity;
        float price;

        cout << "Enter customer name: ";
        cin >> name;

        cout << "Enter food item: ";
        cin >> food;

        cout << "Enter quantity: ";
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Quantity must be greater than zero!\n";
            return;
        }

        cout << "Enter price per item: Rs. ";
        cin >> price;

        if (price < 0) {
            cout << "Price cannot be negative!\n";
            return;
        }

        Node *n = new Node(id, name, food, quantity, price);

        if (rear == NULL)
            front = rear = n;
        else {
            rear->next = n;
            rear = n;
        }

        cout << "\nOrder placed successfully!";
        cout << "\nOrder ID: " << id << endl;

        generateBill(n);

        id++;
    }

    void deliverOrder() {
        if (front == NULL) {
            cout << "\nNo orders in the queue.\n";
            return;
        }

        Node *temp = front;

        cout << "\n========== DELIVERING ORDER ==========\n";
        cout << "Order ID   : " << temp->id << endl;
        cout << "Customer   : " << temp->name << endl;
        cout << "Food Item  : " << temp->food << endl;
        cout << "Quantity   : " << temp->quantity << endl;
        cout << fixed << setprecision(2);
        cout << "Total Bill : Rs. " << temp->total << endl;

        cout << "\nOrder delivered successfully!\n";

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

        cout << fixed << setprecision(2);
        cout << "\n========== PENDING FOOD ORDERS ==========\n";

        while (temp != NULL) {
            cout << "\nOrder ID: " << temp->id
                 << " | Customer: " << temp->name
                 << " | Food: " << temp->food
                 << "\nQuantity: " << temp->quantity
                 << " | Price: Rs. " << temp->price
                 << " | Total Bill: Rs. " << temp->total
                 << endl;

            temp = temp->next;
        }
    }

    void nextOrder() {
        if (front == NULL) {
            cout << "\nNo pending orders.\n";
            return;
        }

        cout << fixed << setprecision(2);

        cout << "\n========== NEXT ORDER ==========\n";
        cout << "Order ID   : " << front->id << endl;
        cout << "Customer   : " << front->name << endl;
        cout << "Food Item  : " << front->food << endl;
        cout << "Quantity   : " << front->quantity << endl;
        cout << "Price      : Rs. " << front->price << endl;
        cout << "Total Bill : Rs. " << front->total << endl;
    }

    ~FoodQueue() {
        while (front != NULL) {
            Node *temp = front;
            front = front->next;
            delete temp;
        }

        rear = NULL;
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
        case 1:
            q.placeOrder();
            break;

        case 2:
            q.deliverOrder();
            break;

        case 3:
            q.display();
            break;

        case 4:
            q.nextOrder();
            break;

        case 5:
            cout << "\nThank you for using Food Delivery Order Queue!\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    } while (ch != 5);

    return 0;
}
