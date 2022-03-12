#include <iostream>
#include "header/Date.hpp"
#include "header/Apple.hpp"
#include "header/AppleTree.hpp"
#include "header/Picker.hpp"
#include "header/Basket.hpp"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "src/Helpers.cpp"

using namespace std;

AppleTree *getNonEmptyAppleTree(const vector<AppleTree *> &);
void printTreeAndPickersState(const vector<AppleTree *> &, const vector<Picker *> &);
int main()
{
    try
    {
        srand(time(NULL));

        vector<AppleTree *> appleTrees{
            new AppleTree(3),
            new AppleTree(7),
            new AppleTree(10),
        };

        vector<Picker *> pickers{
            new Picker(5, new Basket(30)),
            new Picker(8, new Basket(50)),
        };

        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << " diena.-------------------\n";
            cout << "BEFORE EVERYTHING: \n";
            printTreeAndPickersState(appleTrees, pickers);

            for (auto &tree : appleTrees)
            {
                tree->growFruitsForAllDay();
            }
            cout << "\nAFTER GROWING FRUITS: \n";
            printTreeAndPickersState(appleTrees, pickers);

            for (auto &picker : pickers)
            {
                AppleTree *appleTree = getNonEmptyAppleTree(appleTrees);

                if (appleTree != nullptr)
                {
                    int collectFruitsCount = (rand() % (appleTree->getApples().size())) + 1; // Pakeisti i dideli skaiciu kad patikrinti try catch
                    for (int j = 0; j < collectFruitsCount; j++)
                    {
                        try
                        {
                            picker->collectFruit(*appleTree);
                        }
                        catch (const PickerHasNoEnergyException &ex)
                        {
                            cout << "Picker already collected maximum fruits allowed for him \n";
                            break;
                        }
                    }
                }
            }
            cout << "\nAFTER COLLECTING FRUITS:\n";
            printTreeAndPickersState(appleTrees, pickers);
            cout << "\n";
        };
        cout << " -------------------\n";
        cout << "Apple count total: " << Apple::appleCount << endl;
        cout << "Apple Tree count total: " << AppleTree::treeCount << endl;
        clearVectorContent(appleTrees);
        cout << "-------- After destroying appleTrees---------\n";
        cout << "Apple count total: " << Apple::appleCount << endl;
        cout << "Apple Tree count total: " << AppleTree::treeCount << endl;
        // Isitikinti kad normaliai viskas trinama:
        // Per diena po 20 vaisiu uzauginama su daartiniu setup
        //  suskaiciuoti kiek pickeriai turi pinigu - tiek obuoliu jau sunaikinta
        //  sudeti pinigus su obuoliais likusiais ant medzio turi buti 100
    }
    catch (const exception &ex)
    {
        cout << ex.what();
    }
};

AppleTree *getNonEmptyAppleTree(const vector<AppleTree *> &trees)
{
    vector<AppleTree *> nonEmptyTrees;

    for (auto &tree : trees)
    {
        if (tree->getApples().size() != 0)
        {
            nonEmptyTrees.push_back(tree);
        }
    }
    if (nonEmptyTrees.size() == 0)
    {
        return nullptr;
    }

    int randomIndex = (rand() % (nonEmptyTrees.size()));
    return nonEmptyTrees[randomIndex];
}

void printTreeAndPickersState(const vector<AppleTree *> &trees, const vector<Picker *> &pickers)
{
    for (auto &picker : pickers)
    {
        picker->sellFruits();
        cout << "Picker money:" << picker->getMoney() << endl;
    }
    for (auto &tree : trees)
    {
        cout << "Tree has " << tree->getApples().size() << " fruits.\n";
    }
}
