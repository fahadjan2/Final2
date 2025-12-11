#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

const int ROUNDS = 10;

struct Coffee {
    string name;
    string drink;
    Coffee* next;
};

int main() { 
    srand(time(0));

    //File populating w/ names and drinks for Coffee
    ifstream namesfile("names.txt");
    ifstream drinksfile("drinks.txt");
    vector <string> names;
    vector <string> drinks;
    string line;
    while (getline(namesfile, line))
        names.push_back(line);
    while (getline(drinksfile, line))
        drinks.push_back(line);
    namesfile.close();
    drinksfile.close();

    Coffee* head = nullptr;
    //Initializing 3 customers
    for (int i = 0; i < 3; i++) {
        Coffee* newOrder = new Coffee;
        int randNum = rand() % names.size();
        newOrder->name = names[randNum];
        randNum = rand() % drinks.size();
        newOrder->drink = drinks[randNum];
        if (!head) 
            head = newOrder; 
        else {
            while (current)
            head->next = newOrder;
        }
        newOrder->next = nullptr;
    }

    //10 Simulation Rounds
    for (int i = 0; i < ROUNDS; i++) {
        if (head) {
            cout << head->name << " has been served " << head->drink << endl;
            Coffee* temp = head;
            head = temp->next;
             
        }
        int probability = rand() % 100 + 1;
        if (probability > 50) { //Joins queue
            Coffee* current = nullptr;
            Coffee* newOrder = new Coffee;
            int randNum = rand() % names.size();
            newOrder->name = names[randNum];
            randNum = rand() % drinks.size();
            newOrder->drink = drinks[randNum];
            newOrder->next = nullptr;
            head = newOrder;
        }
    }

}   