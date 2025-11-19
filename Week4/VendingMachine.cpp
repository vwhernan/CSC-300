using namespace std;

#include <iostream>
#include <string>
#include <list>
#include <iterator>

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
        cout << "Enter your password: " << endl;
        cin >> temp;
        if (temp == Password) { PassWordCheck = true; }
        else { PassWordCheck = false; }
    }

    void updatePrice() {

    }
    void updateStock() {}
    void getCoinsNow() {}


};

class Customer {
    int MoneyInserted = 0;

public:

    void addCoin(int p) {
        MoneyInserted += 1;
        if (MoneyInserted < p) {
            cout << "Total Coins Input: " << MoneyInserted << endl;
        }
    }

    void returnCoins() {
        int coinsReturned = 0;

        while (MoneyInserted > 0) {
            MoneyInserted -= 1;
            coinsReturned += 1;
        }
        cout << coinsReturned << " Coins were returned";
    }

    int getTotalCoins() {
        return MoneyInserted;
    }
};


class Item {
    string name;
    int quantity;
    int price;

public:
    Item() {}
    Item(string n, int q, int p) : name(n), quantity(q), price(p) {}

    void setPrice() {}
    void setQuantity() {}

    void updateItem(string n, int q, int p) {
        name = n;
        quantity = q;
        price = p;
    }

    int getPrice() {
        return price;
    }
    string PriceToString() {
        return to_string(price) + " Coins";
    }

    string ItemToString() {
        return name + " || " + to_string(price) + " Coins";
    }

};

class Display {
public:

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

    void ItemMenu(list<Item> Inv) {
        const int width = 49;
        int rowCount = 1;
        cout << " =================================================" << endl;
        cout << "|                                                 |" << endl;
        for (Item i : Inv) {
            string text = to_string(rowCount) + ". "+ i.ItemToString();
            int padding = width - text.size() - 1;
            i.ItemToString();
            if (padding < 0) { padding = 0; }
            cout << "| " << text << string(padding, ' ') << "|" << endl;
            rowCount++;
        }
        cout << "|                                                 |" << endl;
        cout << " =================================================" << endl;
    }

    int GetItemMenuSelection(list<Item> Inv) {
        int choice = 0;
        int listSize = Inv.size();

        do {
            ItemMenu(Inv); 
            cout << "Enter your choice or 0 to exit/cancel: ";

            if (!(cin >> choice)) {
                cout << "\nInvalid input (non-number). Please enter a number.\n\n";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                choice = -1; 
                continue; 
            }
            if (choice < 0 || choice > listSize) {
                cout << "\nInvalid option. Please choose a number between 0 and " << listSize << ".\n\n";
            }
        } while (choice < 0 || choice > listSize); 
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

    list<Item>& getList() {
        return Inventory;
    }
    
    Item getSelectedItem() {
        return selectedItem;
    }
    void setSeletedItem(int i) {
        auto it = next(Inventory.begin(), i-1);
        selectedItem = *it;
    }

    void vendItem(int i, int p) {
        if (i == p) {
            cout << "Grab your item!" << endl;
            cout << "Thank you for your Purchase!" << endl;
        }

        else if (i < p) {
            int remaining = p - i;
            cout << "Please insert " << to_string(remaining) << " More Coins" << endl;
        }
    }
};

int main()
{
    string enteredPassword; //for checking the password
    int menuChoice; //used for selecting menu items
    int totalMoney; //count for total money inserted

    //Create System
    VendingSystem myVendingMachine; //creates a instance of the system
    Display systemDisplay; //creates a instance of the display
    Owner vincent("vincent", "PassWord"); //creats an owner which can used their paswword to access the admin menu
    myVendingMachine.setOwner(vincent); //assigns an owenr to the vending machine
    Customer tester; //creates a customer

    /*Create Items and Inventory -----------------------------------------
        This would be done through the admin menu, which isnt developed yet.
        The code below Manually creates and initializes 3 Items, and 
        then adds them to the Systems Inventory, which is list of items
     ---------------------------------------------------------------------*/
    Item drPepper("Dr Pepper", 10, 5);
    Item coke("Coke", 10, 20);
    Item pepsi("Pepsi", 10, 15);
    myVendingMachine.addItem(drPepper);
    myVendingMachine.addItem(coke);
    myVendingMachine.addItem(pepsi);
    
    
    //Start Vending Machine
    menuChoice = systemDisplay.GetTopMenuSelection(); //Main Menu
    
    //If user wants to buy an Item
    if (menuChoice == 1) {
       
       //Gets item choice based on menu postion 
       int itemChoice = systemDisplay.GetItemMenuSelection(myVendingMachine.getList());
       
       //Based on item choice Displays all necessary information about the item
       myVendingMachine.setSeletedItem(itemChoice);
       Item selectedItem = myVendingMachine.getSelectedItem();
       cout <<"\nSelected item: " << selectedItem.ItemToString() << endl;
       cout << "Please Enter " << selectedItem.PriceToString() << " coins" << endl;
       
       //User adds first coin
       cout << "\n";
       tester.addCoin(selectedItem.getPrice());
       totalMoney = tester.getTotalCoins();
       myVendingMachine.vendItem(totalMoney, selectedItem.getPrice());
       
       //User adds second coin
       cout << "\n";
       tester.addCoin(selectedItem.getPrice());
       totalMoney = tester.getTotalCoins();
       myVendingMachine.vendItem(totalMoney, selectedItem.getPrice());
       
       //User adds third coin
       cout << "\n";
       tester.addCoin(selectedItem.getPrice());
       totalMoney = tester.getTotalCoins();
       myVendingMachine.vendItem(totalMoney, selectedItem.getPrice());
       
       //User adds fourth coin
       cout << "\n";
       tester.addCoin(selectedItem.getPrice());
       totalMoney = tester.getTotalCoins();
       myVendingMachine.vendItem(totalMoney, selectedItem.getPrice());
       
       //User adds fifth coin
       cout << "\n";
       tester.addCoin(selectedItem.getPrice());
       totalMoney = tester.getTotalCoins();
       myVendingMachine.vendItem(totalMoney, selectedItem.getPrice());

    }
    //If user is an admin or owner
    else if (menuChoice == 2) {
        vincent.checkPassword();
        if (vincent.PassWordCorrect() == true) {
            int adminChoice = systemDisplay.GetAdminMenuSelection();
            cout << "These Features Coming Soon!!" << endl;
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
