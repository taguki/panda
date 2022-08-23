
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
#define AD_TEXT 30
#define MAX_TEXT 100

void panda();
void trail();
void trail2();
void fork();
void get_text(string text[]);
void textbox_meet(string text[], int i, string name);
void meetPanda(string text[]);
void startAdventure(string text[]);
void textbox_startAdventure(string text[], int i);
void stay(string text[], int i);
void follow(string text[], int i);
void left(string text[], int i);
void right(string text[], int i);

int main() {
    string text[MAX_TEXT];
    meetPanda(text);
    startAdventure(text);
}
void meetPanda(string text[]) {
    
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
    for (i = 14; i < AD_TEXT; i++) {
        if (i == 19) {
            system("cls");
            fork();
            textbox_startAdventure(text, 19);
            cout << endl << "select an option: ";
            cin >> answer;
            if (answer == 1) {
                Sleep(1000);
                system("cls");
                left(text, i);
            }
            else if (answer == 2) {
                Sleep(1000);
                system("cls");
                right(text, i);
            }
        }
        trail2();
        textbox_startAdventure(text, i);
        Sleep(1000);
        system("cls");
    }
}

void left(string text[], int i) {
    for (i = 20; i < AD_TEXT; i++) {
        trail();
    }
}

void right(string text[], int i) {
    for (i = 20; i < AD_TEXT; i++) {
        trail();
    }
}
