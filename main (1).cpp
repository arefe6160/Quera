#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class User {
public:
    string firstName, lastName;
    vector<string> phoneNumbers;
    vector<User*> contacts;
    vector<User*> blockedContacts;

   User(string f, string l, vector<string> phones) {
    firstName = f;
    lastName = l;
    phoneNumbers = phones;
}
    string fullName() const {
        return firstName + " " + lastName;
    }
void addContact(User* contact) {
    for (size_t i = 0; i < contacts.size(); ++i) {
        if (contacts[i] == contact) {
            cout << "addContactError\n";
            return;}
}
    contacts.push_back(contact);
    cout << "Contact added to " << fullName() << "\n";
}
  void print() const {
    cout << fullName() << ":\n";
    size_t i = 0;
    while (i < phoneNumbers.size()) {
        cout << " - " << phoneNumbers[i] << "\n";
        ++i;}
}
void blockContact(User* contact) {
    for (User* c : contacts) {
        if (c == contact) {
            for (User* b : blockedContacts) {
                if (b == contact) {
                    cout << "blockError\n";
                    return;}
            }
            blockedContacts.push_back(contact);
            cout << "Contact blocked in " << fullName() << "\n";
            return;}
    }
    cout << "blockError\n";
}

void unblockContact(User* contact) {
    for (auto it = blockedContacts.begin(); it != blockedContacts.end(); ++it) {
        if (*it == contact) {
            blockedContacts.erase(it);
            cout << "Contact unblocked in " << fullName() << "\n";
            return;}
    }
    cout << "unblockError\n";
}
void specificContact(User* contact) {
    for (int i = 0; i < blockedContacts.size(); ++i) {
        if (blockedContacts[i] == contact) {
            blockedContacts.erase(blockedContacts.begin() + i);
            cout << "Contact specific-unblocked in " << fullName() << "\n";
            return;
        }
    }
    cout << "specificError\n";
}

void unspecificContact(User* contact) {
    bool isContact = false;
    for (int i = 0; i < contacts.size(); ++i) {
        if (contacts[i] == contact) {
            isContact = true;
            break;
        }
    }

    if (!isContact) {
        cout << "unspecificError\n";
        return;
    }

    for (int i = 0; i < blockedContacts.size(); ++i) {
        if (blockedContacts[i] == contact) {
            blockedContacts.erase(blockedContacts.begin() + i);
            break;
        }
    }

    cout << "Contact set to normal in " << fullName() << "\n";
}
void listContacts(const string& type) {
    if (contacts.empty()) return;

    if (type != "first-name" && type != "last-name") {
        cout << "listContactsError\n";
        return;
    }

    vector<User*> sortedContacts = contacts;

    sort(sortedContacts.begin(), sortedContacts.end(), [type](User* a, User* b) {
        return (type == "first-name") ? a->firstName < b->firstName
                                      : a->lastName < b->lastName;
    });

    for (User* contact : sortedContacts) {
        contact->print();
    }
}

};

