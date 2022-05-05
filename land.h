#ifndef LAND_H
#define LAND_H
#include <iostream>
#include <string>
#include "player.h"

using namespace std;

enum LandTypes {FOREST, LAKE, HOUSE,SNOW,ROME,OCEAN,CAVE,GARDEN, NUM_LANDS};

class Land {
    public:
    virtual string getDescription(){
        return "Description of land";
    }
    
    virtual string visit(Player& player){
        return "You visit a land";
    }
};

class Forest : public Land {
    public:
    string getDescription();
    
    string visit(Player& player);
};

class Lake : public Land {
    public:
    string getDescription();
    
    string visit(Player& player);
};

class House : public Land {
    public:
    string getDescription();
    
    string visit(Player& player);
};

class Snow  : public Land {
    public:
    string getDescription();
    
    string visit(Player& player);
};

class Rome : public Land {
    public:
    string getDescription();
    
    string visit(Player& player);
};

class Ocean : public Land {
    public:
    string getDescription();
    
    string visit(Player& player);
};

class Cave : public Land {
    public:
    string getDescription();
    
    string visit(Player& player);
};

class Garden : public Land {
    public:
    string getDescription();
    
    string visit(Player& player);
};

Land* getRandomLand();

#endif