#include <iostream>
#include <string>
using namespace std;

void displayMenu();
//void addEntry(User[]);

class User
{
    public:
        string name;
        string address;
        string phone;

};

void listAllContacts(User address_book[], int &count)
{
    cout << "count=" << count << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "User: " << count << endl;
        cout << "Name: " << address_book[i].name << endl;
        cout << "Phone: " << address_book[i].phone << endl;
        cout << "Address: " << address_book[i].address << endl << endl;
    }

}

void addEntry(User address_book[], int &count)
{
    string name, phone, address;

    cout << "Add the name of the user:" << endl;
    cin >> name;
    cout << "Add the phone of the user:" << endl;
    cin >> phone;
    cout << "Add the address of the user:" << endl;
    cin >> address;

    // create instance of class user
    User newUser;

    //add in attributes to instance
    newUser.name = name;
    newUser.phone = phone;
    newUser.address = address;
   
   address_book[count] = newUser;
   count++;

   cout << "User successfully added to address book" << endl << endl;
     
}

void displayMenu()
{

    cout << "Menu" << endl;
    cout << "1) Add new contact" << endl;
    cout << "2) Update existing contact" << endl;
    cout << "3) Delete contact" << endl;
    cout << "4) List all contacts" << endl;
    cout << "5) Search for a contact" << endl;
    cout << "6) Quit" << endl;

}




int main(){

    bool keepPlaying = true;
    User address_book[100];
    int count = 0;

    while (keepPlaying) {
        displayMenu();
        

        int menu_choice;
        cout << "Please choose an option";
        cin >> menu_choice;

        //address book array

        if (menu_choice == 1)
        {
            addEntry(address_book, count);
        } 
        else if (menu_choice == 4)
        {
            listAllContacts(address_book, count);
        }
        else if (menu_choice == 6)
        {
            keepPlaying = false;
        }
    }
    
}