class Server {
    map<string, User*> users;

public:
   void join(const string& first, const string& last, const vector<string>& phones) {
    string key = first + " " + last;
    if (users.find(key) != users.end() || phones.size() == 0) {
        cout << "joinError\n";
        return;
    }

    User* newUser = new User(first, last, phones);
    users[key] = newUser;

    cout << "User " << key << " joined.\n";
}
   void search(const string& arg1, const string& arg2 = "") {
    string query;
    if (arg2 == "") {
        query = arg1;
    } else {
        query = arg1 + " " + arg2;
    }

    bool found = false;

    for (map<string, User*>::iterator it = users.begin(); it != users.end(); ++it) {
        User* user = it->second;
        if (user->fullName() == query) {
            user->print();
            found = true;
        }
        else {
            for (size_t i = 0; i < user->phoneNumbers.size(); ++i) {
                if (user->phoneNumbers[i] == arg1) {
                    user->print();
                    found = true;
                    break;
                }
            }
        }
    }
    if (!found) {
        cout << "searchError\n";
    }
}
    void addContact(const string& userFull, const string& contactFull) {

    if (users.count(userFull) == 0) {
        cout << "addContactError\n";
        return;
    }

    if (users.count(contactFull) == 0) {
        cout << "addContactError\n";
        return;
    }
    User* user = users[userFull];
    User* contact = users[contactFull];

    user->addContact(contact);
}
void removeByName(const string& first, const string& last) {
    string key = first + " " + last;
    if (users.find(key) == users.end()) {
        cout << "removeError\n";
        return;
    }

    User* target = users[key];

    for (auto& pair : users) {
        User* user = pair.second;
        vector<User*>& cList = user->contacts;
        for (int i = 0; i < cList.size(); ++i) {
            if (cList[i] == target) {
                cList.erase(cList.begin() + i);
                --i;
            }
        }
    }

    delete target;
    users.erase(key);
    cout << "User " << key << " removed.\n";
}
void removeByPhone(const string& phone) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        User* u = it->second;
        bool found = false;
        for (int i = 0; i < u->phoneNumbers.size(); ++i) {
            if (u->phoneNumbers[i] == phone) {
                found = true;
                break;
            }
        }

        if (found) {
            User* target = u;

            for (auto& pair : users) {
                User* user = pair.second;
                vector<User*>& cList = user->contacts;
                for (int i = 0; i < cList.size(); ++i) {
                    if (cList[i] == target) {
                        cList.erase(cList.begin() + i);
                        --i;
                    }
                }
            }

            delete target;
            users.erase(it);
            cout << "User with phone " << phone << " removed.\n";
            return;
        }
    }
    cout << "removeError\n";
}
void listUsers(const string& sortBy) {
    vector<User*> userList;
    for (auto& pair : users) userList.push_back(pair.second);

    for (int i = 0; i < userList.size(); ++i) {
        for (int j = i + 1; j < userList.size(); ++j) {
            if ((sortBy == "first-name" && userList[i]->firstName > userList[j]->firstName) ||
                (sortBy == "last-name" && userList[i]->lastName > userList[j]->lastName)) {
                swap(userList[i], userList[j]);
            }
        }
    }
    for (int i = 0; i < userList.size(); ++i)
        userList[i]->print();
}
void block(const string& userFull, const string& contactFull) {
    if (users.find(userFull) == users.end() || users.find(contactFull) == users.end()) {
        cout << "blockError\n";
        return;
    }
    User* user = users[userFull];
    User* contact = users[contactFull];
    bool inContacts = false;
    for (int i = 0; i < user->contacts.size(); ++i) {
        if (user->contacts[i] == contact) {
            inContacts = true;
            break;
        }
    }
    if (!inContacts) {
        cout << "blockError\n";
        return;
    }

    for (int i = 0; i < user->blockedContacts.size(); ++i) {
        if (user->blockedContacts[i] == contact) {
            cout << "blockError\n";
            return;
        }
    }
    user->blockedContacts.push_back(contact);
    cout << "Contact blocked in " << user->fullName() << "\n";
}
void unblock(const string& userFull, const string& contactFull) {
    if (users.find(userFull) == users.end() || users.find(contactFull) == users.end()) {
        cout << "unblockError\n";
        return;
    }
    User* user = users[userFull];
    User* contact = users[contactFull];

    bool found = false;
    for (int i = 0; i < user->blockedContacts.size(); ++i) {
        if (user->blockedContacts[i] == contact) {
            user->blockedContacts.erase(user->blockedContacts.begin() + i);
            cout << "Contact unblocked in " << user->fullName() << "\n";
            return;
        }
    }
    cout << "unblockError\n";
}
void specific(const string& userFull, const string& contactFull) {
    if (users.find(userFull) == users.end() || users.find(contactFull) == users.end()) {
        cout << "specificError\n";
        return;
    }
    users[userFull]->specificContact(users[contactFull]);
}

