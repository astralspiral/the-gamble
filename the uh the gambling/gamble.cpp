#include <cstdlib>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <limits>
#include <vector>



// cloud rap jako zivotni styl
// cloud rap jako zivotni styl
// cloud rap jako zivotni styl
// cloud rap jako zivotni styl
// cloud rap jako zivotni styl

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::numeric_limits;
using std::streamsize;
using std::vector;

int moners = 100;



void mainloop();

void nahodnecislo(); 

void coinflip(); 

void blackjack();

void ruleta();




void mainloop() {
    int akce;

    if (moners == 0 || moners < 0) {
        system("cls");
        cout << "TY ZMRDE PROGAMBLILS VSECHNY PRACHY" << endl;
        system("pause");
        exit(0);
    }

    system("cls");
    cout << "co si prejes udelat za akci" << endl;
    cout << "tve jmeni: " << moners << "$" << endl;
    cout << "1. sazeni s 10 cisly" << endl;
    cout << "2. coinflip" << endl;
    cout << "3. blackjack" << endl;

    cout << "> ";
    
    if (!(cin >> akce)) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        cout << "hrej bracho neco si udelal spatne zkus to zrobit znovu" << endl;
        system("pause");
        mainloop(); 
        return;
    }

    switch (akce)
    {
    case 1:
        nahodnecislo();
        break;
    
    case 2:
        coinflip();
        break;
    case 3:
        blackjack();
        break;

    default:
        cout << "hej brasko tos asi to to mozna takovy cislo tam este ani neni nebo tak" << endl;
        mainloop();
        break;
    }
}

void coinflip() {
    system("cls");
    srand(time(0));

    int coinflipmoners;
    
    cout << "";

    string flip;
    string heads[2] = {"heads", "h"};
    string tails[2] = {"tails", "t"};
    int maxflip = 2;
    int coinfliprannumber = rand() % maxflip;
    


    cout << "heads or tails" << endl;
    cout << "> ";
    cin >> flip;
    if (flip != heads[0] && flip != heads[1] && flip != tails[1] && flip != tails[0]) {
        cout << "hej zkus napsat heads nebo tails." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("pause");
        coinflip();
    }

    while (true) {
        cout << "kolik penez na toto cislo chces vsadit, k dispozici mas " << moners << "$" << endl;
        cout << "> ";
        if (!(cin >> coinflipmoners)) {
            cout << "hej kamo tos moc nezadal kolik chces vsadit" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            continue;

        }
        if (coinflipmoners > moners) {
            cout << "bro tolik penez ani nemas :-D" << endl;
            continue;
        }
        break;
    }
    

    

    cout << "flipping..." << endl;
    Sleep(2300);
    cout << "and the side is..." << endl;
    Sleep(5000);
    system("cls");
    if (coinfliprannumber == 0) {
        cout << "heads." << endl;

        if (flip == tails[0] || flip == tails[1]) {
            Sleep(500);
            cout << "ouuuu prohral si vsechny sve penize" << endl;
            Sleep(500);
            moners = moners - coinflipmoners;
            cout << "tve penize jsou nyni " << moners << "$" << " prohral si " << coinflipmoners << "$" << endl;
        }
        else if (flip == heads[0] || flip == heads[1]) {
            Sleep(500);
            cout << "OUUU vyhral si 200% svych vsazenych moners" << endl;
            Sleep(500);
            moners = moners + (coinflipmoners * 2);
            cout << "tve penize jsou nyni " << moners << "$" << " vyhral si " << (coinflipmoners * 2) << "$" << endl;
        }  
    }
    else if (coinfliprannumber == 1) {
        cout << "tails" << endl;

        if (flip == heads[0] || flip == heads[1]) {
            Sleep(500);
            cout << "ouuuu prohral si vsechny sve penize" << endl;
            Sleep(500);
            moners = moners - coinflipmoners;
            cout << "tve penize jsou nyni " << moners << "$" << " prohral si " << coinflipmoners << "$" << endl;

            
        }
        else if (flip == tails[0] || flip == tails[1]) {
            Sleep(500);
            cout << "OUUU vyhral si 200% svych vsazenych moners" << endl;
            Sleep(500);
            moners = moners + (coinflipmoners * 2);
            cout << "tve penize jsou nyni " << moners << "$" << " vyhral si " << (coinflipmoners * 2) << "$" << endl;

        }   
    }

    system("pause");
    mainloop();
}

