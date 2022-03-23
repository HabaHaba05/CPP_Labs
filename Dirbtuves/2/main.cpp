#include <iostream>
#include <vector>
#include "Bot.hpp"

using namespace std;
using MyBot::Bot;

// How to build:
//  g++ helpers.hpp bot.cpp main.cpp -o main.exe

int main()
{
    Bot bot1;
    {
        vector<string> greetings{"Hello", "Hi"};
        map<Bot::BotState, vector<string>> askForNameQuestions{
            {Bot::BotState::PLEASANT,
             {"That does not seem like a name, could you input a valid name?",
              "Uuuppsyyy, seems like you did a type, Please try again :)"}},
            {Bot::BotState::GRUMPY,
             {"ENTER YOUR NAME , BUT THIS TIME CORRECTLY",
              "Do you even know how to type? Try again..."}}};
        vector<string> questions{
            "How are you?",
            "What is your greatest accomplishment?",
            "What is your favorite sport?",
            "What is your favorite music?"};
        vector<string> answers{"Cool", "Wonderful.", "NICE!"};

        Bot bot(greetings, askForNameQuestions, questions, answers);
        bot1 = bot;
    }

    bot1.start();
};
