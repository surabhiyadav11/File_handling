#include <iostream>
using namespace std;

class Node {
public:
    string word;
    string meaning;

    Node* next;
    Node* prev;

    Node(string w, string m) {
        word = w;
        meaning = m;
        next = NULL;
        prev = NULL;
    }
};

class Dictionary {
private:
    Node* head;

public:

    Dictionary() {
        head = NULL;
    }

    // INSERT
    void insert(string word, string meaning) {

        Node* newNode = new Node(word, meaning);

        // If list is empty
        if (head == NULL) {
            head = newNode;

            head->next = head;
            head->prev = head;

            return;
        }

        // Insert at end
        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }

    // DELETE
    void deleteWord(string word) {

        if (head == NULL) {
            cout << "Dictionary is empty\n";
            return;
        }

        Node* temp = head;

        do {
            if (temp->word == word) {

                // Only one node
                if (temp->next == temp) {
                    head = NULL;
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    // If deleting head
                    if (temp == head) {
                        head = temp->next;
                    }
                }

                delete temp;

                cout << "Word deleted successfully\n";
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Word not found\n";
    }

    // UPDATE
    void update(string word, string newMeaning) {

        if (head == NULL) {
            cout << "Dictionary is empty\n";
            return;
        }

        Node* temp = head;

        do {
            if (temp->word == word) {
                temp->meaning = newMeaning;

                cout << "Meaning updated successfully\n";
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Word not found\n";
    }

    // DISPLAY
    void display() {

        if (head == NULL) {
            cout << "Dictionary is empty\n";
            return;
        }

        Node* temp = head;

        cout << "\nDictionary:\n";

        do {
            cout << temp->word << " : "
                 << temp->meaning << endl;

            temp = temp->next;

        } while (temp != head);
    }
};

int main() {

    Dictionary d;

    int choice;
    string word, meaning;

    do {

        cout << "\n===== DICTIONARY =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Update\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter word: ";
            cin >> word;

            cout << "Enter meaning: ";
            cin.ignore();
            getline(cin, meaning);

            d.insert(word, meaning);
            cout << "Word inserted successfully\n";
            break;

        case 2:
            cout << "Enter word to delete: ";
            cin >> word;

            d.deleteWord(word);
            break;

        case 3:
            cout << "Enter word to update: ";
            cin >> word;

            cout << "Enter new meaning: ";
            cin.ignore();
            getline(cin, meaning);

            d.update(word, meaning);
            break;

        case 4:
            d.display();
            break;

        case 5:
            cout << "Program ended\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}