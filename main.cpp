#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    int id;
    string name;
    string phone;
    string email;
};

int main() {
    vector<Contact> contacts;

    cout << "===========================\n\n";

    char choice = 'x';
    int nextId = 1;
    int IDchoice;
    char editChoice;

    while (choice != 'q') {
        cout << "Was moechtest du tun? (o, a, e, d, s, q): ";
        cin >> choice;

        if (choice == 'o') {
            cout << "===========================\n\n";
            cout << "Hier sind alle Kontakte!\n";
            for (int i = 0; i < (int)contacts.size(); i++) {
                cout << contacts[i].id << " - " << contacts[i].name << " - "
                     << contacts[i].phone << " - " << contacts[i].email << "\n";
            }
            cout << "===========================\n\n";
        }
        else if (choice == 'a') {
            Contact temp;
            temp.id = nextId;
            nextId++;

            cout << "===========================\n\n";
            cout << "Fuege einen neuen Namen hinzu:\n";
            cin >> temp.name;

            cout << "===========================\n\n";
            cout << "Fuege Handynummer hinzu:\n";
            cin >> temp.phone;

            cout << "===========================\n\n";
            cout << "Fuege E-Mail hinzu:\n";
            cin >> temp.email;

            contacts.push_back(temp);

            cout << "\nSuper! Nutzer wurde registriert!\n";
        }
        else if (choice == 'e') {
            bool submit = false;

            while (!submit) {
                if (contacts.empty()) {
                    cout << "Keine Kontakte vorhanden.\n";
                    break;
                }

                cout << "===========================\n\n";
                cout << "Tippe die ID, die du bearbeiten moechtest.\n";
                for (int i = 0; i < (int)contacts.size(); i++) {
                    cout << contacts[i].id << " - " << contacts[i].name << "\n";
                }

                cin >> IDchoice;

                bool foundId = false;

                for (int i = 0; i < (int)contacts.size(); i++) {
                    if (contacts[i].id == IDchoice) {
                        foundId = true;

                        cout << "===========================\n\n";
                        cout << "Welchen Attributswert moechtest du bearbeiten? (n, p, e)\n";
                        cin >> editChoice;

                        if (editChoice == 'n') {
                            cout << "Neuer Name: ";
                            cin >> contacts[i].name;
                            submit = true;
                        }
                        else if (editChoice == 'p') {
                            cout << "Neue Telefonnummer: ";
                            cin >> contacts[i].phone;
                            submit = true;
                        }
                        else if (editChoice == 'e') {
                            cout << "Neue E-Mail: ";
                            cin >> contacts[i].email;
                            submit = true;
                        }
                        else {
                            cout << "Wert nicht erkannt.\n";
                        }

                        break;
                    }
                }

                if (!foundId) {
                    cout << "ID nicht gefunden.\n";
                }
            }
        }
        else if (choice == 'd') {
            if (contacts.empty()) {
                cout << "Keine Kontakte vorhanden.\n";
                continue;
            }

            cout << "===========================\n\n";
            cout << "Tippe die ID, die du loeschen moechtest.\n";
            for (int i = 0; i < (int)contacts.size(); i++) {
                cout << contacts[i].id << " - " << contacts[i].name << "\n";
            }

            cin >> IDchoice;

            bool deleted = false;

            for (int i = 0; i < (int)contacts.size(); i++) {
                if (contacts[i].id == IDchoice) {
                    contacts.erase(contacts.begin() + i);
                    deleted = true;
                    break;
                }
            }

            if (!deleted) {
                cout << "ID nicht gefunden.\n";
            }
        }
        else if (choice == 's') {
            if (contacts.empty()) {
                cout << "Keine Kontakte vorhanden.\n";
                continue;
            }

            char searchSelect;
            cout << "===========================\n\n";
            cout << "Nach welchem Wert moechtest du suchen? (n/p/e)\n";
            cin >> searchSelect;

            bool found = false;

            if (searchSelect == 'n') {
                string q;
                cout << "Suche nach Name: ";
                cin >> q;

                for (int i = 0; i < (int)contacts.size(); i++) {
                    if (contacts[i].name.find(q) != string::npos) {
                        cout << contacts[i].id << " - " << contacts[i].name << " - "
                             << contacts[i].phone << " - " << contacts[i].email << "\n";
                        found = true;
                    }
                }
            }
            else if (searchSelect == 'p') {
                string q;
                cout << "Suche nach Telefon: ";
                cin >> q;

                for (int i = 0; i < (int)contacts.size(); i++) {
                    if (contacts[i].phone.find(q) != string::npos) {
                        cout << contacts[i].id << " - " << contacts[i].name << " - "
                             << contacts[i].phone << " - " << contacts[i].email << "\n";
                        found = true;
                    }
                }
            }
            else if (searchSelect == 'e') {
                string q;
                cout << "Suche nach E-Mail: ";
                cin >> q;

                for (int i = 0; i < (int)contacts.size(); i++) {
                    if (contacts[i].email.find(q) != string::npos) {
                        cout << contacts[i].id << " - " << contacts[i].name << " - "
                             << contacts[i].phone << " - " << contacts[i].email << "\n";
                        found = true;
                    }
                }
            }
            else {
                cout << "Wert nicht erkannt.\n";
                continue;
            }

            if (!found) {
                cout << "Kein Treffer gefunden.\n";
            }
        }
        else if (choice != 'q') {
            cout << "Ungueltige Eingabe.\n";
        }

        cout << "\n";
    }

    return 0;
}
