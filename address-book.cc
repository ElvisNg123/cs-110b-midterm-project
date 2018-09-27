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

void updateContact(User address_book[], int &count)
{
    cout << "Which contact would you like to update? Please enter the name" << endl;
    string name_current;
    cin >> name_current; //input name you want to update

    bool matchFound = false;

    for (int i = 0; i < count; i++)
    {
        
        if (name_current == address_book[i].name)
        {
            cout << "Is the user you want to update " << address_book[i].name << "?" << endl;
            cout << "What is the updated name of " << address_book[i].name << "?" << endl;
            string name_temp;
            cin >> name_temp;
            

            cout << "What is the updated number?" << endl;
            string phone_temp;
            cin >> phone_temp;

            cout << "What is the updated address?" << endl;
            string address_temp;
            cin >> address_temp;

            //update entries
            address_book[i].name = name_temp;
            address_book[i].phone = phone_temp;
            address_book[i].address = address_temp;

            matchFound = true;
        }
    }
    if (!matchFound)
    {
        cout << "There was no match for that entry" << endl;
    }
}

void searchContact(User address_book[], int &count)
{
    bool matchFound = false;

    cout << "What is the full name of the user you are searching for?" << endl;

    string findName;
    cin.ignore(); 
    getline(cin, findName);

    for (int i = 0; i < count; i++)
    {
        if (address_book[i].name == findName)
        {
            cout << "Here is the user's information" << endl;
            cout << address_book[i].name << endl;
            cout << address_book[i].phone << endl;
            cout << address_book[i].address << endl;

            matchFound = true;
        }
    }

    if (!matchFound)
    {
        cout << "There was no match for that entry" << endl;
    }

}

void listAllContacts(User address_book[], int &count)
{
    for (int i = 0; i < count; i++)
    {
        cout << "User: " << i+1 << endl;
        cout << "Name: " << address_book[i].name << endl;
        cout << "Phone: " << address_book[i].phone << endl;
        cout << "Address: " << address_book[i].address << endl << endl;
    }

}

void addEntry(User address_book[], int &count)
{
    string name, phone, address;

    cout << "Add the name of the user:" << endl;
    cin.ignore(); 
    getline(cin, name);
    cout << "Add the phone of the user:" << endl;
    cin.ignore(); 
    getline(cin, phone);
    cout << "Add the address of the user:" << endl;
    cin.ignore(); 
    getline(cin, address);

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
        else if (menu_choice == 2)
        {
            updateContact(address_book, count);
        }
        else if (menu_choice == 4)
        {
            listAllContacts(address_book, count);
        }
        else if (menu_choice == 5)
        {
            searchContact(address_book, count);
        }
        else if (menu_choice == 6)
        {
            keepPlaying = false;
        }
    }
    
}