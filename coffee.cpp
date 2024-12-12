#include <iostream>
#include <string>
using namespace std;

class Item {
protected:
    string name;
    double price;

public:
    Item() : name("Unknown"), price(0.0) {}

    Item(const string& itemName, double itemPrice) : name(itemName), price(itemPrice) {}

    virtual ~Item() {}

    virtual void showDetails() const = 0; 
};

class MenuItem : public Item {
private:
    static int totalItems;

public:
    MenuItem() : Item() {
        totalItems++;
    }

    MenuItem(const string& itemName, double itemPrice) : Item(itemName, itemPrice) {
        totalItems++;
    }

    ~MenuItem() {
        totalItems--;
    }

    static void showTotalItems() {
        cout << "Total menu items: " << totalItems << endl;
    }

    void setDetails(const string& itemName) {
        name = itemName;
    }

    void setDetails(const string& itemName, double itemPrice) {
        name = itemName;
        price = itemPrice;
    }

    void showDetails() const override {
        cout << "Item: " << name << ", Price: $" << price << endl;
    }
};

int MenuItem::totalItems = 0;

class Order : public Item {
private:
    int orderId;
    string customerPreferences;
    static int totalOrders;

public:
    Order() : Item(), orderId(0), customerPreferences("None") {
        totalOrders++;
    }

    Order(int id, const string& preferences) : Item(), orderId(id), customerPreferences(preferences) {
        totalOrders++;
    }

    ~Order() {
        totalOrders--;
    }

    void setDetails(int id, const string& preferences) {
        orderId = id;
        customerPreferences = preferences;
    }

    void showDetails() const override {
        cout << "Order ID: " << orderId << ", Preferences: " << customerPreferences << endl;
    }

    static void showTotalOrders() {
        cout << "Total orders placed: " << totalOrders << endl;
    }
};

int Order::totalOrders = 0;

class MenuItemManager {
public:
    void addMenuItem(MenuItem& menuItem, const string& itemName, double itemPrice) {
        menuItem.setDetails(itemName, itemPrice);
    }

    void displayMenuItem(const Item& item) const {
        item.showDetails();
    }
};

class OrderManager {
public:
    void addOrder(Order& order, int orderId, const string& preferences) {
        order.setDetails(orderId, preferences);
    }

    void displayOrder(const Item& item) const {
        item.showDetails();
    }
};

class DiscountedMenuItem : public MenuItem {
private:
    double discount;

public:
    DiscountedMenuItem(const string& itemName, double itemPrice, double discountRate) 
        : MenuItem(itemName, itemPrice), discount(discountRate) {}

    void showDetails() const override {
        cout << "Item: " << name << ", Price: $" << price << ", Discount: " << discount << "%" << endl;
    }
};

int main() {
    MenuItem menuItem("Pizza", 9.99);
    Order order(101, "Extra cheese");
    DiscountedMenuItem discountedItem("Burger", 5.99, 10.0);

    MenuItemManager menuItemManager;
    OrderManager orderManager;

    menuItemManager.displayMenuItem(menuItem);
    orderManager.displayOrder(order);
    menuItemManager.displayMenuItem(discountedItem);

    MenuItem::showTotalItems();
    Order::showTotalOrders();

    return 0;
}
