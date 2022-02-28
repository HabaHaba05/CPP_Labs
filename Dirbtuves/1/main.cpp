#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <map>

using namespace std;

enum BotState
{
    PLEASANT,
    GRUMPY
};

BotState getBotState(const int &wrongCount)
{
    if (wrongCount > 2)
    {
        return (BotState)GRUMPY;
    }

    return (BotState)PLEASANT;
}

template <class T>
string getRandom(const vector<T> &data)
{
    // initialize random seed
    srand(time(NULL));
    int randomNumber = rand() % data.size();

    return data[randomNumber];
};

bool isValidName(const string &name)
{
    if (isupper(name[0]))
    {
        for (int i = 1; i < name.length(); ++i)
        {
            if (!islower(name[i]))
            {
                return false;
            }
        }
        return true;
    }

    return false;
}

string askForName(const map<BotState, vector<string>> &askForNameQuestions, int wrongAnswersInARow)
{
    cout << "What is your name?" << endl;

    bool validName = false;
    stringstream result;

    do
    {
        result.str(" ");

        string input;
        getline(cin, input);
        stringstream ss(input);

        string name;

        while (!ss.eof())
        {
            ss >> name;

            validName = isValidName(name);

            if (validName)
            {
                result << name << " ";
            }
            else
            {
                vector<string> questions = askForNameQuestions.at(getBotState(wrongAnswersInARow));
                cout << getRandom(questions) << endl;
                wrongAnswersInARow++;
                break;
            }
        }

    } while (!validName);
    return result.str();
};

int main()
{
    // Bot vars
    vector<string> greetings{"Hello", "Hi"};
    map<BotState, vector<string>> askForNameQuestions{
        {(BotState)PLEASANT,
         {"That does not seem like a name, could you input a valid name?",
          "Uuuppsyyy, seems like you did a type, Please try again :)"}},
        {(BotState)GRUMPY,
         {"ENTER YOUR NAME , BUT THIS TIME CORRECTLY",
          "Do you even know how to type? Try again..."}}};
    vector<string> questions{
        "How are you?",
        "What is your greatest accomplishment?",
        "What is your favorite sport?",
        "What is your favorite music?"};
    vector<string> answers{"Cool", "Wonderful.", "NICE!"};

    // User vars
    string name;

    // Action

    cout << getRandom(greetings) << endl;
    name = askForName(askForNameQuestions, 0);
    cout << getRandom(greetings) << ", " << name << "." << endl;

    string userAnswer;
    while (true)
    {

        cout << getRandom(questions) << endl;
        cin >> userAnswer;
        if (userAnswer != "Bye")
        {
            cout << getRandom(answers) << endl;
        }
        else
        {
            break;
        }
    }

    cout << "Bye, " << name << "!" << endl;
};
