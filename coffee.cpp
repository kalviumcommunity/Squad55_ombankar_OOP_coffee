#include <iostream>
#include <string>
using namespace std;

class MenuItem {
private:
    string name;
    double price;
    static int totalItems;

public:
    void setDetails(const string& itemName, double itemPrice) {
        name = itemName;
        price = itemPrice;
        totalItems++;
    }

    void showDetails() const {
        cout << "Item: " << name << ", Price: $" << price << endl;
    }

    static void showTotalItems() {
        cout << "Total menu items: " << totalItems << endl;
    }
};

int MenuItem::totalItems = 0;

class Order {
private:
    int orderId;
    string customerPreferences;
    static int totalOrders;

public:
    void setDetails(int id, const string& preferences) {
        orderId = id;
        customerPreferences = preferences;
        totalOrders++;
    }

    void showDetails() const {
        cout << "Order ID: " << orderId << ", Preferences: " << customerPreferences << endl;
    }

    static void showTotalOrders() {
        cout << "Total orders placed: " << totalOrders << endl;
    }
};

int Order::totalOrders = 0;

int main() {
    MenuItem menuItem;
    Order order;

    string itemName, preferences;
    double itemPrice;
    int orderId;

    cout << "Enter the item name: ";
    getline(cin, itemName);
    cout << "Enter the item price: ";
    cin >> itemPrice;
    menuItem.setDetails(itemName, itemPrice);

    cout << "Enter the order ID: ";
    cin >> orderId;
    cin.ignore();
    cout << "Enter customer preferences: ";
    getline(cin, preferences);
    order.setDetails(orderId, preferences);

    menuItem.showDetails();
    order.showDetails();

    MenuItem::showTotalItems();
    Order::showTotalOrders();

    return 0;
}
