using namespace std;

#include <iostream>
#include <string>
#include <list>

class Owner {
    string name;
    string Password = "123";
    bool PassWordCheck = false;

public:
    Owner() {}
    Owner(string n, string p) : name(n), Password(p), PassWordCheck(false) {}
    
    bool PassWordCorrect() { return PassWordCheck; }
    
        void checkPassword() {
        string temp;
        cout << "Enter your password: " <<endl; 
        cin >> temp;
        if (temp == Password) { PassWordCheck = true; }
        else { PassWordCheck = false; }
    }

    void updatePrice(){
        
    }
    void updateStock() {}
    void getCoinsNow() {}
    
    
};

class Customer {
    int MoneyInserted;

public:
    
    void addCoin() {
        MoneyInserted += 1;
    }

    void returnCoins() {
        int coinsReturned = 0;

        while (MoneyInserted > 0) {
            MoneyInserted -= 1;
            coinsReturned += 1;
        }
        cout << coinsReturned << " Coins were returned";
    }
};


class Item {
    string name;
    int quantity;
    int price;

public:
    Item() {}
    Item(string n, int q, int p) : name(n), quantity(q),price(p){}

    void setPrice(){}
    void setQuantity() {}
    
    void updateItem(string n, int q, int p) {
        name = n;
        quantity = q;
        price = p;
    }

    void ItemToString() {

    }

};

class Display {
public:

    // ---------------------------------------------
    // TOP MENU
    // ---------------------------------------------
    void TopMenu() {
        cout << " =================================================" << endl;
        cout << "|                                                 |" << endl;
        cout << "|          Press 1 to see items for sale          |" << endl;
        cout << "|                                                 |" << endl;
        cout << "|             Press 2 for admin menu              |" << endl;
        cout << "|                                                 |" << endl;
        cout << " =================================================" << endl;
    }

    int GetTopMenuSelection() {
        int choice = 0;

        do {
            TopMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice != 1 && choice != 2) {
                cout << "\nInvalid option. Please try again.\n\n";
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
            }

        } while (choice != 1 && choice != 2);

        return choice;
    }


    void displayAdminMenu() {
        cout << " =================================================" << endl;
        cout << "|    Press 1 to see inventory information         |" << endl;
        cout << "|    Press 2 to update item Stock                 |" << endl;
        cout << "|    Press 3 to update item Price                 |" << endl;
        cout << "|    Press 4 to add a new item                    |" << endl;
        cout << "|    Press 5 to get your money!!!!                |" << endl;
        cout << " =================================================" << endl;
    }

    int GetAdminMenuSelection() {
        int choice = 0;

        do {
            displayAdminMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice < 1 || choice > 5) {
                cout << "\nInvalid option. Please try again.\n\n";
                if (std::cin.fail()) {
                    std::cin.clear();              
                    std::cin.ignore(10000, '\n');  
                }
            }
           

        } while (choice < 1 || choice > 5);

        return choice;
    }

};

class VendingSystem {
    Owner systemOwner;
    list<Item> Inventory;
    Customer customer;
    Item selectedItem;

public:
    VendingSystem() {}

    void setOwner(Owner o) { systemOwner = o; }
    void addItem(Item i) { Inventory.push_back(i); }

    string AskForPassword() {
        string temp;
        cout << "Please Enter Your Password:" << endl;
        cin >> temp;
        return temp;
    }
};

int main()
{
    string enteredPassword;

    //Create System
    VendingSystem myVendingMachine;
    Display systemDisplay; 
    Owner vincent("vincent", "PassWord"); 
    myVendingMachine.setOwner(vincent); 
    
    
    //Start Vending Machine
    int userChoice = systemDisplay.GetTopMenuSelection();

    if (userChoice == 1) {
        cout << "User chose to see items.\n";
    }
    else if (userChoice == 2) {
        vincent.checkPassword();
        if (vincent.PassWordCorrect() == true) {
        int adminChoice = systemDisplay.GetAdminMenuSelection();
        }
        else {
            cout << "Wrong Password." << endl;
            main();
        }
    }

    return 0;
    
      
   
}

//enteredPassword = myVendingMachine.AskForPassword();
//vincent.checkPassword(enteredPassword);
