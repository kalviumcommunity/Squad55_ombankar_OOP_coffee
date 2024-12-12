#include <iostream>
#include <string>
using namespace std;

class MenuItem {
private:
    string name;
    double price;
    static int totalItems;

public:
 
    MenuItem() : name("Unknown"), price(0.0) {
        totalItems++;
    }

    
    MenuItem(const string& itemName, double itemPrice) : name(itemName), price(itemPrice) {
        totalItems++;
    }

 
    ~MenuItem() {
        totalItems--;
    }

    void setDetails(const string& itemName, double itemPrice) {
        name = itemName;
        price = itemPrice;
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
    
    Order() : orderId(0), customerPreferences("None") {
        totalOrders++;
    }

   
    Order(int id, const string& preferences) : orderId(id), customerPreferences(preferences) {
        totalOrders++;
    }

   
    ~Order() {
        totalOrders--;
    }

    void setDetails(int id, const string& preferences) {
        orderId = id;
        customerPreferences = preferences;
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
   
    MenuItem menuItem("Pizza", 9.99);
    Order order(101, "Extra cheese");

    menuItem.showDetails();
    order.showDetails();

    MenuItem::showTotalItems();
    Order::showTotalOrders();

    return 0;
}