void unspecific(const string& userFull, const string& contactFull) {
    if (users.find(userFull) == users.end() || users.find(contactFull) == users.end()) {
        cout << "unspecificError\n";
        return;
    }
    users[userFull]->unspecificContact(users[contactFull]);
}

void listContacts(const string& userFull, const string& type) {
    if (users.find(userFull) == users.end()) {
        cout << "listContactsError\n";
        return;
    }
    users[userFull]->listContacts(type);
}

};
vector<string> splitWords(const string& line) {
    vector<string> words;
    string word = "";
    for (char ch : line) {
        if (ch == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        } else {
            word += ch;
        }
    }
    if (!word.empty()) words.push_back(word);
    return words;
}

int main() {
    Server server;
    string line;

    while (getline(cin, line)) {
        vector<string> tokens = splitWords(line);
        if (tokens.empty()) continue;

        string command = tokens[0];

        if (command == "join") {
            if (tokens.size() < 4) {
                cout << "joinError\n";
                continue;
            }
            string first = tokens[1];
            string last = tokens[2];
            vector<string> phones(tokens.begin() + 3, tokens.end());
            server.join(first, last, phones);
        }
        else if (command == "search") {
            if (tokens.size() == 2) {
                server.search(tokens[1]);
            } else if (tokens.size() == 3) {
                server.search(tokens[1], tokens[2]);
            } else {
                cout << "searchError\n";
            }
        }
        else if (command == "addContact") {
    size_t pos = line.find("addContact");
    string rest = line.substr(pos + 10);
    size_t colon = rest.find(':');

    if (colon == string::npos) {
        cout << "addContactError\n";
        continue;
    }
    string user = rest.substr(0, colon);
    string contact = rest.substr(colon + 1);

    while (!user.empty() && isspace(user.front())) user.erase(0, 1);
    while (!user.empty() && isspace(user.back())) user.pop_back();
    while (!contact.empty() && isspace(contact.front())) contact.erase(0, 1);
    while (!contact.empty() && isspace(contact.back())) contact.pop_back();

    server.addContact(user, contact);
}

        else if (command == "remove") {
    if (tokens.size() == 3) {
        string first = tokens[1];
        string last = tokens[2];
        server.removeByName(first, last);
    } else if (tokens.size() == 2) {
        string phone = tokens[1];
        server.removeByPhone(phone);
    } else {
        cout << "removeError\n";
    }
}
else if (command == "listUsers") {
    if (tokens.size() != 2) {
        cout << "Unknown command\n";
    } else {
        string sortType = tokens[1];
        server.listUsers(sortType);
    }
}
else if (command == "block" || command == "unblock") {
    if (tokens.size() < 4) {
        cout << command << "Error\n";
        continue;
    }

    string user = tokens[1] + " " + tokens[2];
    string contact = tokens[3];
    for (int i = 4; i < tokens.size(); ++i)
        contact += " " + tokens[i];

    if (command == "block")
        server.block(user, contact);
    else
        server.unblock(user, contact);
}
else if (command == "specific" || command == "unspecific") {
    string rest = line.substr(command.length());
    size_t colon = rest.find(':');

    if (colon == string::npos) {
        cout << command << "Error\n";
        continue;
    }

    string user = rest.substr(0, colon);
    string contact = rest.substr(colon + 1);

    while (!user.empty() && isspace(user.back())) user.pop_back();
    while (!contact.empty() && isspace(contact.front())) contact.erase(0, 1);

    if (command == "specific")
        server.specific(user, contact);
    else
        server.unspecific(user, contact);
}
else if (command == "listContacts") {
    if (tokens.size() == 4) {
        string first = tokens[1];
        string last = tokens[2];
        string sortType = tokens[3];
        string fullName = first + " " + last;
        server.listContacts(fullName, sortType);
    } else {
        cout << "listContactsError\n";
    }
}
    else {
            cout << "Unknown command\n";
        }
    }
    return 0;
}
