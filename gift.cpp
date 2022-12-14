
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define START_TEXT 7
#define MAX_TEXT 49

void panda();
void trail();
void trail2();
void fork();
void albert();
void doggie();
void present();
void get_text(string text[]);
void textbox_meet(string text[], int i, string name);
string meetPanda(string text[]);
void startAdventure(string text[]);
void textbox_startAdventure(string text[], int i);
void stay(string text[], int i);
void follow(string text[], int i);
void left(string text[], int i);
void meetAlbert(string text[], int i);
void right(string text[], int i);
void meetSeymour(string text[], int i);
void party(string text[], string name);

int main() {
    string text[MAX_TEXT];
    string name = meetPanda(text);
    startAdventure(text);
    party(text, name);
}
string meetPanda(string text[]) {
    
    string name;
    char present;
    int i = 0;
    for (i = 0; i < START_TEXT; i++) {
        panda();
        get_text(text);
        textbox_meet(text, i, name);
        Sleep(1000);
        if (i == 1) {
            cout << endl << endl << "enter ur name: ";
            getline(cin, name);
        }
        if (i == 5) {
            cout << endl << "would u like to open the present (y/n)? ";
            cin >> present;
            if (present == 'N' || present == 'n') {
                system("cls");
                panda();
                cout << "    ------------------------------------" << endl;
                cout << "   |                                    |" << endl;
                cout << "   |            oh. thats ok            |" << endl;
                cout << "   |                                    |" << endl;
                cout << "    ------------------------------------" << endl;
                Sleep(1000);
                system("cls");
                panda();
                cout << "    ------------------------------------" << endl;
                cout << "   |                                    |" << endl;
                cout << "   |        maybe another time :(       |" << endl;
                cout << "   |                                    |" << endl;
                cout << "    ------------------------------------" << endl;
                Sleep(1000);
                exit(0);
            }
        }
        system("cls");
    }
    return name;
}

void panda(){
    string line = "";
    ifstream openPanda;
    openPanda.open("panda.txt");

    if (openPanda.is_open()) {
        while (getline(openPanda, line)) {
            cout << line << endl;
        }
    }
    cout << endl << endl;
}

void trail() {
    string line = "";
    ifstream openTrail;
    openTrail.open("trail.txt");

    if (openTrail.is_open()) {
        while (getline(openTrail, line)) {
            cout << line << endl;
        }
    }
    cout << endl << endl;
}

void trail2() {
    string line = "";
    ifstream openTrail2;
    openTrail2.open("trail2.txt");

    if (openTrail2.is_open()) {
        while (getline(openTrail2, line)) {
            cout << line << endl;
        }
    }
    cout << endl << endl;
}

void fork() {
    string line = "";
    ifstream openfork;
    openfork.open("fork.txt");

    if (openfork.is_open()) {
        while (getline(openfork, line)) {
            cout << line << endl;
        }
    }
    cout << endl << endl;
}

void albert() {
    string line = "";
    ifstream openAlbert;
    openAlbert.open("bee.txt");

    if (openAlbert.is_open()) {
        while (getline(openAlbert, line)) {
            cout << line << endl;
        }
    }
    cout << endl << endl;
}


void doggie() {
    string line = "";
    ifstream openDog;
    openDog.open("dog.txt");

    if (openDog.is_open()) {
        while (getline(openDog, line)) {
            cout << line << endl;
        }
    }
    cout << endl << endl;
}

void present() {
    string line = "";
    ifstream openGift;
    openGift.open("present.txt");

    if (openGift.is_open()) {
        while (getline(openGift, line)) {
            cout << line << endl;
        }
    }
    cout << endl << endl;
}

void get_text(string text[]) {
    ifstream openText;
    openText.open("text.txt");
    int i = 0;
    while (!openText.eof() && i < MAX_TEXT) {
        getline(openText, text[i]);
        i++;
    }
}

void textbox_meet(string text[], int i, string name) {
    if (i == 2) {

        cout << "    ------------------------------------" << endl;
        cout << "   |                                    |" << endl;
        cout << "   |              " << name << text[i] << "              |" << endl;
        cout << "   |                                    |" << endl;
        cout << "    ------------------------------------" << endl;
    }

    else {
        cout << "    ------------------------------------" << endl;
        cout << "   |                                    |" << endl;
        cout << "   |" << text[i] << "|" << endl;
        cout << "   |                                    |" << endl;
        cout << "    ------------------------------------" << endl;
    }
}


