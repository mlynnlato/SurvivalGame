#include "land.h"

Land* getRandomLand(){
    LandTypes selection = (LandTypes)(rand() % NUM_LANDS);
    switch(selection){
        case FOREST:
            return new Forest;
        break;
        case LAKE:
            return new Lake;
        break;
        case HOUSE:
            return new House;
        break;
        case SNOW:
            return new Snow;
        break;
        case ROME:
            return new Rome;
        break;
        case OCEAN:
            return new Ocean;
        break;
        case CAVE:
            return new Cave;
        break;
        case GARDEN:
            return new Garden;
        break;
        default:
            return nullptr;
        break;
    }
}
string Garden::getDescription(){
    return "a Gardener who will give a flower with unknown effects (mystery box).";
}

string Garden:: visit(Player& player){
    
    int num=((rand()%2)+1);
    if(num== 1){
        player.setHunger(player.getHunger() + 2);
        player.setThirst(player.getThirst() + 2);
        player.setPosion(false);
        return "You ate a special flower that cured all poison, and fullfiled your thirst and hunger.";
        
    }
    else if(num==2){
        player.setHealth(-420);
        return "You ate a fatal flower and unfortunately you died!";
        
    }
    
    else{
        player.setHunger(player.getHunger() + 2);
        player.setThirst(player.getThirst() + 2);
        if(player.isPosioned()){
        player.setHealth(player.getHealth() - 1);
        return "You ate a flower that was fullfilling! *Still poisoned!";
    }else
        return "You ate a flower that was fullfilling!";
        
    }
    
}
///////////////////////////////////////////////////////////////
string Snow::getDescription(){
    return "alot of snow, may be able to purify some water.";
}

string Snow:: visit(Player& player){
    
    player.setHunger(player.getHunger() - 1);
    player.setThirst(player.getThirst() + 1);
    if(player.isPosioned()){
        player.setHealth(player.getHealth() - 1);
        return "You purified some water, but wasted many calories from the cold. *Still poisoned!";
    }else
    return "You purified some water, but wasted many calories from the cold.";
    
}
///////////////////////////////////////////////////////////////
string Rome::getDescription(){
    return "an old Colosseum with eary animal sounds, but possible rewards.";
}

string Rome:: visit(Player& player){
    
    player.setHealth(player.getHealth() - 1);
    player.setHunger(player.getHunger() + 2);
    player.setThirst(player.getThirst() + 2);
    if(player.isPosioned()){
        player.setHealth(player.getHealth() - 1);
        return "You barely survived the tiger brawl, but are rewarded with food and water. *Still poisoned!";
    }
    else
    return "You barely survived the tiger brawl, but are rewarded with food and water.";
    
}
///////////////////////////////////////////////////////////////
string Ocean::getDescription(){
    return "an ocean that reminds you of sushi.";
}

string Ocean:: visit(Player& player){
    
    player.setHunger(player.getHunger() + 2);
    if(player.isPosioned()){
        player.setHealth(player.getHealth() - 1);
        return "You recovered fish left overs from a megalodon! *Still poisoned!";
    }
    else
    return "You recovered fish left overs from a megalodon!";
    
    
}
///////////////////////////////////////////////////////////////
string Cave::getDescription(){
    return "a cave that may have raw materials.";
}

string Cave:: visit(Player& player){
    
    player.setPosion(true);
    if(player.isPosioned()){
        player.setHealth(player.getHealth() - 1);
    }
    return "You were biten by the Shue Bug, find a doctor or flower to get rid of poison (losing 1 extra health per move)";
    
    
    
}
///////////////////////////////////////////////////////////////

string House::getDescription(){
    return "a welcoming home.";
}

string House:: visit(Player& player){
    player.setHealth(player.getHealth()+ 2);
    player.setPosion(false);
    return "The Doctor fixed your wounds and poison!";
    
}
///////////////////////////////////////////////////////////////
string Forest::getDescription(){
    return "a densely wooded forest.";
}

string Forest::visit(Player& player){
    player.setHunger(player.getHunger() + 2);
    if(player.isPosioned()){
        player.setHealth(player.getHealth() - 1);
        return "You venture into the forest and forage for nuts and berries, restoring your hunger. *Still poisoned";
    }else
    return "You venture into the forest and forage for nuts and berries, restoring your hunger";
    
}
///////////////////////////////////////////////////////////////
string Lake::getDescription(){
    return "a sparkling clear lake.";
}

string Lake::visit(Player& player){
    player.setThirst(player.getThirst() + 3);
    if(player.isPosioned()){
        player.setHealth(player.getHealth() - 1);
         return "You drink from the lake, re-hydrating yourself. *Still poisoned!";
    }else
    return "You drink from the lake, re-hydrating yourself.";
}