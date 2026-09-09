#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Product {
public:
    int id;
    string name;
    string type;

    Product(int i, string n, string t) {
        id = i;
        name = n;
        type = t;
    }

    void display() {
        cout << id << "  " << name << "  " << type << endl;
    }
};

class Mall {
public:
    vector<Product> products;
    map<string, int> purchaseCount;

    // Add product
    void addProduct(Product p) {
        products.push_back(p);
    }

    // Record purchase
    void purchase(string name) {
        purchaseCount[name]++;
    }

    // Display products
    void displayProducts() {
        cout << "\nProducts in Mall:\n";

        for (int i = 0; i < products.size(); i++) {
            products[i].display();
        }
    }

    // Display purchase pattern
    void displayPurchasePattern() {
        cout << "\nPurchase Pattern:\n";

        for (auto x : purchaseCount) {
            cout << x.first << " -> "
                 << x.second << " times" << endl;
        }
    }
};

int main() {

    Mall mall;

    mall.addProduct(Product(1, "Apple", "Fruit"));
    mall.addProduct(Product(2, "Banana", "Fruit"));
    mall.addProduct(Product(3, "Mango", "Fruit"));
    mall.addProduct(Product(4, "Potato", "Vegetable"));
    mall.addProduct(Product(5, "Onion", "Vegetable"));
    mall.addProduct(Product(6, "Tomato", "Vegetable"));

    mall.displayProducts();

    int n;
    cout << "\nEnter number of purchases: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        string name;

        cout << "Enter product name: ";
        cin >> name;

        mall.purchase(name);
    }

    
    mall.displayPurchasePattern();

    return 0;
}