void nahodnecislo() {
    system("cls");



    int nahodnecisl;
    int vsazenemoners;
    int vyhra;

    srand(time(0));

    cout << "vybral sis hru betting" << endl;

    while (nahodnecisl > 10 || nahodnecisl < 1) {
        
        cout << "vyber si cislo od 1 do 10" << endl;

        cout << "> ";
        cin >> nahodnecisl;

        if (nahodnecisl > 10 || nahodnecisl < 1) {
            cout << "Zadal si moc velke cislo, zkus to znovu" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            continue;
        }
        break;
    }

    
    while (true) {
        cout << "kolik penez na toto cislo chces vsadit, k dispozici mas " << moners << "$" << endl;
        cout << "> ";
        if (!(cin >> vsazenemoners)) {
            cout << "hej kamo tos moc nezadal kolik chces vsadit" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            continue;

        }
        
        if (vsazenemoners > moners) {
            cout << "bro tolik penez ani nemas :-D" << endl;
            continue;
        }
        break;
    }
    
    
   
    moners = moners - vsazenemoners;
    cout << "vsadil si " << vsazenemoners << " tve penize jsou nyni " << moners << endl;


    int vyhernecisla[4] = {};
    int j = 0;
    int maximalnicislo = 10;

    while (j < 4) {
        vyhernecisla[j] = rand() % maximalnicislo;
        j++;
    }

    int x = 0;
    while (x < 4) {
        cout << vyhernecisla[x] << " ";  
        x++;
    }
    cout << endl;

    if (nahodnecisl == vyhernecisla[0] && nahodnecisl == vyhernecisla[1] &&
    nahodnecisl == vyhernecisla[2] && nahodnecisl == vyhernecisla[3])
    {
        cout << "vyhral si jackpot, tva vyhra je 2000% vsazene castky" << endl;
        vyhra = vsazenemoners * 20;
        moners = moners + vyhra;
        cout << "vyhral si " << vyhra << "penez, nyni mas " << moners << "$" << endl;
        
    }

    else if (nahodnecisl == vyhernecisla[0] && nahodnecisl == vyhernecisla[1] && nahodnecisl == vyhernecisla[2] ||
    nahodnecisl == vyhernecisla[0] && nahodnecisl == vyhernecisla[1] && nahodnecisl == vyhernecisla[3] ||
    nahodnecisl == vyhernecisla[0] && nahodnecisl == vyhernecisla[2] && nahodnecisl == vyhernecisla[3] ||
    nahodnecisl == vyhernecisla[1] && nahodnecisl == vyhernecisla[2] && nahodnecisl == vyhernecisla[3])
    {

        cout << "vyhral si 800%" << endl;
        vyhra = vsazenemoners * 8;
        moners += vyhra;
        cout << "vyhral si " << vyhra << "$, nyni mas " << moners << "$" << endl;
        
    }

    else if (nahodnecisl == vyhernecisla[0] && nahodnecisl == vyhernecisla[1] ||
        nahodnecisl == vyhernecisla[0] && nahodnecisl == vyhernecisla[2] ||
        nahodnecisl == vyhernecisla[0] && nahodnecisl == vyhernecisla[3] || 
        nahodnecisl == vyhernecisla[1] && nahodnecisl == vyhernecisla[2] ||
        nahodnecisl == vyhernecisla[1] && nahodnecisl == vyhernecisla[3] ||
        nahodnecisl == vyhernecisla[2] && nahodnecisl == vyhernecisla[3]) 
    {
        cout << "vyhral si 400%" << endl;
        vyhra = vsazenemoners * 4;
        moners += vyhra;
        cout << "vyhral si " << vyhra << "$, nyni mas " << moners << "$" << endl;
        
    }

    else if (nahodnecisl == vyhernecisla[0] || nahodnecisl == vyhernecisla[1] ||
        nahodnecisl == vyhernecisla[2] || nahodnecisl == vyhernecisla[3])
    {
        cout << "vyhral si 200%" << endl;
        vyhra = vsazenemoners * 2;
        moners += vyhra;
        cout << "vyhral si " << vyhra << "$, nyni mas " << moners << "$" << endl;
        
    }
    else {
        cout << "nevyhral si" << endl;
    }
    
    system("pause");
    mainloop();

}


