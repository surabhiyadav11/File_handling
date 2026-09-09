/*
    E-COMMERCE PRODUCT MANAGEMENT AND SEARCH SYSTEM
    -------------------------------------------------
    Easy, simple C program covering:
    1. Add & display N products
    2. Linear Search by Product ID
    3. Sort products by Price (Bubble Sort)
    4. Binary Search by Product ID (after sorting by ID)
    5. Cheapest, Most Expensive, Highest Rated product
    6. Top 5 highest priced products
    7. Price range search
*/

#include <stdio.h>

#define MAX 100   // maximum number of products

struct Product {
    int id;
    char name[50];
    char category[30];
    float price;
    float rating;
    int stock;
};

struct Product products[MAX];
int n;  


void addProducts() {
    printf("\nEnter number of products: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n--- Product %d ---\n", i + 1);

        printf("Product ID: ");
        scanf("%d", &products[i].id);

        printf("Product Name: ");
        scanf("%s", products[i].name);       // %s = no spaces in name

        printf("Category: ");
        scanf("%s", products[i].category);

        printf("Price: ");
        scanf("%f", &products[i].price);

        printf("Rating: ");
        scanf("%f", &products[i].rating);

        printf("Stock Quantity: ");
        scanf("%d", &products[i].stock);
    }
}

void displayProducts() {
    printf("\nID\tName\t\tCategory\tPrice\tRating\tStock\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%s\t\t%.2f\t%.1f\t%d\n",
               products[i].id, products[i].name, products[i].category,
               products[i].price, products[i].rating, products[i].stock);
    }
}

/* 2. LINEAR SEARCH BY PRODUCT ID - */

void linearSearch() {
    int id, found = 0;
    printf("\nEnter Product ID to search (Linear Search): ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (products[i].id == id) {
            printf("\nProduct Found!\n");
            printf("Name: %s, Category: %s, Price: %.2f, Rating: %.1f, Stock: %d\n",
                   products[i].name, products[i].category, products[i].price,
                   products[i].rating, products[i].stock);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("\nProduct with ID %d not found.\n", id);
}

/* ---------- 3. SORT PRODUCTS BY PRICE (BUBBLE SORT) ---------- */

void sortByPrice() {
    struct Product temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (products[j].price > products[j + 1].price) {
                temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
    printf("\nProducts sorted by price successfully!\n");
}

/* Small helper: sort by ID (needed before binary search on ID) */
void sortByID() {
    struct Product temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (products[j].id > products[j + 1].id) {
                temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

/* 4. BINARY SEARCH BY PRODUCT ID */

void binarySearch() {
    sortByID();   // binary search needs the array sorted by ID first
    printf("\n(Array sorted by ID for Binary Search)\n");

    int id;
    printf("Enter Product ID to search (Binary Search): ");
    scanf("%d", &id);

    int low = 0, high = n - 1, mid, found = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        if (products[mid].id == id) {
            printf("\nProduct Found!\n");
            printf("Name: %s, Category: %s, Price: %.2f, Rating: %.1f, Stock: %d\n",
                   products[mid].name, products[mid].category, products[mid].price,
                   products[mid].rating, products[mid].stock);
            found = 1;
            break;
        } else if (products[mid].id < id) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (!found)
        printf("\nProduct with ID %d not found.\n", id);
}

/* ---------- 5. CHEAPEST / MOST EXPENSIVE / HIGHEST RATED ---------- */

void cheapestProduct() {
    int idx = 0;
    for (int i = 1; i < n; i++)
        if (products[i].price < products[idx].price)
            idx = i;
    printf("\nCheapest Product: %s (Price: %.2f)\n", products[idx].name, products[idx].price);
}

void expensiveProduct() {
    int idx = 0;
    for (int i = 1; i < n; i++)
        if (products[i].price > products[idx].price)
            idx = i;
    printf("\nMost Expensive Product: %s (Price: %.2f)\n", products[idx].name, products[idx].price);
}

void highestRatedProduct() {
    int idx = 0;
    for (int i = 1; i < n; i++)
        if (products[i].rating > products[idx].rating)
            idx = i;
    printf("\nHighest Rated Product: %s (Rating: %.1f)\n", products[idx].name, products[idx].rating);
}

/* ---------- 6. TOP 5 HIGHEST PRICED PRODUCTS ---------- */

void topFiveProducts() {
    sortByPrice();  // ascending order after sort

    printf("\nTop 5 Highest Priced Products:\n");
    int count = 0;
    // print from the end of sorted array (highest price first)
    for (int i = n - 1; i >= 0 && count < 5; i--, count++) {
        printf("%d. %s - Price: %.2f\n", count + 1, products[i].name, products[i].price);
    }
}

/* ---------- 7. PRICE RANGE SEARCH ---------- */

void priceRangeSearch() {
    float minP, maxP;
    printf("\nEnter minimum price: ");
    scanf("%f", &minP);
    printf("Enter maximum price: ");
    scanf("%f", &maxP);

    printf("\nProducts in range %.2f - %.2f:\n", minP, maxP);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (products[i].price >= minP && products[i].price <= maxP) {
            printf("%s - Price: %.2f\n", products[i].name, products[i].price);
            found = 1;
        }
    }
    if (!found)
        printf("No products found in this price range.\n");
}

/* ---------- MAIN MENU ---------- */

int main() {
    int choice;

    do {
        printf("\n===== PRODUCT MANAGEMENT MENU =====\n");
        printf("1. Add Products\n");
        printf("2. Display Products\n");
        printf("3. Linear Search by ID\n");
        printf("4. Sort Products by Price\n");
        printf("5. Binary Search by ID\n");
        printf("6. Cheapest Product\n");
        printf("7. Most Expensive Product\n");
        printf("8. Highest Rated Product\n");
        printf("9. Top 5 Highest Priced Products\n");
        printf("10. Price Range Search\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProducts(); break;
            case 2: displayProducts(); break;
            case 3: linearSearch(); break;
            case 4: sortByPrice(); break;
            case 5: binarySearch(); break;
            case 6: cheapestProduct(); break;
            case 7: expensiveProduct(); break;
            case 8: highestRatedProduct(); break;
            case 9: topFiveProducts(); break;
            case 10: priceRangeSearch(); break;
            case 0: printf("\nExiting program...\n"); break;
            default: printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 0);

    return 0;
}