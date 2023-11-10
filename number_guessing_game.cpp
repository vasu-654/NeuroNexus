#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    cout << "!!  welcome to the number guessing game !!" << endl<< endl;
    int number, guess, tries = 0;
    int max_limit;
    cout << "Enter the maximum limit of number : ";
    cin >> max_limit;
    srand(time(0));
    number = rand() % max_limit + 1;
    cout << endl<< "If at any point you found difficult\n Press 0 for hint \n Press -1 for ans" << endl;
    cout << "Start guessing ! All the best" << endl<< endl;
    bool do_exit = false;
    while (guess != number)
    {
        cout << "Enter a guess between 1 & " << max_limit << " : ";
        cin >> guess;
        tries++;
        if (guess == -1)
        {
            cout << "Thanks for playing the game. The correct ans is " << number << endl;
            break;
        }
        else if (guess == 0)
        {
            if (number - 10 < 0)
            {
                cout << "You hint is \n The answer is less than " << number + 10 << endl;
            }
            else
            {
                cout << "You hint is \n The answer is between " << number - 10 << "and" << number + 10 << endl;
            }
        }
        else if (guess > number)
        {
            cout << "Guessed number is high !\n\n";
        }
        else if (guess < number)
        {
            cout << "Guessed number is low !\n\n";
        }
        else
        {
            cout << "\nCorrect! You got it in " << tries << " guesses!\n";
        }
    }
    cout <<endl<<"Thanks do play again"<<endl;

    return 0;
}