// blackjack


void rukaloop();

void lick();

void ai_lick();

void blackjack();

void dohrat();

void gameover();

void loser();

void win();

void remiza();


vector<string> karty;
int skore = 0;
int maxskore = 21;

vector<string> ai_karty;
int ai_skore = 0;

int lastpozice_ai = 0;
int lastpozicekarty = 0;

int vsazenemoners;

   
string karty52[52] = 
{
    "11 eso", "11 eso", "11 eso", "11 eso",
    "10 kral", "10 kral", "10 kral", "10 kral", 
    "10 dama", "10 dama", "10 dama", "10 dama", 
    "10 jack", "10 jack", "10 jack", "10 jack", 
    "10", "10", "10", "10", 
    "9", "9", "9", "9", 
    "8", "8", "8", "8", 
    "7", "7", "7", "7", 
    "6", "6", "6", "6", 
    "5", "5", "5", "5", 
    "4", "4", "4", "4", 
    "3", "3", "3", "3", 
    "2", "2", "2", "2",
};



void blackjack() {
    skore = 0;
    ai_skore = 0;
    lastpozice_ai = 0;
    lastpozicekarty = 0;

    system("cls");
    srand(time(0));
    cout << "vybral sis hru blackjack" << endl;
    Sleep(250);
    cout << "kolik si prejes vsadit" << endl;
    cout << "> ";
    cin >> vsazenemoners;
    system("cls");
    cout << "vsadil si " << vsazenemoners << "$" <<  endl;
    Sleep(500);
    cout << "rozdavani" << endl;

    Sleep(2500);
    
    // system("cls");
    
    int i;
    i = 0;
    while (i < 2) {
        int pozicekarty = rand() % 52;
        karty.push_back(karty52[pozicekarty]);
        
        i++;
        lastpozicekarty++;
    }
    i = 0;
    while (i < 2) {
        int pozicekarty = rand() % 52;
        ai_karty.push_back(karty52[pozicekarty]);
        
        i++;
        lastpozice_ai++;
    }

    rukaloop();
}

