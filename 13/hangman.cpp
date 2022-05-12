#include <iostream>
#include <map>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class GuessWord;

class Action
{
public:
  static int actionCount;
  static int powerUpCount;
  virtual void run(GuessWord *guessWords) = 0;
};

class GuessWord
{
  std::string word;
  std::string hidden_word;

public:
  GuessWord(const std::string &word);
  int get_word_length();
  void guess_char(char chr);
  bool have_won();
  void reveal_letter(int index);
  void set_word(const std::string &word);
  void show_hidden_word();
};

GuessWord::GuessWord(const std::string &word)
{
  set_word(word);
}

int GuessWord::get_word_length()
{
  return word.size();
}

void GuessWord::guess_char(char chr)
{
  for (int i = 0; i < word.size(); i++)
  {
    if (word[i] == chr && hidden_word[i] == '*')
    {
      reveal_letter(i);
    }
  }
}

bool GuessWord::have_won()
{
  return word == hidden_word;
}

void GuessWord::reveal_letter(int index)
{
  if (index >= 0 && index < word.size())
  {
    hidden_word[index] = word[index];
  }
}

void GuessWord::set_word(const string &word)
{
  this->word = word;
  this->hidden_word.clear();

  for (int i = 0; i < word.size(); i++)
    hidden_word.push_back('*');
}

void GuessWord::show_hidden_word()
{
  cout << "WORD: " << hidden_word << endl;
}
// mano
class GuessLetter : public Action
{
private:
  char letter;

public:
  GuessLetter(const char letter) : letter(letter){};
  void run(GuessWord *guessWords)
  {
    guessWords->guess_char(letter);
  };
};

class RevealLetter : public Action
{
private:
  int letterIndex;

public:
  RevealLetter(int index) : letterIndex(index){};
  void run(GuessWord *guess_word)
  {
    guess_word->reveal_letter(letterIndex);
  };
};
class RevealRandom : public Action
{
public:
  RevealRandom(){};
  void run(GuessWord *guessWords)
  {
    int randNumb = rand() % guessWords->get_word_length();
    guessWords->reveal_letter(randNumb);
  };
};

int Action::powerUpCount = 3;
int Action::actionCount = 7;

int main(int argc, char **argv)
{
  srand(time(NULL));
  // Programuojate jus
  GuessWord *guessWord = new GuessWord("hello");

  while (!guessWord->have_won())
  {
    if (Action::actionCount == 0)
    {
      cout << "Ejimai baigesi - PRALAIMEJAI\n";
      return 0;
    }

    cout << "ACTIONS: guess reveal rand" << endl;
    guessWord->show_hidden_word();

    string action;
    cin >> action;

    Action *actionPtr = nullptr;
    if (action == "guess")
    {
      char symbol;
      cin >> symbol;
      actionPtr = new GuessLetter(symbol);
    }
    else if (action == "reveal" && Action::powerUpCount-- > 0)
    {
      int index;
      cin >> index;
      actionPtr = new RevealLetter(index);
    }
    else if (action == "rand" && Action::powerUpCount-- > 0)
    {
      actionPtr = new RevealRandom();
    }
    else if (action == "rand" || action == "reveal")
    {
      cout << "Baiges power'upai\n";
    }
    else
    {
      cout << "Wrong cmd\n";
    }

    if (actionPtr != nullptr)
    {
      Action::actionCount--;
      actionPtr->run(guessWord);
    }

    if (guessWord->have_won())
    {
      cout << "WON!\n";
    }
  }
}