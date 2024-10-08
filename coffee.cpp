#include <iostream>
using namespace std;

class MenuItem {
public:
    string name;
    double price;

    void setDetails(string n, double price) {
        this->name = name;
        this->price = price;
    }

    void showDetails() {
        cout << "Item: " << this->name << ", Price: $" << this->price << endl;
    }
};

class Order {
public:
    int orderId;
    string customerPreferences;

    void setDetails(int orderId, string customerPreferences) {
        this->orderId = orderId;
        this->customerPreferences = customerPreferences;
    }

    void showDetails() {
        cout << "Order ID: " << this->orderId << ", Preferences: " << this->customerPreferences << endl;
    }
};

int main() {
    MenuItem item;
    Order order1;

    string itemName, customerPref;
    double itemPrice;
    int orderId;

    cout << "Enter the item name: ";
    getline(cin, itemName);
    cout << "Enter the item price: ";
    cin >> itemPrice;
    cin.ignore();

    
    item.setDetails(itemName, itemPrice);

   
    cout << "Enter the order ID: ";
    cin >> orderId;
    cin.ignore();
    cout << "Enter customer preferences: ";
    getline(cin, customerPref);

    
    order1.setDetails(orderId, customerPref);

    item.showDetails();
    order1.showDetails();

    return 0;
}
