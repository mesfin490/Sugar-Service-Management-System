#include <iostream>
#include <fstream>

using namespace std;

struct Citizen
{
    string id, name, kebele, status;
};

int main()
{
    string adminName = "Bilise", adminPassword = "1234";
    string username, password, answer, searchID;
    bool found;
    int payment;

    cout << "=== Sugar System ===\n";

    cout << "Admin Name: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    if (username != adminName || password != adminPassword)
    {
        cout << "Access Denied!" << endl;
        return 0;
    }

    cout << "Login Success." << endl;

    do
    {
        Citizen user;
        found = false;

        cout << "\nCitizen ID: ";
        cin >> searchID;

        ifstream file("citizens.txt");
        ofstream records("records.txt", ios::app);

        if (!file || !records)
        {
            cout << "File Error!" << endl;
            return 0;
        }

        while (file >> user.id >> user.name >> user.kebele >> user.status)
        {
            if (user.id == searchID)
            {
                found = true;

                cout << "\nName: " << user.name << "\nKebele: " << user.kebele << endl;

                if (user.status == "Taken")
                    cout << "Already Taken." << endl;
                else
                {
                    cout << "Payment: ";
                    cin >> payment;

                    user.status = "Taken";
                    cout << "Service Given." << endl;
                }
            }

            records << user.id << " " << user.name << " " << user.kebele << " " << user.status << endl;
        }

        file.close();
        records.close();

        remove("citizens.txt");
        rename("records.txt", "citizens.txt");

        if (!found)
            cout << "Not Found!" << endl;

        cout << "\nContinue? (yes/no): ";
        cin >> answer;

    } while (answer == "yes");

    return 0;
}