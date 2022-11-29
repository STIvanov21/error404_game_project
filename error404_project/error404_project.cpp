#include <iostream>
#include <random>
#include <cstring>
#include <string>
using namespace std;

int difficulty = 3;
//Difficulty levels 1-5
int streak = 0;
int totalWins = 0;
string gameStatus = "inactive";


void clearScreen()
{
    system("cls");
}

void selectDifficulty()
{
    cout << "Select difficulty" << "\n";
    cout << "1 Very Easy" << "\n";
    cout << "2 Easy" << "\n";
    cout << "3 Normal" << "\n";
    cout << "4 Hard" << "\n";
    cout << "5 Impossible" << "\n";
    int input;
    cin >> input;
    switch (input)
    {
    case 1: difficulty = 1; break;
    case 2: difficulty = 2; break;
    case 3: difficulty = 3; break;
    case 4: difficulty = 4; break;
    case 5: difficulty = 5; break;
    }
}

void howToPlay()
{
    cout << "This is how you play Mathle:" << '\n';
    cout << "1 You will be shown the answer of an equation with two hidden numbers" << '\n';
    cout << "2 You will have to guess the numbers in the equation(0 is not an input option)" << '\n';
    cout << "3 If you have correctly guessed a number it will be revealed" << '\n';
    string input;
    cout << "Enter 'back' to go the main menu:" << '\n';
    cin >> input;
    if (input != "back") cin >> input;
}

int randomNumLevelEasy()
{
    random_device rd;
    uniform_int_distribution<int> dist(50, 99);
    return dist(rd);
}

int randomNumLevelNormal()
{
    random_device rd;
    uniform_int_distribution<int> dist(99, 499);
    return dist(rd);
}

int randomLevelEasyString()
{
    random_device rd;
    uniform_int_distribution<int> dist(1, 2);
    return dist(rd);
}

int randomLevelNormalString()
{
    random_device rd;
    uniform_int_distribution<int> dist(1, 4);
    return dist(rd);
}

