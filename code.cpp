#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int ROUNDS = 10;

struct Coffee {
    string name;
    string drink;
    Coffee* next;
};

int main() { 
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
        
        int randNum = rand() % names.size();
        randNum = rand() % drinks.size();
    }
    for (int i = 0; i < ROUNDS; i++) {

    }

}   