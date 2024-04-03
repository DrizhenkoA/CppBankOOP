#include <iostream>
#include <string>
#define random(min,max) (min + rand() % (max - min + 1))
using namespace std;
const int SIZE = 5;

const char NUMBERS[] = { '0','1', '2', '3', '4', '5', '7','8','9' };
const string firstName[] = { "Albert","Magdes", "Pashok", "Klyaksa", "Povar","Krisa","Valenok","Glina","Klara","Sapog" };
const string lastName[] = { "Cumshotov","Lopatov", "Ayeshkin", "Kuropatkin", "Debilov","Cacyn","Goluum","Pezdov","Yaisev","Gomunkulov" };

class Client;
class Bank;



class Bank {
private:
    int size;
    int arr;



public:
    string bank = "Alpha Bank";
    void createClient(string firstName, string lastName, int age) {

        Client(firstName, lastName, age);

    }
};



class Client {
    friend class Bank;
private:

    static int lastId;

    string firstName;
    string lastName;
    int age;
    long int bankAccount;
    double balance = 0;
    int id;

    int idGenerate() {
        return lastId++;
    }



public:
    Client() {};

    Client(string firstName, string lastName, int age) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;

        int newId = idGenerate();
        this->id = newId;


    }


    void setName(string firstName) {
        this->firstName = firstName;
    }

    void setLastName(string lastName) {
        this->lastName = lastName;
    }

    void setAge(int age) {
        this->age = age;
    }

    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    int getAge() {
        return age;
    }

    long int getBankAccount() {
        return bankAccount;
    }

    double getBalance() {
        return balance;
    }

    void createBankAccount() {
        for (int i = 0; i <= 8; i++) {
            i = random(0, 9);
            bankAccount = i;
        }
    }

    void changeBalance() {
        
    }




    void showInfo() {
        cout << "Name: " << this->firstName << " " << this->lastName << endl;
        cout << "Age:  " << this->age << endl;
        cout << "Balance: " << balance << " $" << endl;
        cout << "Bank account: " << bankAccount << endl;
        cout << "ID: " << id << endl;

        cout << "\n\n";
    }


    //~Client() {                //деструктор
    //    delete[] this->balance;
    //}
};

int Client::lastId = 1;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    //Bank* bank = new Bank("Alpha Bank");


    Client cl1(firstName[random(0, 9)], lastName[random(0, 9)], random(14, 99));

    Client cl2(firstName[random(0, 9)], lastName[random(0, 9)], random(14, 99));

    Client cl3(firstName[random(0, 9)], lastName[random(0, 9)], random(14, 99));

    //Client cl2{ cl1 };

    cl1.showInfo();
    cout << "\n\n";
    cl2.showInfo();
    cout << "\n\n";
    cl3.showInfo();
    cout << "\n\n";


    //cl2.setAge(random(14, 99));
    //cl2.showInfo();






}
