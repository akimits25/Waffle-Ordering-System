#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int MAX_SIZE = 10;
string orders[MAX_SIZE];
int currentSize = 0;

void showTotal() {
    double total = 0.0;
    
    for (int i = 0; i < currentSize; i++) {
        string order = orders[i];
        
        int quantity = 0;
        stringstream ss(order.substr(order.find("x") + 1));
        ss >> quantity;
        
        float price = 0.0;
        if (order.find("Plain Waffle") != string::npos) price = 50.00;
        else if (order.find("Chocolate Waffle") != string::npos) price = 60.00;
        else if (order.find("Vanilla Waffle") != string::npos) price = 55.00;
        else if (order.find("Cheese Waffle") != string::npos) price = 70.00;
        else if (order.find("Peanut Butter Waffle") != string::npos) price = 70.00;
        else if (order.find("Strawberry Waffle") != string::npos) price = 75.00;
        else if (order.find("Cinnamon Waffle") != string::npos) price = 60.00;
        else if (order.find("Ube Waffle") != string::npos) price = 80.00;
        else if (order.find("Banana Waffle") != string::npos) price = 70.00;
        else if (order.find("Matcha Waffle") != string::npos) price = 90.00;

        total += price * quantity;
    }

    cout << "\nTotal Order Amount: ₱" << total << endl;
}

void create() {
    if (currentSize >= MAX_SIZE) {
        cout << "\nSorry, we can't add more entries at the moment. The list is full.\n";
        return;
    }
    
    int choice;
    cout << "\nSelect a flavor from the list below (enter the number):";
    cout << "\n1. Plain Waffle – ₱50\n2. Chocolate Waffle – ₱60\n3. Vanilla Waffle – ₱55\n4. Cheese Waffle – ₱70\n5. Peanut Butter Waffle – ₱70\n";
    cout << "6. Strawberry Waffle – ₱75\n7. Cinnamon Waffle – ₱60\n8. Ube Waffle – ₱80\n9. Banana Waffle – ₱70\n10. Matcha Waffle – ₱90\n";
    cout << "\nChoose a waffle flavor: ";
    cin >> choice;
    
    string flavor;
    float price;
    switch (choice) {
        case 1:
            flavor = "Plain Waffle";
            price = 50.00;
            break;
        case 2:
            flavor = "Chocolate Waffle";
            price = 60.00;
            break;
        case 3:
            flavor = "Vanilla Waffle";
            price = 55.00;
            break;
        case 4:
            flavor = "Cheese Waffle";
            price = 70.00;
            break;
        case 5:
            flavor = "Peanut Butter Waffle";
            price = 70.00;
            break;
        case 6:
            flavor = "Strawberry Waffle";
            price = 75.00;
            break;
        case 7:
            flavor = "Cinnamon Waffle";
            price = 60.00;
            break;
        case 8:
            flavor = "Ube Waffle";
            price = 80.00;
            break;
        case 9:
            flavor = "Banana Waffle";
            price = 70.00;
            break;
        case 10:
            flavor = "Matcha Waffle";
            price = 90.00;
            break;
        default:
            cout << "\nInvalid selection. Please choose a number from the list." << endl;
            return;
    }
        
    int quantity;
    cout << "Quantity: ";
    cin >> quantity;
    cout << "\n" << flavor << " - " << 'x' << quantity << "\n";
    orders[currentSize] = flavor + " - " + 'x' + to_string(quantity);
    currentSize++;

    showTotal();
}

void read() {
    if (currentSize == 0) {
        cout << "\nYou haven't placed any orders yet.\n";
        return;
    }
    cout << "\nList of orders:\n";
    for (int i = 0; i < currentSize; i++) {
        cout << (i + 1) << ". " << orders[i] << endl;
    
    }
}

void update() {
    if (currentSize == 0) {
        cout << "\nYou haven't placed any orders yet.\n";
        return;
    }
    read();
    int entry;
    cout << "\nEnter the number of the entry you'd like to update: ";
    cin >> entry;

    if (entry < 1 || entry > currentSize) {
        cout << "\nInvalid choice.\n";
        return;
    }
    
    int Newchoice;
    cout << "\nSelect a flavor from the list below (enter the number):";
    cout << "\n1. Plain Waffle – ₱50\n2. Chocolate Waffle – ₱60\n3. Vanilla Waffle – ₱55\n4. Cheese Waffle – ₱70\n5. Peanut Butter Waffle – ₱70\n";
    cout << "6. Strawberry Waffle – ₱75\n7. Cinnamon Waffle – ₱60\n8. Ube Waffle – ₱80\n9. Banana Waffle – ₱70\n10. Matcha Waffle – ₱90\n";
    cout << "\nChoose a waffle flavor: ";
    cin >> Newchoice;
    
    string Newflavor;
    float price;
    switch (Newchoice) {
        case 1:
            Newflavor = "Plain Waffle";
            price = 50.00;
            break;
        case 2:
            Newflavor = "Chocolate Waffle";
            price = 60.00;
            break;
        case 3:
            Newflavor = "Vanilla Waffle";
            price = 55.00;
            break;
        case 4:
            Newflavor = "Cheese Waffle";
            price = 70.00;
            break;
        case 5:
            Newflavor = "Peanut Butter Waffle";
            price = 70.00;
            break;
        case 6:
            Newflavor = "Strawberry Waffle";
            price = 75.00;
            break;
        case 7:
            Newflavor = "Cinnamon Waffle";
            price = 60.00;
            break;
        case 8:
            Newflavor = "Ube Waffle";
            price = 80.00;
            break;
        case 9:
            Newflavor = "Banana Waffle";
            price = 70.00;
            break;
        case 10:
            Newflavor = "Matcha Waffle";
            price = 90.00;
            break;
        default:
            cout << "\nInvalid selection. Please choose a number from the list." << endl;
            return;
    }
        
    int quantity;
    cout << "Quantity:";
    cin >> quantity;
    cout << "\n" << Newflavor << " - " << 'x' << quantity << "\n";
    orders[entry - 1] = Newflavor + " - " + "x" + to_string(quantity);
    cout << "\nEntry updated successfully.\n";

    showTotal();
}

void deleteEntry() {
    if (currentSize == 0) {
        cout << "\nYou haven't placed any orders yet.\n";
        return;
    }
    read();
    int entry;
    cout << "\nEnter the number of the entry you want to delete: ";
    cin >> entry;

    if (entry < 1 || entry > currentSize) {
        cout << "\nInvalid entry. Please choose a number that corresponds to an existing entry.\n";
        return;
    }

    for (int i = entry - 1; i < currentSize - 1; i++) {
        orders[i] = orders[i + 1];
    }

    currentSize--;
    cout << "\nYour order has been removed.\n";

    showTotal();
}

void menu() {
    int choice;
    while (true) {
        cout << "\n--- Mayka's Waffles ---\n";
        cout << "1. Place Order\n";
        cout << "2. View Orders\n";
        cout << "3. Update Order\n";
        cout << "4. Cancel Order\n";
        cout << "5. Complete Order\n";
        cout << "\nEnter an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                read();
                showTotal();
                break;
            case 3:
                update();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                cout << "\nThank you for your order! Your waffles will be ready soon.";
                showTotal();
                return;
            default:
                cout << "\nInvalid choice. Enter a number from 1 to 5.\n";
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}
