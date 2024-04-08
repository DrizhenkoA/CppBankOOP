#include <iostream>
#include <string>
#define random(min, max) min + rand() % (max - min + 1)

using namespace std;

const int SIZE = 5;

const char NUMBERS[] = { '0','1', '2', '3', '4', '5', '7','8','9' };
const string firstName[] = { "Albert","Magdes", "Pashok", "Klyaksa", "Povar","Krisa","Valenok","Glina","Klara","Sapog" };
const string lastName[] = { "Cumshotov","Lopatov", "Ayeshkin", "Kuropatkin", "Debilov","Cacyn","Goluum","Pezdov","Yaisev","Gomunkulov" };


class Client;
class Bank;

class Client {
    friend class Bank;

private:
    static int lastId;
    int id;
    string firstName;
    string lastName;
    unsigned short age;
    string bankAccount;
    double balance = 0;

    Client() {};

    Client(string firstName, string lastName,
        unsigned short age,
        string bankAccount) {

        this->id = lastId++;
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->bankAccount = bankAccount;

    }

    void setFirstName(string fName) {
        this->firstName = fName;
    }

    string getFirstName() {
        return this->firstName;
    }

    void setLastName(string lName) {
        this->lastName = lName;
    }

    string getLastName() {
        return this->lastName;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getAge() {
        return this->age;
    }

    string getBankAccount() {
        return this->bankAccount;
    }

    void setBalance(double balance) {
        this->balance = balance;
    }

    double getBalance() {
        return this->balance;
    }

    void showInfo() {
        cout << "Name: " << this->firstName << " " << this->lastName << endl;
        cout << "Age:  " << this->age << endl;
        cout << "Balance: " << balance << " $" << endl;
        cout << "Bank account: " << bankAccount << endl;
        cout << "ID: " << id << endl;
        cout << "Balance: " << this->balance << endl;

        cout << "\n\n";
    
    }

public:
    bool operator == (const Client& client) {
        return (this->id == client.id && this->bankAccount == client.bankAccount && this->age == client.age && this->firstName == client.firstName && this->lastName == client.lastName);
    }

};

int Client::lastId = 1;

class Bank {
private:
    string name;
    Client* clients = new Client[0];
    int size = 0;


public:
    Bank(string name) {
        this->name = name;
    }

    Bank(const Bank& bank) {
        this->name == bank.name;
        
    }

    ~Bank() {
        delete[] clients;
    }

    void createClient(string firstName,
        string lastName,
        unsigned short age) {
        Client* buf = new Client[size + 1];
        for (int i = 0; i < size; i++)
        {
            buf[i] = clients[i];
        }
        delete[] clients;
        clients = buf;
        clients[size] = Client(firstName, lastName, age, createBankAccount());
        size++;
    }

    void showClients() {
        for (int i = 0; i < size; i++)
        {
            clients[i].showInfo();
        }
    }

    void showClientByID(int id) {
        for (int i = 0; i < size; i++) {
            if (clients[i].id == id) {
                clients[i].showInfo();
                return;
            }
        }
    }

    void deleteClientById(int id) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (clients[i].id == id) {
                index == i;
                break;
            }
        }
        if (index != -1) {
            deleteClientByIndex(index);
            size--;
        }
        else {
            cout << endl << "Client not found" << endl;
        }
    }

    void transaction(string sender, string taker, double value) {
        int senderIndex = -1;
        int takerIndex = -1;
        for (int i = 0; i < size; i++) 
        {
            if (clients[i].bankAccount == sender) {
                if (clients[i].balance >= value) {
                    senderIndex = i;
                    break;
                }
                else {
                    cout << "Not enough money" << endl;
                    return;
                }
            }
        }
        if (senderIndex == 1) {
            cout << "Sender not found" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            if (clients[i].bankAccount == sender) {
                takerIndex = i;
                break;
            }
            else {
                cout << "Taker not found" << endl;
                return;
            }
        }
        clients[senderIndex].balance -= value;
        clients[takerIndex].balance += value;
        cout << "Transaction completed!" << endl;
    }

    void addBalance(string bankAccount,double value) {
        for (int i = 0; i < size; i++)
        {
            if (clients[i].bankAccount == bankAccount) {

                clients[i].balance += value;
                return;
            }
        }
    }



private:

    void deleteClientByIndex(int index) {
        Client* buf = new Client[size - 1];
        for (int i = 0; i < index; i++) 
        {
            buf[i] = clients[i];
        }
        for (int i = index; i < size; i++) 
        {
            buf[i - 1] = clients[i];
        }
        delete[] clients;
        clients = buf;

    }
    string createBankAccount() {
        string bankAccount;
        do {
            bankAccount = " ";
            bankAccount += to_string(random(1000, 9999));
            bankAccount += to_string(random(1000, 9999));
        } while (checkBankAccount(bankAccount));

        return bankAccount;
    }

    bool checkBankAccount(string bankAccount) {
        for (int i = 0; i < size; i++)
        {
            if (clients[i].getBankAccount() == bankAccount) return true;
        }
        return false;
    }

};


int main()
{
    srand(time(NULL));
    Bank bank("NYBank");
    
    Bank bank2(bank);
    for (int i = 0; i < 10; i++)
    {
        bank.createClient(firstName[random(0, 9)], lastName[random(0, 9)], random(14, 99));
    }
    bank.showClients();

    cout << "\n\n";
    bank.showClientByID(5);
    bank.deleteClientById(2);
    bank.showClients();

    string bnkSender,bnkTaker;
    cin >> bnkSender >> bnkTaker;
    bank.transaction(bnkSender,bnkTaker,1000);
    bank.showClients();




}
