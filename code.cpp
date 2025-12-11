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
void muffinOutput(deque<string>);

int main() { 
    srand(time(0));

    //File populating w/ names
    ifstream namesfile("names.txt");
    vector <string> names;
    string line;
    while (getline(namesfile, line))
        names.push_back(line);
    namesfile.close();
    
    //COFFEE POPULATING
    Coffee* head = nullptr;
    //Drink file
    ifstream drinksfile("drinks.txt");
    vector <string> drinks;
    while (getline(drinksfile, line))
        drinks.push_back(line);
    drinksfile.close();
    //Initializing 3 customers
    for (int i = 0; i < 3; i++) {
        int randNum = rand() % names.size();
        string name = names[randNum];
        randNum = rand() % drinks.size();
        string drink = drinks[randNum];
        addCoffeeOrder(head, name, drink);
    }

    //MUFFIN
    deque <string> muffinQueue;

    //Initial queue
    cout << "Initial queue:" << endl;
    coffeeOutput(head);

    //10 Simulation Rounds
    for (int i = 0; i < ROUNDS; i++) {
        cout << "Round " << i + 1 << endl;

        //COFFEE LINE
        //Serves the head of the line
        if (head) { 
            cout << head->name << " has been served " << head->drink << endl;
            Coffee* temp = head;
            head = temp->next;
            delete temp;
        }
        //Probability of joining queue
        int probability = rand() % 100 + 1;
        if (probability > 50) {
            int randNum = rand() % names.size();
            string name = names[randNum];
            randNum = rand() % drinks.size();
            string drink = drinks[randNum];
            addCoffeeOrder(head, name, drink);
            cout << name << " has joined the coffee booth queue" << endl;
        }

        //MUFFIN LINE
        if (!muffinQueue.empty()) {

            muffinQueue.pop_front();
        }
        //Joining probability
        probability = rand() % 100 + 1;
        if (probability > 50) {
            int randNum = rand() % names.size();
            string name = names[randNum];
            muffinQueue.push_back(name);
            cout << name << " has joined the muffin booth queue" << endl;
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

void muffinOutput(deque<string>) {
    
}