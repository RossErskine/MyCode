#include "Test_Vectors.h"
#include "PlayingCards.h"
#include "ContVsArrayTest.h"
#include <iostream>

int main()
{
    ContVsArrayTest cna;
    Test_Vectors test1;
    PlayingCards newGame;
    bool test = true;
    while (test == true)
    {
        int choice;

        cout << "**Please choose from main menu:**" << endl;
        cout << "*********** Main Menu ***********" << endl;
        cout << "***1) Conatiner vs Array Tests***" << endl;
        cout << "***2) Algorithms Tests        ***" << endl;
        cout << "***3) Game                    ***" << endl;
        cout << "***0) Quit                    ***" << endl;
        cout << "***                           ***" << endl;
        cout << "*********************************" << endl;
        cin >> choice;
        switch (choice) {
        case 0:
            test = false;
            break;
        case 1:
            cna.containerVsArray();
            break;
        case 2:
            test1.test();
            break;
        case 3:
            newGame.play();
            break;
        
        default:
            cout << " a number was not picked! " << endl;
        }


    }
    
    

}

