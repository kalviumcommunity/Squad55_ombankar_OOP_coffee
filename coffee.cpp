#include <iostream>
using namespace std;

class MenuItem {
public:
    string name;
    double price;
    static int totalItems;

    void setDetails(string name, double price) {
        this->name = name;
        this->price = price;
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
public:
    int orderId;
    string customerPreferences;
    static int totalOrders;

    void setDetails(int orderId, string customerPreferences) {
        this->orderId = orderId;
        this->customerPreferences = customerPreferences;
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

    cout << "Enter the item name: ";
    getline(cin, menuItem.name);
    cout << "Enter the item price: ";
    cin >> menuItem.price;
    menuItem.setDetails(menuItem.name, menuItem.price);

    cout << "Enter the order ID: ";
    cin >> order.orderId;
    cin.ignore();
    cout << "Enter customer preferences: ";
    getline(cin, order.customerPreferences);
    order.setDetails(order.orderId, order.customerPreferences);

    menuItem.showDetails();
    order.showDetails();

    MenuItem::showTotalItems();
    Order::showTotalOrders();

    return 0;
}
