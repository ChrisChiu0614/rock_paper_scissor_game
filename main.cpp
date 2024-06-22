#include <iostream>
#include <ctime>
#include <map>
using namespace std;

// Function declarations
void displayMenu();
void playerChoice(char &);
void computerChoice(char &);
void displayChoice(char);
void fight(char &, char &, int &, int &);
void startGame();
int getValidatedInput();

// Constants
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
    displayMenu(); // Display the game menu
    int options;
    do
    {
        options = getValidatedInput(); // Get user input
        switch (options) 
        {
        case START:
            startGame(); // Start the game
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

/**
 * Function to validate user input
 * Ensures that the input is a number
 * @return int - the validated input
 */
int getValidatedInput()
{
    int options;
    while (!(cin >> options))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    return options;
}

/**
 * Function to display the game menu
 * Provides options to start the game or exit
 */
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

/**
 * Function to start the game
 * Manages the game loop and score tracking
 */
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

/**
 * Function to get the player's choice
 * Validates the choice to ensure it is either 'r', 'p', or 's'
 * @param char &choice - reference to store the player's choice
 */
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

/**
 * Function to get the computer's choice
 * Randomly selects between 'r', 'p', and 's'
 * @param char &choice - reference to store the computer's choice
 */
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

/**
 * Function to display the choice (Rock, Paper, or Scissors)
 * @param char choice - the choice to be displayed
 */
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

/**
 * Function to determine the result of a round
 * Updates the scores based on the choices of player and computer
 * @param char &player - the player's choice
 * @param char &computer - the computer's choice
 * @param int &playerScore - the player's score
 * @param int &computerScore - the computer's score
 */
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