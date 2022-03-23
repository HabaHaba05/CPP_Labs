#include "Bot.hpp"
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "Helpers.hpp"

namespace MyBot
{
    class Bot::BotImplementation
    {
        friend class Bot;

    private:
        string userName;
        int emotionsCounter;
        vector<string> greetings;
        map<BotState, vector<string>> askForNameQuestions;
        vector<string> questions;
        vector<string> answers;
    };

    Bot::Bot()
    {
        impl = new BotImplementation();
        impl->emotionsCounter = 2;
        impl->askForNameQuestions.insert(pair<BotState, vector<string>>((BotState)PLEASANT, {}));
        impl->askForNameQuestions.insert(pair<BotState, vector<string>>((BotState)GRUMPY, {}));
    };

    Bot::Bot(const vector<string> &greetings, const map<BotState, vector<string>> &askForNameQuestions, const vector<string> &questions, const vector<string> &answers)
    {
        impl = new BotImplementation();
        impl->emotionsCounter = 2;
        impl->greetings = greetings;
        impl->askForNameQuestions = askForNameQuestions;
        impl->questions = questions;
        impl->answers = answers;
    }

    Bot::Bot(const Bot &other)
    {
        impl = new BotImplementation(*(other.impl));
    }

    Bot &Bot::operator=(const Bot &other)
    {
        if (this == &other)
            return *this;

        delete impl;
        impl = new BotImplementation(*(other.impl));
        return *this;
    }

    Bot::~Bot()
    {
        delete impl;
    }

    // Getters
    Bot::BotState Bot::getBotState() const
    {
        if (this->impl->emotionsCounter < 0)
        {
            return (BotState)GRUMPY;
        }

        return (BotState)PLEASANT;
    }

    vector<string> Bot::getAllGreetings() const
    {
        return impl->greetings;
    }

    string Bot::getRandomGreeting() const
    {
        return Helpers::getRandom(impl->greetings);
    }

    map<Bot::BotState, vector<string>> Bot::getAllAskForNameQuestions() const
    {
        return impl->askForNameQuestions;
    }

    string Bot::getRandomAskForNameQuestion() const
    {
        return Helpers::getRandom(impl->askForNameQuestions.at(getBotState()));
    }

    vector<string> Bot::getAllQuestions() const
    {
        return impl->questions;
    }

    string Bot::getRandomQuestion() const
    {
        return Helpers::getRandom(impl->questions);
    }

    vector<string> Bot::getAllAnswers() const
    {
        return impl->answers;
    }

    string Bot::getRandomAnswers() const
    {
        return Helpers::getRandom(impl->answers);
    }

    string Bot::getUserName() const
    {
        return impl->userName;
    }

    // Setters
    void Bot::addGreeting(const string &greeting)
    {
        impl->greetings.push_back(greeting);
    }

    void Bot::setGreetings(const vector<string> &greetings)
    {
        impl->greetings = greetings;
    }

    void Bot::addPleasantAskForNameQuestion(const string &question)
    {
        impl->askForNameQuestions.at(BotState::PLEASANT).push_back(question);
    }

    void Bot::setPleasantAskForNameQuestions(const vector<string> &questions)
    {
        impl->askForNameQuestions.at(BotState::PLEASANT) = questions;
    }

    void Bot::addGrumpyAskForNameQuestion(const string &question)
    {
        impl->askForNameQuestions.at(BotState::GRUMPY).push_back(question);
    }

    void Bot::setGrumpyAskForNameQuestions(const vector<string> &questions)
    {
        impl->askForNameQuestions.at(BotState::GRUMPY) = questions;
    }

    void Bot::addQuestion(const string &question)
    {
        impl->questions.push_back(question);
    }

    void Bot::setQuestions(const vector<string> &questions)
    {
        impl->questions = questions;
    }

    void Bot::addAnswer(const string &answer)
    {
        impl->answers.push_back(answer);
    }

    void Bot::setAnswers(const vector<string> &answers)
    {
        impl->answers = answers;
    }

    // Methods
    void Bot::start()
    {
        cout << getRandomGreeting() << endl;
        askUserName();
        cout << getRandomGreeting() << ", " << impl->userName << "." << endl;

        string userAnswer;
        while (true)
        {
            cout << getRandomQuestion() << endl;
            getline(cin, userAnswer);
            if (Helpers::toLower(userAnswer) == "bye")
            {
                break;
            }
            cout << getRandomAnswers() << endl;
        }

        cout << "Bye, " << impl->userName << "!" << endl;
    }

    // BotImplementation part
    void Bot::askUserName()
    {
        cout << "What is your name?\n";

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
                    cout << getRandomAskForNameQuestion() << endl;
                    impl->emotionsCounter--;
                    break;
                }
            }

        } while (!validName);

        impl->userName = result.str();
        impl->emotionsCounter++;
    };

    bool Bot::isValidName(const string &name)
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
}