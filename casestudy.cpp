#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

class MenuItem {
protected:
    string name;
    string category;
    double basePrice;
public:
    MenuItem() {
        name = "";
        category = "";
        basePrice = 0.0;
    }
    MenuItem(string n, string c, double p) {
        name = n;
        category = c;
        basePrice = p;
    }

    virtual void display() {
        cout << name << " - $" << fixed << setprecision(2) << basePrice << endl;
    }

    virtual double getPrice(string size) {
        if (size == "Small") return basePrice;
        else if (size == "Medium") return basePrice + 0.5;
        else if (size == "Large") return basePrice + 1.0;
        else return basePrice;
    }
    
    void setPrice(double p) {
    basePrice = p;
    }


    string getName() { return name; }
    string getCategory() { return category; }
};


class CoffeeItem : public MenuItem {
public:
    CoffeeItem(string n) : MenuItem(n, "Coffee", 2.0) {}
};

class TeaItem : public MenuItem {
public:
    TeaItem(string n) : MenuItem(n, "Tea", 1.5) {}
};

class SnackItem : public MenuItem {
public:
    SnackItem(string n) : MenuItem(n, "Snack", 2.0) {}
    double getPrice(string size) { return basePrice; }
};

class DessertItem : public MenuItem {
public:
    DessertItem(string n) : MenuItem(n, "Dessert", 1.5) {}
    double getPrice(string size) { return basePrice; }
};


class Menu {
private:
    static const int MAX_ITEMS = 50;
    MenuItem* items[MAX_ITEMS];
    int itemCount;

public:
    Menu() {
        itemCount = 0;
        for (int i = 0; i < MAX_ITEMS; i++) items[i] = NULL;

        
        addItem(new CoffeeItem("Espresso"));
        addItem(new CoffeeItem("Cappuccino"));
        addItem(new CoffeeItem("Latte"));
        addItem(new CoffeeItem("Americano"));

        addItem(new TeaItem("Green Tea"));
        addItem(new TeaItem("Black Tea"));
        addItem(new TeaItem("Chamomile"));
        addItem(new TeaItem("Masala Chai"));

        addItem(new SnackItem("Sandwich"));
        addItem(new SnackItem("Cookies"));
        addItem(new SnackItem("French Fries"));
        addItem(new SnackItem("Muffin"));

        addItem(new DessertItem("Muffin"));
        addItem(new DessertItem("Brownie"));
        addItem(new DessertItem("Donut"));
        addItem(new DessertItem("Cupcake"));
    }

    void addItem(MenuItem* m) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount] = m;
            itemCount++;
        } else {
            cout << "Menu is full!" << endl;
        }
    }

    void displayMenu() {
        cout << "===================================" << endl;
        cout << "             MENU                  " << endl;
        cout << "===================================" << endl;

        string currentCategory = "";
        for (int i = 0; i < itemCount; i++) {
            if (items[i]->getCategory() != currentCategory) {
                currentCategory = items[i]->getCategory();
                cout << "---------- " << currentCategory << " ----------" << endl;
            }
            cout << i + 1 << ". ";
            items[i]->display();
        }
        cout << "-----------------------------------" << endl;
    }

    MenuItem *getItem(int index) {
        if (index >= 0 && index < itemCount)
            return items[index];
        else
            return NULL;
    }

    int getItemCount() { return itemCount; }

    void addNewItem() {
        int categoryChoice;
        cout << "\nSelect Category to Add:\n1. Coffee\n2. Tea\n3. Snack\n4. Dessert\nEnter choice: ";
        cin >> categoryChoice;
        cin.ignore();

        string itemName;
        double itemPrice;
        cout << "Enter item name: ";
        getline(cin, itemName);

        cout << "Enter price for " << itemName << ": $";
        cin >> itemPrice;
        cin.ignore();

        MenuItem* newItem = NULL;

        switch(categoryChoice) {
            case 1: newItem = new CoffeeItem(itemName); break;
            case 2: newItem = new TeaItem(itemName); break;
            case 3: newItem = new SnackItem(itemName); break;
            case 4: newItem = new DessertItem(itemName); break;
            default:
                cout << "Invalid category!\n";
                return;
        }

        newItem->setPrice(itemPrice);     
        items[itemCount] = newItem;       
        itemCount++;

        cout << itemName << " added successfully with price $"
             << fixed << setprecision(2) << itemPrice << "!\n";
    }
};

class Order {
private:
    static const int MAX_ITEMS = 20;
    MenuItem* items[MAX_ITEMS];
    int quantities[MAX_ITEMS];
    string sizes[MAX_ITEMS];
    int itemCount;
public:
    Order() {
        itemCount = 0;
        for (int i = 0; i < MAX_ITEMS; i++) {
            items[i] = NULL;
            quantities[i] = 0;
            sizes[i] = "";
        }
    }