void startGame()
{
    if (difficulty == 1)
    {
        int answer = randomNumLevelEasy();
        int guessCount = 0;
        int num1, num2;
        string gameString = "_ + _ = ";
        string input;
        gameStatus = "active";
        cout << gameString << answer << '\n';
        cout << "Guess the numbers:" << '\n';
        while (gameStatus == "active")
        {
            cin >> num1 >> num2;
            guessCount++;
            if (num1 + num2 == answer) {
                cout << "Congratulations you won!" << '\n';
                totalWins++;
                streak++;
                cout << "Total wins: " << totalWins << '\n';
                cout << "Current streak: " << streak << '\n';
                cout << "Enter 'back' to go the main menu or 'play' to play again" << '\n';
                while (input != "play" && input != "back")
                {
                    cin >> input;
                    if (input == "play") {
                        clearScreen();
                        startGame();
                    }if (input == "back") {
                        clearScreen();
                        gameStatus = "inactive";
                        break;
                    }
                }
            }
            if(guessCount != 3 && gameStatus == "active"){
                cout << "Wrong! Try again" << '\n';
            }
            if (guessCount == 3) {
                cout << "No more guesses left! You lost!" << '\n';
                cout << "Streak reset" << '\n';
                streak = 0;
                cout << "Total wins: " << totalWins << '\n';
                cout << "Enter 'back' to go the main menu or 'play' to play again" << '\n';
                cin >> input;
                while (input != "play" && input != "back")
                {
                    cin >> input;
                    if (input == "play") {
                        clearScreen();
                        startGame();
                    }if (input == "back") {
                        clearScreen();
                        gameStatus = "inactive";
                        break;
                    }
                }
            }
        }
    }
    else if (difficulty == 2)
    {
        int answer = randomNumLevelEasy();
        int levelType = randomLevelEasyString();
        int num1, num2, num3;
        int guessCount = 0;
        string input;
        string gameString;
        gameStatus = "active";
        switch (levelType)
        {
        case 1 : gameString = "_ + _ - _ = "; break;
        case 2 : gameString = "_ - _ + _ = "; break;
        }
        cout << gameString << answer << '\n';
        cout << "Guess the numbers:" << '\n';
        while (gameStatus == "active")
        {
            cin >> num1 >> num2 >> num3;
            guessCount++;
            if (levelType == 1 && num1 + num2 - num3 == answer) 
            {
                cout << "Congratulations you won!" << '\n';
                totalWins++;
                streak++;
                cout << "Total wins: " << totalWins << '\n';
                cout << "Current streak: " << streak << '\n';
                cout << "Enter 'back' to go the main menu or 'play' to play again" << '\n';
                cin >> input;
                while (input != "play" && input != "back")
                {
                    cin >> input;
                    if (input == "play") {
                        clearScreen();
                        startGame();
                    }if (input == "back") {
                        clearScreen();
                        gameStatus = "inactive";
                        break;
                    }
                }
            }else if (levelType == 2 && num1 - num2 + num3 == answer) 
            {
                cout << "Congratulations you won!" << '\n';
                totalWins++;
                streak++;
                cout << "Total wins: " << totalWins << '\n';
                cout << "Current streak: " << streak << '\n';
                cout << "Enter 'back' to go the main menu or 'play' to play again" << '\n';
                cin >> input;
                while (input != "play" && input != "back")
                {
                    cin >> input;
                    if (input == "play") {
                        clearScreen();
                        startGame();
                    }if (input == "back") {
                        clearScreen();
                        gameStatus = "inactive";
                        break;
                    }
                }
            }
            if (guessCount != 3 && gameStatus == "active") {
                cout << "Wrong! Try again" << '\n';
            }
            if (guessCount == 3) {
                cout << "No more guesses left! You lost!" << '\n';
                cout << "Streak reset" << '\n';
                streak = 0;
                cout << "Total wins: " << totalWins << '\n';
                cout << "Enter 'back' to go the main menu or 'play' to play again" << '\n';
                cin >> input;
                while (input != "play" && input != "back")
                {
                    cin >> input;
                    if (input == "play") {
                        clearScreen();
                        startGame();
                    }if (input == "back") {
                        clearScreen();
                        gameStatus = "inactive";
                        break;
                    }
                }
            }
        }
    }else if (difficulty == 3)
    {
        int answer = randomNumLevelNormal();
        int levelType = randomLevelNormalString();
        int num1, num2, num3;
        int guessCount = 0;
        string input;
        string gameString;
        gameStatus = "active";
        switch (levelType)
        {
        case 1: gameString = "_ + _ * _ = "; break;
        case 2: gameString = "_ - _ * _ = "; break;
        case 3: gameString = "_ * _ + _ = "; break;
        case 4: gameString = "_ * _ - _ = "; break;

        }
        cout << gameString << answer << '\n';
        cout << "Guess the numbers:" << '\n';
        while (gameStatus == "active")
        {
            cin >> num1 >> num2 >> num3;
            guessCount++;
            if (levelType == 1 && num1 + num2 * num3 == answer)
            {
                cout << "Congratulations you won!" << '\n';
                totalWins++;
                streak++;
                cout << "Total wins: " << totalWins << '\n';
                cout << "Current streak: " << streak << '\n';
                cout << "Enter 'back' to go the main menu or 'play' to play again" << '\n';
                cin >> input;
                while (input != "play" && input != "back")
                {
                    cin >> input;
                    if (input == "play") {
                        clearScreen();
                        startGame();
                    }if (input == "back") {
                        clearScreen();
                        gameStatus = "inactive";
                        break;
                    }
                }
            }
            else if (levelType == 2 && num1 - num2 * num3 == answer)
            {
                cout << "Congratulations you won!" << '\n';
                totalWins++;
                streak++;
                cout << "Total wins: " << totalWins << '\n';
                cout << "Current streak: " << streak << '\n';
                cout << "Enter 'back' to go the main menu or 'play' to play again" << '\n';
                cin >> input;
                while (input != "play" && input != "back")
                {
                    cin >> input;
                    if (input == "play") {
                        clearScreen();
                        startGame();
                    }if (input == "back") {
                        clearScreen();
                        gameStatus = "inactive";
                        break;
                    }
                }
            }
            else if (levelType == 3 && num1 * num2 + num3 == answer)
            {
                cout << "Congratulations you won!" << '\n';
                totalWins++;
                streak++;
                cout << "Total wins: " << totalWins << '\n';
                cout << "Current streak: " << streak << '\n';
                cout << "Enter 'back' to go the main menu or 'play' to play again" << '\n';
                cin >> input;
                while (input != "play" && input != "back")
                {
                    cin >> input;
                    if (input == "play") {
                        clearScreen();
                        startGame();
                    }if (input == "back") {
                        clearScreen();
                        gameStatus = "inactive";
                        break;
                    }
                }
            }
            else if (levelType == 4 && num1 * num2 - num3 == answer)
            {
                cout << "Congratulations you won!" << '\n';
                totalWins++;
                streak++;
                cout << "Total wins: " << totalWins << '\n';
                cout << "Current streak: " << streak << '\n';
                cout << "Enter 'back' to go the main menu or 'play' to play again" << '\n';
                cin >> input;
                while (input != "play" && input != "back")
                {
                    cin >> input;
                    if (input == "play") {
                        clearScreen();
                        startGame();
                    }if (input == "back") {
                        clearScreen();
                        gameStatus = "inactive";
                        break;
                    }
                }
            }
            if (guessCount != 2 && gameStatus == "active") {
                cout << "Wrong! Try again" << '\n';
            }
            if (guessCount == 2) {
                cout << "No more guesses left! You lost!" << '\n';
                cout << "Streak reset" << '\n';
                streak = 0;
                cout << "Total wins: " << totalWins << '\n';
                cout << "Enter 'back' to go the main menu or 'play' to play again" << '\n';
                cin >> input;
                while (input != "play" && input != "back")
                {
                    cin >> input;
                    if (input == "play") {
                        clearScreen();
                        startGame();
                    }if (input == "back") {
                        clearScreen();
                        gameStatus = "inactive";
                        break;
                    }
                }
            }
        }
    }
}

void mainMenu()
{
    int choice;
    cout << "Welcome to Mathle" << '\n';
    cout << "Current difficulty: " << difficulty << '\n';
    cout << "Current streak: " << streak << '\n';
    cout << "Total wins: " << totalWins << '\n';
    cout << '\n' << "Please select an option:" << '\n';
    cout << "1 Difficulty settings" << '\n';
    cout << "2 Play Game" << '\n';
    cout << "3 How to play the game" << '\n';
    cin >> choice;
    switch (choice)
    {
    case 1: clearScreen(); selectDifficulty(); break;
    case 2: clearScreen(); startGame(); break;
    case 3: clearScreen(); howToPlay(); break;
    default: cin >> choice;
    }
    clearScreen();
    mainMenu();
}

int main()
{
    mainMenu();
}