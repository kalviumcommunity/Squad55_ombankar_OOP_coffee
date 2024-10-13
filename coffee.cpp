#include <iostream>
using namespace std;

class MenuItem {
public:
    string name;
    double price;

    void setDetails(string name, double price) {
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
    const int numItems = 1;

    MenuItem* menuItems = new MenuItem[numItems];  
    Order* order1 = new Order;  

    string itemName, customerPref;
    double itemPrice;
    int orderId;

    for (int i = 0; i < numItems; i++) {
        cout << "Enter the item name: ";
        getline(cin, itemName);
        cout << "Enter the item price: ";
        cin >> itemPrice;
        cin.ignore();
        menuItems[i].setDetails(itemName, itemPrice);
    }

    cout << "Enter the order ID: ";
    cin >> orderId;
    cin.ignore();
    cout << "Enter customer preferences: ";
    getline(cin, customerPref);
    
    order1->setDetails(orderId, customerPref);

    for (int i = 0; i < numItems; i++) {
        menuItems[i].showDetails();
    }

    order1->showDetails();

    delete[] menuItems;  
    delete order1;  

    return 0;
}
