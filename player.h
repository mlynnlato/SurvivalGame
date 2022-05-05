#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <sstream>

using namespace std;

class Player {
    public:
    Player(int initX, int initY);
    
    bool isPosioned() const;
    
    void setPosion(bool val);
    
    int getScore() const;
    
    bool isAlive() const;
    
    int getThirst() const;
    
    int getHunger() const;
    
    int getHealth() const;
    
    void setHealth(int val);
    
    void setThirst(int val);
    
    void setHunger(int val);
    
    int getXPosition() const;
    
    int getYPosition() const;
    
    void setPosition(int newX, int newY);
    
    string toString();
    
    void nextTurn();
    
    private:
    int thirst;
    int hunger;
    int health;
    bool posion;
    int x, y;
    
    int score;
};

#endif