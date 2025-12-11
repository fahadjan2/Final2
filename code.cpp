#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <map>
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
void friendshipBrOutput(vector<string>);
void gamesOutput(map<string, string>);

int main() { 
    srand(time(0));

    //File populating w/ names
    ifstream namesfile("names.txt");
    vector <string> names;
    string line;
    while (getline(namesfile, line))
        names.push_back(line);
    namesfile.close();

    //Queues
    Coffee* head = nullptr;
    deque <string> muffinQueue;
    vector <string> friendshipBracelets;
    map <string, string> games;
    
    //COFFEE
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
   
    //Initial queue output
    cout << "Initial queues:" << endl;
    cout << "Coffee ";
    coffeeOutput(head);
    cout << "Muffin ";
    muffinOutput(muffinQueue);
    cout << endl;
    cout << "Friendship Bracelets ";
    friendshipBrOutput(friendshipBracelets);
    cout << endl;
    cout << "Video games ";
    gamesOutput(games);
    cout << endl;

    //10 Simulation Rounds
    for (int i = 0; i < ROUNDS; i++) {
        cout << "---Round " << i + 1 << "---" << endl;

        //COFFEE
        cout << "Coffee booth:" << endl;
        //Serves the head of the line
        if (head) { 
            cout << "[" << head->name << " has been served " << head->drink << "]" << endl;
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
            cout << "[" << name << " has joined the coffee booth queue" << "]" << endl;
        }
        coffeeOutput(head);

        //MUFFIN
        cout << "Muffin booth:" << endl;
        if (!muffinQueue.empty()) {
            cout << "[" << muffinQueue[0] << " has been served" << "]" << endl;
            muffinQueue.pop_front();
        }
        //Joining probability
        probability = rand() % 100 + 1;
        if (probability > 50) {
            int randNum = rand() % names.size();
            string name = names[randNum];
            muffinQueue.push_back(name);
            cout << "[" << name << " has joined the muffin booth queue" << "]" << endl;
        }
        muffinOutput(muffinQueue);

        //FRIENDSHIP BRACELETS
        cout << "Friendship Bracelets booth:" << endl;
        if (!friendshipBracelets.empty()) {
            cout << "[" << friendshipBracelets[0] << " has bought a bracelet" << "]" << endl;
            friendshipBracelets.erase(friendshipBracelets.begin());
        }
        //Joining probability
        probability = rand() % 100 + 1;
        if (probability > 50) {
            int randNum = rand() % names.size();
            string name = names[randNum];
            friendshipBracelets.push_back(name);
            cout << "[" << name << " has joined the bracelets booth queue" << "]" << endl;
        }
        friendshipBrOutput(friendshipBracelets);

        //GAME BOOTH
        cout << "Video game booth:" << endl;
        if (!muffinQueue.empty()) {
            cout << "[" << muffinQueue[0] << " has bought a bracelet" << "]" << endl;
            muffinQueue.pop_front();
        }
        //Joining probability
        probability = rand() % 100 + 1;
        if (probability > 50) {
            int randNum = rand() % names.size();
            string name = names[randNum];
            friendshipBracelets.push_back(name);
            cout << "[" << name << " has joined the bracelets booth queue" << "]" << endl;
        }
        friendshipBrOutput(friendshipBracelets);
    }
}   

void coffeeOutput(Coffee* head) {
    cout << "Queue:" << endl;
    if (!head) {
        cout << "     Empty" << endl << endl;
        return;
    }
    
    Coffee* current = head;
    while (current) {
        cout << "     " << current->name << ": " << current->drink << endl; 
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

void muffinOutput(deque<string> muffins) {
    cout << "Queue:" << endl;
    if (muffins.empty()) {
        cout << "     Empty" << endl << endl;
        return;
    }
    for (auto it : muffins) {
        cout << "     " << it << endl;
    }
    cout << endl;
}

void friendshipBrOutput(vector<string> bracelets) {
    cout << "Queue:" << endl;
    if (bracelets.empty()) {
        cout << "     Empty" << endl << endl;
        return;
    }
    for (auto it : bracelets) {
        cout << "     " << it << endl;
    }
    cout << endl; 
}

void gamesOutput(map<string, string> gameList) {
    for (auto pair : gameList) {
        cout << pair.first << " " << pair.second << endl;
    }
}