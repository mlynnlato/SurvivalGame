#include <iostream>
#include <time.h>
#include "player.h"
#include "land.h"

using namespace std;

const int WORLD_SIZE = 20;

Land* world[WORLD_SIZE][WORLD_SIZE];

void buildWorld(){
    for(int i = 0; i < WORLD_SIZE; i++){
        for(int j = 0; j < WORLD_SIZE; j++){
            world[i][j] = getRandomLand();
        }
    }
}


int main(){
    srand(time(0));
    bool swapMap=false;
    buildWorld();
    
    Player player(WORLD_SIZE / 2, WORLD_SIZE / 2);
    
    cout << "You wake up in a mysterious wonderland. Watch out for all the critters, don't be fooled!" << endl;
    //cout << "Player position x: " << player.getXPosition() << " y: " << player.getYPosition() << endl;
    while(player.isAlive()){
        player.nextTurn();
        cout << player.toString() << endl;
        cout << "Player position x: " << player.getXPosition() << " y: " << player.getYPosition() << endl;
        //cout<<"test" <<endl;
        
        if(player.getYPosition()==0){
            cout<< "North: Out of Bounds (If selected will put you on oppsite side of map!)" << endl;
        }
        else{
            
            cout << "To the north you see " << world[player.getXPosition()][player.getYPosition() - 1]->getDescription() << endl;
        }
        
        if(player.getYPosition()==19){
            cout<< "South: Out of Bounds (If selected will put you on oppsite side of map!)" << endl;
        }
        else{
            cout << "To the south you see " << world[player.getXPosition()][player.getYPosition() + 1]->getDescription() << endl;
            }
        
        if(player.getXPosition()==0){
            cout<< "West: Out of Bounds (If selected will put you on oppsite side of map!)" << endl;
        }
        else{
            cout << "To the West you see " << world[player.getXPosition() - 1][player.getYPosition()]->getDescription() << endl;
        }
        if(player.getXPosition()==19){
            cout<< "East: Out of Bounds (If selected will put you on oppsite side of map!)" << endl;
        }
        else{
            cout << "To the east you see " << world[player.getXPosition() + 1][player.getYPosition()]->getDescription() << endl;
}
        
        
        cout << "Which direction do you want to move?" << endl;
        cout << "1: North, 2: South, 3: West, 4: East" << endl;
        int userInput;
        cin >> userInput;
        
        switch(userInput){
            case 1: // North
                cout << "You move North." << endl;
                if(player.getYPosition() == 0){
                    player.setPosition(player.getXPosition(), 19);
                    swapMap=true;
                }
                else{
                    player.setPosition(player.getXPosition(), player.getYPosition() - 1);
                }
                
            break;
            
            case 4: // East
                cout << "You move East." << endl;
                if(player.getXPosition()==19){
                    player.setPosition(0, player.getYPosition());
                    swapMap=true;
                }
                else{
                    player.setPosition(player.getXPosition() + 1, player.getYPosition());
                }
            break;
            
            case 3: // West
            cout << "You move West." << endl;
            if(player.getXPosition()==0){
                player.setPosition(19, player.getYPosition());
                swapMap=true;
            }
            else{
                player.setPosition(player.getXPosition() - 1, player.getYPosition());
            }
            break;
            
            case 2: // South
            cout << "You move South." << endl;
            if(player.getYPosition() == 19){
                player.setPosition(player.getXPosition(), 0);
                swapMap=true;
            }
            else{
                player.setPosition(player.getXPosition(), player.getYPosition() + 1);
            }
            break;
            default: // Error
            break;
        }
        
        //cout << "Player position x: " << player.getXPosition() << " y: " << player.getYPosition() << endl;
        if(swapMap){
            cout<< "You were moved the the other side of the map!" << endl;
        }
        else{
            cout << world[player.getXPosition()][player.getYPosition()]->visit(player) << endl;
        }
        
        cout << endl;
        cout << "------------------------------------------------------------------------" << endl;
        
        swapMap=false;
    }
    
    cout << "You died" << endl;
    cout << "Score: " << player.getScore() << endl;
    
    return 0;
}