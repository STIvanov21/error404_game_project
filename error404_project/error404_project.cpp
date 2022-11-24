#include <iostream>
#include <random>
#include <cstring>
#include <string>
using namespace std;

int difficulty = 3;
//Difficulty levels 1-5



void clearScreen()
{
    system("cls");
}

void selectDifficulty(int difficulty)
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
    mainMenu();
}

void startGame()
{

}

int generateRandomNum()
{
    random_device rd;
    uniform_int_distribution<int> dist(0, 9);
    return dist(rd);
}

void mainMenu()
{
    cout << "Welcome to Mathle" << '\n';
    cout << "Current difficulty: " << difficulty;
    cout << "Please select and option:" << '\n';
    cout << "1 Select difficulty" << '\n';
    cout << "2 Play Game" << '\n';
    int choice = 3;
    while (choice != 1 && choice != 2)
    {
        cin >> choice;
        switch (choice)
        {
        case 1: clearScreen(); selectDifficulty(difficulty); break;
        case 2: clearScreen(); startGame(); break;
        }
    }
}

int main()
{
    mainMenu();
}