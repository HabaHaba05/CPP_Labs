#pragma once
#include <iostream>
#include <vector>
#include <map>

namespace MyBot
{
    using namespace std;

    class Bot
    {
    public:
        enum BotState
        {
            PLEASANT,
            GRUMPY
        };

    private:
        class BotImplementation;
        BotImplementation *impl;

    public:
        Bot();
        Bot(const vector<string> &greetings, const map<BotState, vector<string>> &askForNameQuestions, const vector<string> &questions, const vector<string> &answers);
        Bot(const Bot &other);
        ~Bot();

        // Getters
        BotState getBotState() const;
        vector<string> getAllGreetings() const;
        string getRandomGreeting() const;
        map<BotState, vector<string>> getAllAskForNameQuestions() const;
        string getRandomAskForNameQuestion() const;
        vector<string> getAllQuestions() const;
        string getRandomQuestion() const;
        vector<string> getAllAnswers() const;
        string getRandomAnswers() const;
        string getUserName() const;

        // Setters
        void addGreeting(const string &);
        void setGreetings(const vector<string> &);
        void addPleasantAskForNameQuestion(const string &);
        void setPleasantAskForNameQuestions(const vector<string> &);
        void addGrumpyAskForNameQuestion(const string &);
        void setGrumpyAskForNameQuestions(const vector<string> &);
        void addQuestion(const string &);
        void setQuestions(const vector<string> &);
        void addAnswer(const string &);
        void setAnswers(const vector<string> &);

        // Methods
        void start(); //(it kinda breaks SRP)
        void askUserName();

        // operators overloading
        Bot &operator=(const Bot &other);

    private:
        bool isValidName(const string &);
    };
}