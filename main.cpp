#include <iostream>
#include <ctime>
#include <map>
using namespace std;

void displayMenu();
void playerChoice(char &);
void computerChoice(char &);
void displayChoice(char);
void fight(char &, char &, int &, int &);
void startGame();
int getValidatedInput();

/*
const attribute
*/
const int START = 1;
const int EXIT = 2;
const int NUMBER_OF_GAME = 3;
const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';
const string PLAYER_WIN = "Player wins!";
const string COMPUTER_WIN = "Computer wins!";
const string TIES = "It's a tie!";

int main()
{
    srand(static_cast<unsigned int>(time(0))); //initialize random number generator
    displayMenu();
    int options;
    do
    {
        options = getValidatedInput();
        switch (options)
        {
        case START:
            startGame();
            cout << "==============GAME  OVER==============" << endl;
            cout << "Do you want to play again? " << endl;
            cout << "[  1 = YES, 2 = NO   ]" << endl;   
            break;
        case EXIT:
            cout << "Bye Bye !" << endl;
            return 1;
            break;
        default:
            break;
        }
    } while (true);

    return 0;
}
int getValidatedInput()
{
    int options;
    //cin.clear(); // 清除錯誤標幟
    //cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入緩衝區
    while (!(cin >> options))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    return options;
}

void displayMenu()
{
    cout << "======================================" << endl;
    cout << "===           WELCOME TO           ===" << endl;
    cout << "===    Rock Paper Scissors Game    ===" << endl;
    cout << "===                                ===" << endl;
    cout << "===             BY:Chrs            ===" << endl;
    cout << "===                                ===" << endl;
    cout << "===           1. Start             ===" << endl;
    cout << "===           2. Exit              ===" << endl;
    cout << "===                                ===" << endl;
    cout << "======================================" << endl;
    cout << "Enter your option: ";
}
void startGame()
{
    int playerScore = 0;
    int computerScore = 0;
    while (playerScore < NUMBER_OF_GAME && computerScore < NUMBER_OF_GAME)
    {
        char player;
        char computer;
        playerChoice(player);
        computerChoice(computer);
        fight(player, computer, playerScore, computerScore);
    }

    if (playerScore > computerScore)
    {
        cout << "******  YOU ARE WINER !!!  ****** " << endl;
    }
    else
    {
        cout << "******  YOU ARE LOSER.     ****** " << endl;
    }
}

void playerChoice(char &choice)
{
    do
    {
        cout << "======================================" << endl;
        cout << "r = Rock || p = Paper || s = scissors" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case ROCK:
        case PAPER:
        case SCISSORS:

            break;
        default:
            cout << "Incorrect choice." << endl;
            break;
        }
    } while (choice != ROCK && choice != PAPER && choice != SCISSORS);
    cout << "player choise is : ";
    displayChoice(choice);
}
void computerChoice(char &choice)
{
    
    int ran = rand() % 3;

    switch (ran)
    {
    case 0:
        choice = ROCK;
        break;
    case 1:
        choice = PAPER;
        break;
    case 2:
        choice = SCISSORS;
        break;
    }
    cout << "Computer choise is : ";
    displayChoice(choice);
}
void displayChoice(char choice)
{
    switch (choice)
    {
    case ROCK:
        cout << "ROCK" << endl;
        break;
    case PAPER:
        cout << "PAPER" << endl;
        break;
    case SCISSORS:
        cout << "SCISSORS" << endl;
        break;
    }
}
void fight(char &player, char &computer, int &playerScore, int &computerScore)
{
    map<pair<char, char>, string> result_map = {
        {{ROCK, SCISSORS}, PLAYER_WIN},
        {{SCISSORS, PAPER}, PLAYER_WIN},
        {{PAPER, ROCK}, PLAYER_WIN},
        {{ROCK, PAPER}, COMPUTER_WIN},
        {{SCISSORS, ROCK}, COMPUTER_WIN},
        {{PAPER, SCISSORS}, COMPUTER_WIN}};

    if (player == computer)
    {
        cout << TIES << endl;
    }
    else
    {

        string result = result_map[{player, computer}];
        if (result == PLAYER_WIN)
        {
            playerScore++;
        }
        else if (result == COMPUTER_WIN)
        {
            computerScore++;
        }
        else
        {
            result = TIES;
        }
        cout << result << endl;
    }
    cout << "======================================" << endl;
    cout << "=== Player   Score : " << playerScore << endl;
    cout << "=== Computer Score : " << computerScore << endl;
    cout << "======================================" << endl;
}