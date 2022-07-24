#include <iostream>
#include <string>
#include <regex>
#include <ctime>
#include <fstream>
using namespace std;

int stop()
{
    cout << "Bye!\n";
    return 0;
}

int passgen() {
    int Input;
    char c, Save;
    string password;
    srand(time(nullptr));
    regex passwd ("^[a-zA-Z0-9!-/:-@[-`]*$");
    do {
        cout << "Password lenght: ";
        cin >> Input;
        if(Input < 8)
        {
            cout << "Incorrect innput! | Minimum password lenght is 8.\n";
        }
    }while (Input < 8);

    for (int i = 0; i < Input; i++) {
        do {
            c = rand() % 94 + 33;
        } while (!regex_match(string(1, c), passwd));
        password += c;
    }
    cout << password << endl << endl;
    cout << "Do you want to save your password? | Press (y/n)";
    cin >> Save;
    if (Save == 'y')
    {
        ofstream file;
        file.open("passwd.txt");
        file << password;
        file.close();
        cout << "Password succesfully saved\n";
    }
}
int main()
{
    cout << "Random password generator!\n";
    cout << "==========================\n";
    passgen();
    char repeat;
    cout << "Do you want generate a new password? | Press (y/n)";
    cin >> repeat;
    if (repeat == 'y')
    {
        main();
    }
    else
    {
        stop();
    }
    return 0;
}
