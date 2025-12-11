#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Node {
    string name;
    string drink;
    Node* next;
    
    Node(string nm, string dr) {
        name = nm;
        drink = dr;
        next = nullptr;
    }
};

int main() {
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

}   