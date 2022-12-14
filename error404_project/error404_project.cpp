#include <iostream>
#include <random>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int difficulty = 3;
//Difficulty levels 1-4
int streak = 0;
int totalWins = 0;
string gameStatus = "inactive";


void clearScreen()
{
    system("cls");
}

void selectDifficulty()
{
        clearScreen();
        cout << "Select difficulty" << "\n";
        cout << "1 Very Easy" << "\n";
        cout << "2 Easy" << "\n";
        cout << "3 Normal" << "\n";
        cout << "4 Hard" << "\n";
        int input;
        cin >> input;
        switch (input)
        {
        case 1: difficulty = 1; break;
        case 2: difficulty = 2; break;
        case 3: difficulty = 3; break;
        case 4: difficulty = 4; break;
        }
}

void howToPlay()
{
        clearScreen();
        cout << "This is how you play Mathle:" << '\n';
        cout << "1 You will be shown the answer of an equation with N hidden numbers based on the difficulty you choose" << '\n';
        cout << "2 You will have to guess the numbers in the equation (0 is not an input option)" << '\n';
        cout << "3 If you have correctly guessed a number it will be revealed" << '\n';
        cout << "4 If you guess all numbers within the allowed tries you win" << '\n';
        string input;
        cout << "Enter 'back' to go the main menu:" << '\n';
        cin >> input;
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

int randomNumLevelHard()
{
    random_device rd;
    uniform_int_distribution<int> dist(99, 9999);
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
                cin >> input;
                if (input == "play") {
                    clearScreen();
                    startGame();
                }if (input == "back") {
                    clearScreen();
                    gameStatus = "inactive";
                    break;
                }
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
                
                if (input == "play") {
                    clearScreen();
                    startGame();
                }if (input == "back") {
                    clearScreen();
                    gameStatus = "inactive";
                    break;
                }
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
                if (input == "play") {
                    clearScreen();
                    startGame();
                }if (input == "back") {
                    clearScreen();
                    gameStatus = "inactive";
                    break;
                }
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
                if (input == "play") {
                    clearScreen();
                    startGame();
                }if (input == "back") {
                    clearScreen();
                    gameStatus = "inactive";
                    break;
                }
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
                if (input == "play") {
                    clearScreen();
                    startGame();
                }if (input == "back") {
                    clearScreen();
                    gameStatus = "inactive";
                    break;
                }
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
    else if (difficulty == 3)
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
                if (input == "play") {
                    clearScreen();
                    startGame();
                }if (input == "back") {
                    clearScreen();
                    gameStatus = "inactive";
                    break;
                }
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
                if (input == "play") {
                    clearScreen();
                    startGame();
                }if (input == "back") {
                    clearScreen();
                    gameStatus = "inactive";
                    break;
                }
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
                if (input == "play") {
                    clearScreen();
                    startGame();
                }if (input == "back") {
                    clearScreen();
                    gameStatus = "inactive";
                    break;
                }
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
                if (input == "play") {
                    clearScreen();
                    startGame();
                }if (input == "back") {
                    clearScreen();
                    gameStatus = "inactive";
                    break;
                }
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
                if (input == "play") {
                    clearScreen();
                    startGame();
                }if (input == "back") {
                    clearScreen();
                    gameStatus = "inactive";
                    break;
                }
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
    else if (difficulty == 4)
    {
        float answer = randomNumLevelHard();
        float wholeNumCheck = sqrt(answer);
        while (floor(wholeNumCheck) != wholeNumCheck)
        {
            answer = randomNumLevelHard();
            wholeNumCheck = sqrt(answer);
            if (floor(wholeNumCheck) == wholeNumCheck)break;
        }
        int num;
        int guessCount = 0;
        string input;
        gameStatus = "active";
        cout <<"Enter the square root of " << answer << ":" << '\n';
        while (gameStatus == "active")
        {
            cin >> num;
            guessCount++;
            if (pow(num, 2) == answer)
            {
                cout << "Congratulations you won!" << '\n';
                totalWins++;
                streak++;
                cout << "Total wins: " << totalWins << '\n';
                cout << "Current streak: " << streak << '\n';
                cout << "Enter 'back' to go the main menu or 'play' to play again" << '\n';
                cin >> input;
                if (input == "play") {
                    clearScreen();
                    startGame();
                }if (input == "back") {
                    clearScreen();
                    gameStatus = "inactive";
                    break;
                }
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
                if (input == "play") {
                    clearScreen();
                    startGame();
                }if (input == "back") {
                    clearScreen();
                    gameStatus = "inactive";
                    break;
                }
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
        clearScreen();
        int choice;
        cout << "__      __   _                    _____      __  __      _   _    _" << '\n';
        cout << "\\ \\    / /__| |__ ___ _ __  ___  |_   _|__  |  \\/  |__ _| |_| |_ | |___" << '\n';
        cout << " \\ \\/\\/ / -_) / _/ _ \\ '  \\/ -_)   | |/ _ \\ | |\\/| / _` |  _| ' \\| / -_)" << '\n';
        cout << "  \\_/\\_/\\___|_\\__\\___/_|_|_\\___|   |_|\\___/ |_|  |_\\__,_|\\__|_||_|_\\___|" << '\n';
        cout << '\n';
        cout << '\n';
        switch (difficulty)
        {
        case 1:  cout << "Current difficulty: 1 (Very Easy)" << '\n'; break;
        case 2:  cout << "Current difficulty: 2 (Easy)" << '\n'; break;
        case 3:  cout << "Current difficulty: 3 (Normal)" << '\n'; break;
        case 4:  cout << "Current difficulty: 4 (Hard)" << '\n'; break;
        }
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