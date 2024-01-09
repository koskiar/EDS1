//Made By Andrew Koski, Domanic Antaki, Justin Fergestad
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Person.h"
#include <iostream>
using namespace std;
int main() {
    int choice = 0;
    List<Person> List;
    Person* p;

    do {
        cout << "Linked List functions:" << std::endl;
        cout << "1. AddItem" << std::endl;
        cout << "2. GetItem" << std::endl;
        cout << "3. IsInList" << std::endl;
        cout << "4. IsEmpty" << std::endl;
        cout << "5. Size" << std::endl;
        cout << "6. SeeNext" << std::endl;
        cout << "7. SeePrev" << std::endl;
        cout << "8. SeeAt" << std::endl;
        cout << "9. Reset" << std::endl;
        cout << "10. Display" << std::endl;
        cout << "11. Quit program" << std::endl;
        cout << "Enter your choice: ";
        cin >> choice;
        while (choice < 1 || choice > 11) {
            cout << "\n Invalid input. Enter your choice again: ";
            cin >> choice;
        }
        cout << "\n" << std::endl;

        /*if block to execute the chosen function*/
        if (choice == 1) {
            string LN, FN;
            int MN, BD, GPA;
            cout << "Enter First Name: ";
            cin >> FN;
            cout << "Enter Last Name: ";
            cin >> LN;
            cout << "Enter Mnumber (ex: 12345678): ";
            cin >> MN;
            cout << "Enter GPA (0 to 5.0): ";
            cin >> GPA;
            cout << "Enter Birthday year(ex: 2004): ";
            cin >> BD;
            cout << endl;
            p = new Person(FN, LN, MN, BD, GPA);
            List.AddItem(p);
        }
        else if (choice == 2) {
            int key;
            cout << "Enter the Mnumber of the person you want to get from the list: ";
            cin >> key;
            cout << "\n";
            try {
                p = List.GetItem(key);
            }
            catch (EmptyList ex) {
                cout << ex.what() << std::endl;
                continue; //goes to next loop iteration since the list was empty
            }
            if (p == nullptr) {
                cout << "The person you were looking for wasn't found in the list." << std::endl;
            }
            else {
                cout << "The person you were looking for was found in the list, printing info:" << std::endl;
                p->Display();
            }
        }
        else if (choice == 3) {
            int key;
            cout << "Enter the SKU of the part you want to search for in the list: ";
            cin >> key;
            cout << "\n";
            bool p;
            try {
                p = List.IsInList(key);
            }
            catch (EmptyList ex) {
                cout << ex.what() << std::endl;
                continue; //goes to next loop iteration since the list was empty
            }
            if (p == false) {
                cout << "The person you were looking for wasn't found in the list." << std::endl;
            }
            else {
                cout << "The person you were looking for was found in the list." << std::endl;
            }
        }
        else if (choice == 4) {
            if (List.IsEmpty()) {
                cout << "The list is empty" << std::endl;
            }
            else {
                cout << "The list is not empty" << std::endl;
            }
        }
        else if (choice == 5) {
            cout << "The size of the list is: " << List.Size() << std::endl;
        }
        else if (choice == 6) {
            try {
                p = List.SeeNext();
            }
            catch (EmptyList ex) {
                cout << ex.what() << std::endl;
                continue; //goes to next loop iteration since the list was empty
            }

            if (p == nullptr) {
                cout << "Reached the end of the list. No item can be returned. Try using SeeAt or Reset.";
            }
            else {
                cout << "The next person in the list is:" << std::endl;
                p->Display();
            }
        }
        else if (choice == 7) {
            try {
                p = List.SeePrev();
            }
            catch (EmptyList ex) {
                cout << ex.what() << std::endl;
                continue; //goes to next loop iteration since the list was empty
            }

            if (p == nullptr) {
                cout << "Reached the end of the list. No person can be returned.";
            }
            else {
                cout << "The next person in the list is:" << std::endl;
                p->Display();
            }
        }
        else if (choice == 8) {
            int index;
            cout << "Enter the list index from where you would like to fetch a persons info: ";
            cin >> index;
            while (index < 0) {
                cout << "\nIndex has to be >= 0. Enter again: ";
                cin >> index;
            }
            cout << std::endl;
            try {
                p = List.SeeAt(index);
            }
            catch (EndOfList ex) {
                cout << ex.what() << std::endl;
                continue; //goes to next loop iteration since the end of list was reached while trying to SeeAt()
            }
            catch (EmptyList ex) {
                cout << ex.what() << std::endl;
                continue; //goes to next loop iteration since the list was empty
            }

            cout << "The part at the list index you specified is:" << std::endl;
            p->Display();
        }
        else if (choice == 9) {
            List.Reset();
            cout << "The location pointed to by the SeeNext() function has been reset." << std::endl;
        }
        else if (choice == 10) {
            try {
                List.DisplayASCII();
            }
            catch (EmptyList ex) {
                cout << ex.what() << std::endl;
                continue;
            }
        }
        cout << "\n\n";
    } while (choice != 11);
    return 0;
}
