#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <deque>
using namespace std;

const int ROUNDS = 10;

struct Coffee {
    string name;
    string drink;
    Coffee* next;
};

void coffeeOutput(Coffee *);
void addCoffeeOrder(Coffee *&, string, string);

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
        int randNum = rand() % names.size();
        string name = names[randNum];
        randNum = rand() % drinks.size();
        string drink = drinks[randNum];
        addCoffeeOrder(head, name, drink);
    }

    cout << "Initial queue:" << endl;
    coffeeOutput(head);

    //10 Simulation Rounds
    for (int i = 0; i < ROUNDS; i++) {
        cout << "Round " << i + 1 << endl;

        //COFFEE LINE
        if (head) { //Serves the head of the line
            cout << head->name << " has been served " << head->drink << endl;
            Coffee* temp = head;
            head = temp->next;
            delete temp;
        }

        int probability = rand() % 100 + 1;
        if (probability > 50) { //Joins queue
            int randNum = rand() % names.size();
            string name = names[randNum];
            randNum = rand() % drinks.size();
            string drink = drinks[randNum];
            addCoffeeOrder(head, name, drink);
            cout << name << " has joined the queue" << endl;
        }

        //Outputs
        coffeeOutput(head);
    }

}   

void coffeeOutput(Coffee* head) {
    if (!head) {
        cout << "Queue empty" << endl << endl;
        return;
    }
    
    Coffee* current = head;
    cout << "Coffee queue:" << endl;
    while (current) {
        cout << current->name << ": " << current->drink << endl; 
        current = current->next;
    }
    cout << endl;
}

void addCoffeeOrder(Coffee*& head, string name, string drink) {
    Coffee* newOrder = new Coffee;
    newOrder->name = name;
    newOrder->drink = drink;
    newOrder->next = nullptr;
    if (!head) //If head is empty
        head = newOrder; 
    else { //Connects tail to neworder
        Coffee* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newOrder;
    }
}