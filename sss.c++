#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

struct Client {
    string name;
    long long phone;
    bool occupied;

    Client() {
        name = "";
        phone = 0;
        occupied = false;
    }
};

// Hash function
int hashFunction(string key) {
    int sum = 0;
    for (char ch : key)
        sum += ch;
    return sum % TABLE_SIZE;
}

// Secondary hash for double hashing
int doubleHash(string key) {
    int sum = 0;
    for (char ch : key)
        sum += ch;
    return 7 - (sum % 7); // 7 should be < TABLE_SIZE and prime
}

class HashTable {
    Client table[TABLE_SIZE];

public:
    void insertLinear(string name, long long phone) {
        int index = hashFunction(name);
        int startIndex = index;
        while (table[index].occupied) {
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) {
                cout << "Hash Table is full!\n";
                return;
            }
        }
        table[index].name = name;
        table[index].phone = phone;
        table[index].occupied = true;
    }

    void insertQuadratic(string name, long long phone) {
        int index = hashFunction(name);
        int i = 0;
        while (table[(index + i * i) % TABLE_SIZE].occupied && i < TABLE_SIZE) {
            i++;
        }
        if (i == TABLE_SIZE) {
            cout << "Hash Table is full!\n";
            return;
        }
        int finalIndex = (index + i * i) % TABLE_SIZE;
        table[finalIndex].name = name;
        table[finalIndex].phone = phone;
        table[finalIndex].occupied = true;
    }

    void insertDoubleHash(string name, long long phone) {
        int index = hashFunction(name);
        int step = doubleHash(name);
        int i = 0;
        while (table[(index + i * step) % TABLE_SIZE].occupied && i < TABLE_SIZE) {
            i++;
        }
        if (i == TABLE_SIZE) {
            cout << "Hash Table is full!\n";
            return;
        }
        int finalIndex = (index + i * step) % TABLE_SIZE;
        table[finalIndex].name = name;
        table[finalIndex].phone = phone;
        table[finalIndex].occupied = true;
    }

    void search(string name) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].occupied && table[i].name == name) {
                cout << "Client found at index " << i << ": " << table[i].phone << endl;
                return;
            }
        }
        cout << "Client not found.\n";
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            if (table[i].occupied)
                cout << table[i].name << " - " << table[i].phone;
            else
                cout << "Empty";
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice;
    string name;
    long long phone;
    int method;

    cout << "Hash Table Collision Resolution:\n";
    cout << "1. Linear Probing\n2. Quadratic Probing\n3. Double Hashing\n";
    cout << "Choose method (1-3): ";
    cin >> method;

    do {
        cout << "\n1. Insert\n2. Search\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> phone;
            if (method == 1)
                ht.insertLinear(name, phone);
            else if (method == 2)
                ht.insertQuadratic(name, phone);
            else if (method == 3)
                ht.insertDoubleHash(name, phone);
            else
                cout << "Invalid method.\n";
            break;

        case 2:
            cout << "Enter name to search: ";
            cin >> name;
            ht.search(name);
            break;

        case 3:
            ht.display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
