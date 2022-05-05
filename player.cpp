#include "player.h"

Player::Player(int initX, int initY){
    health = 6;
    hunger = 6; // actual hunger and thirst starts at 5*
    thirst = 6;
    posion=false;
    x = initX;
    y = initY;
    
    score = 0;
}

int Player::getScore() const{
    return score;
}
bool Player::isPosioned() const{
    return posion;
}
void Player::setPosion(bool val){
    posion=val;
}
bool Player::isAlive() const{
    return health > 0;
}

int Player::getThirst() const{
    return thirst;
}

int Player::getHunger() const{
    return hunger;
}

int Player::getHealth() const{
    return health;
}

void Player::setThirst(int val) {
    thirst = val;
}

void Player::setHealth(int val){
    health=val;
}

void Player::setHunger(int val) {
    hunger = val;
}

int Player::getXPosition() const {
    return x;
}

int Player::getYPosition() const {
    return y;
}

void Player::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

string Player::toString(){
    stringstream ss;
    ss << "Health: " << health << endl;
    ss << "Hunger: " << hunger << endl;
    ss << "Thirst: " << thirst << endl;
    
    return ss.str();
}

void Player::nextTurn(){
    hunger--;
    thirst--;
    
    if(hunger <= 0){
        hunger = 0;
        health--;
    }
    
    if(thirst <= 0){
        thirst = 0;
        health--;
    }
    
    score++;
}