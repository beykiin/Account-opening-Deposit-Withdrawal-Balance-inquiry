// Account opening, Deposit, Withdrawal, Balance inquiry.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct BankAccount {

    string accountNumber;
    string ownerName;
    double balance;

};

void openAcoount(vector<BankAccount>& accounts) {

    BankAccount newAccount;
    cout << "Acoount Number: ";
    cin >> newAccount.accountNumber;
    cout << "Owner Name: ";
    cin >> newAccount.ownerName;
    newAccount.balance = 0.0;

    accounts.push_back(newAccount);
    cout << "Account opened successfully." << endl;

}

void deposit(vector<BankAccount>& accounts, const string& accountNumber, double amount) {

    for (auto& account : accounts) {

        if (account.accountNumber == accountNumber) {

            account.balance += amount;
            cout << "Deposit successful. New balance: " << account.balance << endl;
            return;

        }

    }

    cout << "Account not found!" << endl;

}

void withdraw(vector<BankAccount>& accounts, const string& accountNumber, double amount){

    for (auto account : accounts) {

        if (account.accountNumber == accountNumber) {

            if (account.balance >= amount) {

                account.balance -= amount;
                cout << "Withdrawal successful. New balance: " << account.balance << endl;

            }else {

                cout << "Insufficient balance." << endl;

            }

            return;

        }

    }

    cout << "Account not found." << endl;

}

void checkBalance(const vector<BankAccount>& accounts, const string& accountNumber) {

    for (const auto& account : accounts) {

        if (account.accountNumber == accountNumber) {

            cout << "Balance: " << account.balance << endl;
            return;

        }

    }

    cout << "Account not found." << endl;

}

int main()
{
    vector<BankAccount> accounts;
    while (true) {

        cout << "1. Open account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Check balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Make your selection: ";

        int choice;
        cin >> choice;

        switch (choice) {

            case 1:
                openAcoount(accounts);
                break;
            case 2: {
                string accountNumber;
                double amount;
                cout << "Account Number: ";
                cin >> accountNumber;
                cout << "Amount: ";
                cin >> amount;
                deposit(accounts, accountNumber, amount);
                break;
            }

            case 3: {

                string accountNumber;
                double amount;
                cout << "Account Number: ";
                cin >> accountNumber;
                cout << "Amount: ";
                cin >> amount;
                withdraw(accounts, accountNumber, amount);
                break;

            }

            case 4: {

                string accountNumber;
                cout << "Account Number: ";
                cin >> accountNumber;
                checkBalance(accounts, accountNumber);
                break;

            }

            case 5:

                cout << "Exiting the program..." << endl;
                return 0;

            default:
                cout << "Invalid Selection!" << endl;
                break;
        }

    }

    return 0;

}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