void startAdventure(string text[]) {
    int answer;
    for (int i = START_TEXT; i < 11; i++) {
        trail();
        get_text(text);
        textbox_startAdventure(text, i);
        Sleep(1000);
        if (i == 10) {
            cout << endl <<  "select an option: ";
            cin >> answer;
            if (answer == 1) {
                system("cls");
                stay(text, i);
            }
            else if (answer == 2) {
                system("cls");
                follow(text, i);
            }
        }
        system("cls");
    }
}

void textbox_startAdventure(string text[], int i) {
    cout << "    ------------------------------------" << endl;
    cout << "   |                                    |" << endl;
    cout << "   |" << text[i] << "|" << endl;
    cout << "   |                                    |" << endl;
    cout << "    ------------------------------------" << endl;
}

void stay(string text[], int i) {
    int c = 1;
    while (c == 1) {

        for (i = 11; i < 13; i++) {
            trail();
            textbox_startAdventure(text, i);
            Sleep(1000);
            system("cls");
        }

        trail();
        textbox_startAdventure(text, 10);
        cout << endl << "select an option: ";
        cin >> c;
        system("cls");
        if (c != 1 && c != 2) {
            trail();
            textbox_startAdventure(text, 10);
            cout << endl << "invaild option. please select [1] or [2]";
            Sleep(2000);
            system("cls");
            trail();
            textbox_startAdventure(text, 10);
            cout << endl << "select an option: ";
            cin >> c;
            system("cls");
        }
    }
    
    trail();
    textbox_startAdventure(text, 13);
    Sleep(1000);
    system("cls");
    follow(text, i);
   
}

void follow(string text[], int i) {
    int answer;
    for (i = 14; i < 20; i++) {

        trail2();
        textbox_startAdventure(text, i);
        Sleep(1000);
        system("cls");
    }
    system("cls");
    fork();
    textbox_startAdventure(text, 19);
    cout << endl << "select an option: ";
    cin >> answer;
    if (answer == 1) {
        system("cls");
        left(text, i);
    }
    else if (answer == 2) {
        system("cls");
        right(text, i);
    }
}

void left(string text[], int i) {
    for (i = 20; i < 25; i++) {
        trail();
        textbox_startAdventure(text, i);
        Sleep(1000);
        system("cls");
        if (i == 24) {
            meetAlbert(text, i);
        }
    }
}

void meetAlbert(string text[], int i) {
    char follow;
    for (i = 25; i < 34; i++) {
        albert();
        textbox_startAdventure(text, i);
        if (i == 33) {
            cout << "would you like to follow the bee (y/n)? ";
            cin >> follow;
            if (follow == 'y' || follow == 'Y') {
                break;
            }
            else if (follow == 'n' || follow == 'N') {
                system("cls");
                int c = 0;
                i = 34;
                while (c < 2) {
                    trail2();
                    textbox_startAdventure(text, i);
                    Sleep(1000);
                    system("cls");
                    c++;
                    i++;
                }
                right(text, i);
                break;
            }
            else {
                cout << endl << "invaild option. please select 'y' or 'n'";
            }

            Sleep(1000);
            system("cls");
            albert();
            textbox_startAdventure(text, 33);
        }
        Sleep(1000);
        system("cls");
    }
}

void right(string text[], int i) {
    system("cls");
    for (i = 36; i < 40; i++) {
        trail();
        textbox_startAdventure(text, i);
        Sleep(1000);
        system("cls");
    }
    meetSeymour(text, i);
   
}

void meetSeymour(string text[], int i) {
    for (i = 40; i < 44; i++) {
        doggie();
        textbox_startAdventure(text, i);
        Sleep(1000);
        system("cls");
    }
}

void party(string text[], string name) {
    char answer;
    for (int i = 44; i < MAX_TEXT; i++) {
        trail2();
        textbox_startAdventure(text, i);
        Sleep(1000);
        system("cls");
    }
    present();
    textbox_startAdventure(text, 5);
    cout << "would you like to open the present (y/n)? ";
    cin >> answer;
    if (answer == 'N' || answer == 'n') {
        system("cls");
        present();
        cout << "    ------------------------------------" << endl;
        cout << "   |                                    |" << endl;
        cout << "   |            oh. thats ok            |" << endl;
        cout << "   |                                    |" << endl;
        cout << "    ------------------------------------" << endl;
        Sleep(1000);
        system("cls");
        present();
        cout << "    ------------------------------------" << endl;
        cout << "   |                                    |" << endl;
        cout << "   |        maybe another time :(       |" << endl;
        cout << "   |                                    |" << endl;
        cout << "    ------------------------------------" << endl;
        Sleep(1000);
        exit(0);
    }
    else {
        system("cls");
        panda();
        cout << "happy birthday " << name << "!!!" << endl;
    }
}