    void addItem(MenuItem* m, int qty, string size) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount] = m;
            quantities[itemCount] = qty;
            sizes[itemCount] = size;
            itemCount++;
        } else {
            cout << "Cannot add more items to this order!" << endl;
        }
    }

    double calculateTotal() {
        double total = 0.0;
        for (int i = 0; i < itemCount; i++) {
            total += items[i]->getPrice(sizes[i]) * quantities[i];
        }
        return total;
    }

    void displayOrder() {
        cout << "===================================" << endl;
        cout << "          CUSTOMER ORDER           " << endl;
        cout << "===================================" << endl;
        cout << left << setw(5) << "No."
             << setw(20) << "Item"
             << setw(10) << "Size"
             << setw(10) << "Qty"
             << setw(10) << "Price" << endl;

        for (int i = 0; i < itemCount; i++) {
            double price = items[i]->getPrice(sizes[i]) * quantities[i];
            cout << setw(5) << (i + 1)
                 << setw(20) << items[i]->getName()
                 << setw(10) << sizes[i]
                 << setw(10) << quantities[i]
                 << "$" << fixed << setprecision(2) << price << endl;
        }

        cout << "-----------------------------------" << endl;
        cout << "TOTAL BILL: $" << fixed << setprecision(2) << calculateTotal() << endl;
        cout << "===================================" << endl;
    }

    void saveOrder() {
        ofstream fout("orders.txt", ios::app);
        if (!fout.is_open()) {
            cout << "Error: Unable to save order!\n";
            return;
        }

        
        time_t now = time(0);
        char* dt = ctime(&now);
        fout << "Order Time: " << dt;

        for (int i = 0; i < itemCount; i++) {
            fout << items[i]->getName() << "," << sizes[i] << "," << quantities[i] 
                 << "," << fixed << setprecision(2) << items[i]->getPrice(sizes[i]) * quantities[i] << endl;
        }

        fout << "Total: $" << fixed << setprecision(2) << calculateTotal() << endl;
        fout << "-----------------------------------" << endl;

        fout.close();
    }
};

class Payment {
private:
    static float shopBalance;

    void loadBalance() {
        ifstream fin("shop_balance.txt");
        if (fin.is_open()) {
            fin >> shopBalance;
            fin.close();
        } else {
            shopBalance = 0.0;
        }
    }

    void saveBalance() {
        ofstream fout("shop_balance.txt");
        if (fout.is_open()) {
            fout << fixed << setprecision(2) << shopBalance;
            fout.close();
        } else {
            cout << "Error: Unable to save shop balance!\n";
        }
    }

public:
    Payment() { loadBalance(); }

    void processPayment(double total) {
        cout << "\nTotal amount to pay: $" << fixed << setprecision(2) << total << endl;
        int choice;
        cout << "Select payment method:\n1. Cash\n2. Card\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            float cash;
            cout << "Enter cash amount: $";
            cin >> cash;
            if (cash < total) {
                cout << "Insufficient cash! Transaction cancelled.\n";
                return;
            }
            float change = cash - total;
            shopBalance += total;
            saveBalance();
            cout << "Payment successful! Change to return: $" << change << endl;
        }
        else if (choice == 2) {
            string cardNumber;
            cout << "Enter card number: ";
            cin >> cardNumber;
            shopBalance += total;
            saveBalance();
            cout << "Payment successful! Amount $" << total << " charged to card.\n";
        }
        else {
            cout << "Invalid payment method! Transaction cancelled.\n";
        }
    }

    void displayShopBalance() {
        cout << "\nCurrent Shop Balance: $" << fixed << setprecision(2) << shopBalance << endl;
    }
};


float Payment::shopBalance = 0.0;

void generateRevenueReport() {
    ifstream fin("orders.txt");
    if (!fin.is_open()) {
        cout << "No orders found.\n";
        return;
    }

    string line;
    double totalRevenue = 0.0;
    int orderCount = 0;

    
    while (getline(fin, line)) {
    if (line.find("Total: $") != string::npos) {
        size_t pos = line.find("$");
        string totalStr = line.substr(pos + 1);  

        double total = 0.0;
        stringstream ss(totalStr);   
        ss >> total;

        totalRevenue += total;
        orderCount++;
    }
    }

    cout << "\n===== REVENUE REPORT =====\n";
    cout << "Total Orders: " << orderCount << endl;
    cout << "Total Revenue: $" << fixed << setprecision(2) << totalRevenue << endl;
    cout << "==========================\n";

    fin.close();
}

const string pass = "admin123"; 

bool authenticateAdmin() {
    string password;
    cout << "Enter Admin Password: ";
    cin >> password;
    if (password == pass) {
        return true;
    } else {
        cout << "Incorrect password! Access denied.\n";
        return false;
    }
}

int main() {
    Menu menu;
    Payment paymentSystem;
    int mainChoice;
    

    do {
        cout << "\n===== COFFEE SHOP SYSTEM =====\n";
        cout << "1. Display Menu\n";
        cout << "2. Place Order (Customer)\n";
        cout << "3. Add New Item (Admin)\n";
        cout << "4. Show Shop Balance (Admin)\n";
        cout << "5. Revenue Report (Admin)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            menu.displayMenu();
        }
        else if (mainChoice == 2) {
            Order order;
            int choice, qty;
            string size;
            do {
                menu.displayMenu();
                cout << "\nEnter the item number to order (0 to finish): ";
                cin >> choice;
                if (choice == 0) break;
                if (choice < 1 || choice > menu.getItemCount()) {
                    cout << "Invalid choice! Try again.\n";
                    continue;
                }

                MenuItem* selectedItem = menu.getItem(choice - 1);
                cout << "Enter quantity: ";
                cin >> qty;

                if (selectedItem->getCategory() == "Coffee" || selectedItem->getCategory() == "Tea") {
                    cout << "Enter size (Small/Medium/Large): ";
                    cin >> size;
                } else {
                    size = "-";
                }

                order.addItem(selectedItem, qty, size);
                cout << qty << " x " << selectedItem->getName() << " added to order.\n\n";

            } while (true);

            order.displayOrder();
            paymentSystem.processPayment(order.calculateTotal());
            order.saveOrder();
        }
        else if (mainChoice == 3) {
            if(authenticateAdmin()) {
            menu.addNewItem();
            }
        }
        else if (mainChoice == 4) {
        	if(authenticateAdmin()){
            paymentSystem.displayShopBalance();
            }
        }
        else if (mainChoice == 5) {
            if(authenticateAdmin()){
			generateRevenueReport();
		    }
        }
        else if (mainChoice == 0) {
            cout << "Exiting system. Goodbye!\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (mainChoice != 0);

    return 0;
}