void rukaloop() {
    system("cls");
    
    int x = 0;
    skore = 0;
    ai_skore = 0;
    for (x = 0; x < lastpozicekarty; x++) {
        
        int skrecounter = stoi(karty[x]);

        switch (skrecounter)
        {
        case 1:
            skore = skore + 1;
            break;
        case 2:
            skore = skore + 2;
            break;
        case 3:
            skore = skore + 3;
            break;
        case 4:
            skore = skore + 4;
            break;
        case 5:
            skore = skore + 5;
            break;
        case 6:
            skore = skore + 6;
            break;
        case 7:
            skore = skore + 7;
            break;
        case 8:
            skore = skore + 8;
            break;
        case 9:
            skore = skore + 9;
            break;
        case 10:
            skore = skore + 10;
            break;
        case 11:
            skore = skore + 11;
            break;
  
        default:
            cout << "bro?" << endl ;
            break;
        }
    }
    if (skore > maxskore) {
        gameover();
        
    }

    x = 0;
    for (x = 0; x < lastpozice_ai; x++) {
        
        int skrecounter = stoi(ai_karty[x]);

        switch (skrecounter)
        {
        case 1:
            ai_skore = ai_skore + 1;
            break;
        case 2:
            ai_skore = ai_skore + 2;
            break;
        case 3:
            ai_skore = ai_skore + 3;
            break;
        case 4:
            ai_skore = ai_skore + 4;
            break;
        case 5:
            ai_skore = ai_skore + 5;
            break;
        case 6:
            ai_skore = ai_skore + 6;
            break;
        case 7:
            ai_skore = ai_skore + 7;
            break;
        case 8:
            ai_skore = ai_skore + 8;
            break;
        case 9:
            ai_skore = ai_skore + 9;
            break;
        case 10:
            ai_skore = ai_skore + 10;
            break;
        case 11:
            ai_skore = ai_skore + 11;
            break;
  
        default:
            cout << "bro?" << endl ;
            break;
        }
    }
    if (ai_skore > maxskore) {
        win();
    }



    cout << "v ruce mas: ";
    for (int j = 0; j < lastpozicekarty;j++) {
        cout << karty[j] << ", ";
    }
    cout << "tve skore je: " << skore << endl;
    cout << "skore protivnika je " << ai_skore << endl;

    int akce;

    cout << "co si prejes udelat?" << "\n";
    cout << "1. vzit si kartu" << "\n";
    cout << "2. dohrat" << "\n";

    cin >> akce;
    switch (akce)
    {
    case 1:
        if (ai_skore <= 16) {
            ai_lick();
        }
        else {
            
        }

        lick();
        break;
    case 2:
        dohrat();
        break;
    default:
        cout << "bro?";
        rukaloop();
    }
}

void lick() {
    
    int randomkarta = rand() % 52;
    karty.push_back(karty52[randomkarta]);
    cout << "vytahl sis " << karty52[randomkarta] << endl;
    lastpozicekarty++;
    

    system("pause");
    rukaloop();
}
void ai_lick() {
    int nahoda = rand() % 2;

    if (nahoda = 1 && ai_skore < 16) { 
        int randomkarta = rand() % 52;
        ai_karty.push_back(karty52[randomkarta]);
        cout << "protivnik si vytahl kartu" << endl;
        Sleep(350);
        lastpozice_ai++;
    }

    else if (ai_skore <= 10) {
        int randomkarta = rand() % 52;
        ai_karty.push_back(karty52[randomkarta]);
        cout << "protivnik si vytahl kartu" << endl;
        Sleep(350);
        lastpozice_ai++;
    }
    else {}

}


void dohrat() {
    cout << "tve skore je " << skore << endl;

    if (skore > ai_skore) {
        win();
    }
    else if (ai_skore > skore) { 
        loser();
    }
    else if (skore == ai_skore) {
        remiza();
    }
    else {
        cout << "bro?" << endl;
    }

}

void win() {
    if (skore = 21) {
        cout <<  "OUUUU YEEES BABYYYYYYYYYYY VYHRAL SI 250% SVYH VSAZENYCH MONERS OU YEAAAAAAAA" << endl;
        moners = moners + (vsazenemoners*3/2);
    }
    else {
         cout << "OUUUU YEEES BABYYYYYYYYYYY VYHRAL SI 200% SVYH VSAZENYCH MONERS OU YEAAAAAAAA" << endl;
        moners = moners + (vsazenemoners);
    }
    system("pause");
    vsazenemoners = 0;
    mainloop();
}

void loser() {
    cout << "prohral si vsechny vsazene penize, protivnik mel vice bodu jako ty" << endl;
    moners = moners - (vsazenemoners);
    system("pause");
    vsazenemoners = 0;
    mainloop();
}

void gameover() {
    cout << "tve skore presahlo 21, dohral si." << endl;
    Sleep(500);
    cout << "ouuu prohral si vsechny sve penize, velike skody" << endl;
    moners = moners - vsazenemoners;
    system("pause");
    vsazenemoners = 0;
    mainloop();
}
void remiza() {
    cout << "ou vypada to ze to byla remiza, jaka to ale prilezitost" << endl;
    Sleep(350);
    cout << "nic si nevyhral a nic si neprohral" << endl;
    system("pause");
    vsazenemoners = 0;
    mainloop();

}







// konec blackjack

int main()
{
    mainloop();
    return 0;
}