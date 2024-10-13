#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    string itemId;
    string name;
    float price;
    int quantity;
    string category;

public:
    Item(string id = "", string name = "", float price = 0.0, int quantity = 0, string category = "")
        : itemId(id), name(name), price(price), quantity(quantity), category(category) {}

    string getId() const {
        return itemId;
    }

    string getName() const {
        return name;
    }

    float getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    string getCategory() const {
        return category;
    }

    void setPrice(float newPrice) {
        price = newPrice;
    }

    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    void displayItem() const {
        cout << itemId << "\t" << name << "\t" << price << "\t" << quantity << "\t" << category << endl;
    }
};

class Storage {
private:
    Item items[100]; // storage is 100
    int itemCount = 0;

public:
    void addItem(const Item& item) {
        if (itemCount < 100) {
            items[itemCount] = item;
            itemCount++;
            cout << "Item added successfully!" << endl;
        } else {
            cout << "Storage is full!" << endl;
        }
    }

    void displayItemsByCategory(const string& category) const {
        bool found = false;
        cout << "ID\tName\tPrice\tQuantity\tCategory" << endl;
        for (int i = 0; i < itemCount; ++i) {
            if (items[i].getCategory() == category) {
                items[i].displayItem();
                found = true;
            }
        }
        if (!found) {
            cout << "No items found in category: " << category << endl;
        }
    }

    void updateItem(const string& id, float newPrice, int newQuantity) {
        bool found = false;
        for (int i = 0; i < itemCount; ++i) {
            if (items[i].getId() == id) {
                items[i].setPrice(newPrice);
                items[i].setQuantity(newQuantity);
                cout << "Item updated successfully!" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Item not found." << endl;
        }
    }

    void removeItem(const string& id) {
        bool found = false;
        for (int i = 0; i < itemCount; ++i) {
            if (items[i].getId() == id) {
                for (int j = i; j < itemCount - 1; ++j) {
                    items[j] = items[j + 1]; // shift remaining items
                }
                itemCount--;
                cout << "Item removed successfully!" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Item not found." << endl;
        }
    }

    void displayAllItems() const {
        if (itemCount == 0) {
            cout << "No items in storage." << endl;
        } else {
            cout << "ID\tName\tPrice\tQuantity\tCategory" << endl;
            for (int i = 0; i < itemCount; ++i) {
                items[i].displayItem();
            }
        }
    }

    // bubble sort: ascending quantity
    void sortItemsByQuantityAscending() {
        for (int i = 0; i < itemCount - 1; ++i) {
            for (int j = 0; j < itemCount - i - 1; ++j) {
                if (items[j].getQuantity() > items[j + 1].getQuantity()) {
                    swap(items[j], items[j + 1]); 
                }
            }
        }
        cout << "Items sorted by quantity in ascending order successfully!" << endl;
    }

    // bubble sort: descending quantity
    void sortItemsByQuantityDescending() {
        for (int i = 0; i < itemCount - 1; ++i) {
            for (int j = 0; j < itemCount - i - 1; ++j) {
                if (items[j].getQuantity() < items[j + 1].getQuantity()) {
                    swap(items[j], items[j + 1]); 
                }
            }
        }
        cout << "Items sorted by quantity in descending order successfully!" << endl;
    }

    // bubble sort ascending price
    void sortItemsByPriceAscending() {
        for (int i = 0; i < itemCount - 1; ++i) {
            for (int j = 0; j < itemCount - i - 1; ++j) {
                if (items[j].getPrice() > items[j + 1].getPrice()) {
                    swap(items[j], items[j + 1]); 
                }
            }
        }
        cout << "Items sorted by price in ascending order successfully!" << endl;
    }

    // bubble sort descending price
    void sortItemsByPriceDescending() {
        for (int i = 0; i < itemCount - 1; ++i) {
            for (int j = 0; j < itemCount - i - 1; ++j) {
                if (items[j].getPrice() < items[j + 1].getPrice()) {
                    swap(items[j], items[j + 1]); 
                }
            }
        }
        cout << "Items sorted by price in descending order successfully!" << endl;
    }

    // custom swap function
    void swap(Item &a, Item &b) {
        Item temp = a;
        a = b;
        b = temp;
    }

    void displayLowStockItems() const {
        cout << "ID\tName\tPrice\tQuantity\tCategory" << endl;
        bool found = false;
        for (int i = 0; i < itemCount; ++i) {
            if (items[i].getQuantity() <= 5) {
                items[i].displayItem();
                found = true;
            }
        }
        if (!found) {
            cout << "No low stock items found." << endl;
        }
    }

    //search for an item by ID
    void searchItemById(const string& id) const {
        bool found = false;
        for (int i = 0; i < itemCount; ++i) {
            if (items[i].getId() == id) {
                cout << "Item found: " << endl;
                cout << "ID\tName\tPrice\tQuantity\tCategory" << endl;
                items[i].displayItem();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Item with ID " << id << " not found." << endl;
        }
    }
};

int main() {
    Storage storage;
    int option;

    while (true) {
        cout << "Enter option: Add item-1, Update item-2, Remove item-3, Display by category-4, Display all items-5, Search item-6, Sort items-7, Display low stock-8, Exit-9: ";
        cin >> option;

        switch (option) {
            case 1: {
                string id, name, category;
                float price;
                int quantity;

                cout << "Enter item ID: ";
                cin >> id;
                cout << "Enter item name: ";
                cin.ignore(); 
                getline(cin, name); // can input with spaces
                cout << "Enter item price: ";
                cin >> price;
                cout << "Enter item quantity: ";
                cin >> quantity;
                cout << "Enter item category (Clothing, Electronics, Entertainment): ";
                cin >> category;

                if (category == "Clothing" || category == "Electronics" || category == "entertainment" || category == "clothing" || category == "electronics" || category == "entertainment") {
                    Item newItem(id, name, price, quantity, category);
                    storage.addItem(newItem);
                } else {
                    cout << "Invalid category. Item not added." << endl;
                }
                break;
            }
            case 2: {
                string id;
                float newPrice;
                int newQuantity;

                cout << "Enter item ID to update: ";
                cin >> id;
                cout << "Enter new price: ";
                cin >> newPrice;
                cout << "Enter new quantity: ";
                cin >> newQuantity;

                storage.updateItem(id, newPrice, newQuantity);
                break;
            }
            case 3: {
                string id;
                cout << "Enter item ID to remove: ";
                cin >> id;
                storage.removeItem(id);
                break;
            }
            case 4: {
                string category;
                cout << "Enter category to display (Clothing, Electronics, Entertainment): ";
                cin >> category;
                storage.displayItemsByCategory(category);
                break;
            }
            case 5:
                storage.displayAllItems();
                break;
            case 6: {
                string id;
                cout << "Enter item ID to search: ";
                cin >> id;
                storage.searchItemById(id);
                break;
            }
            case 7: {
                int sortOption;
                cout << "Enter 1 for ascending quantity, 2 for descending quantity, 3 for ascending price, 4 for descending price: ";
                cin >> sortOption;

                switch (sortOption) {
                    case 1: storage.sortItemsByQuantityAscending(); break;
                    case 2: storage.sortItemsByQuantityDescending(); break;
                    case 3: storage.sortItemsByPriceAscending(); break;
                    case 4: storage.sortItemsByPriceDescending(); break;
                    default: cout << "Invalid option." << endl; break;
                }
                break;
            }
            case 8:
                storage.displayLowStockItems();
                break;
            case 9:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    }

    return 0;
}
