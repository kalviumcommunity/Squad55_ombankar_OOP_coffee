#include <iostream>
using namespace std;

class MenuItem {
public:
    string name;
    double price;
};

class Order {
public:
    int orderId;
    string customerPreferences;
};

int main() {
    MenuItem item;
    Order order1;

   
    cout << "Enter the item name: ";
    getline(cin, item.name);  

    cout << "Enter the item price: ";
    cin >> item.price;

    cin.ignore();

    cout << "Enter the order ID: ";
    cin >> order1.orderId;

    cin.ignore();

    cout << "Enter customer preferences: ";
    getline(cin, order1.customerPreferences);  

    cout << "\nItem: " << item.name << ", Price: $" << item.price << endl;
    cout << "Order ID: " << order1.orderId << ", Preferences: " << order1.customerPreferences << endl;

    return 0;
}
