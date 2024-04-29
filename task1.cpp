#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    cout << "\n\t\t\tWelcome to GuessTheNumber game!" << endl;
    cout << "You have to guess a number between 1 and 100. " << endl;
    cout << "You'll have limited choices based on the level you choose. Good Luck!" << endl;

    while (true) {
        cout << "\nEnter the difficulty level: \n";
        cout << "1 for easy!\t";
        cout << "2 for medium!\t";
        cout << "3 for difficult!\t";
        cout << "0 for ending the game!\n" << endl;

        int difficultyChoice;
        cout << "Enter the number: ";
        cin >> difficultyChoice;

        if (difficultyChoice == 0) {
            break;
        }

        srand(time(0));
        int secretNumber = 1 + (rand() % 100);

        int playerChoice;
        int choicesLeft;

        if (difficultyChoice == 1) {
            cout << "\nYou have 10 choices for finding the secret number between 1 and 100.";
            choicesLeft = 10;
        } else if (difficultyChoice == 2) {
            cout << "\nYou have 7 choices for finding the secret number between 1 and 100.";
            choicesLeft = 7;
        } else if (difficultyChoice == 3) {
            cout << "\nYou have 5 choices for finding the secret number between 1 and 100.";
            choicesLeft = 5;
        }

        for (int i = 1; i <= choicesLeft; i++) {
            cout << "\n\nEnter the number: ";
            cin >> playerChoice;

            if (playerChoice == secretNumber) {
                cout << "\nCongratulations! You guessed the secret number in " << i << " attempts." << endl;
                break;
            } else if (playerChoice < secretNumber) {
                cout << "Too low. Try again!" << endl;
            } else {
                cout << "Too high. Try again!" << endl;
            }

            cout << "You have " << choicesLeft - i << " choices left." << endl;
        }

        if (choicesLeft == 0) {
            cout << "\nSorry, you ran out of attempts! The secret number was " << secretNumber << "." << endl;
        }
    }

    return 0;
}