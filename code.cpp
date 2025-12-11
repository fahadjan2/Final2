#include <iostream>

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
    
}