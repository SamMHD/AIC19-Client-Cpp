#ifndef AIC18_CLIENT_CPP_GAME_H
#define AIC18_CLIENT_CPP_GAME_H

#include "Map.h"
#include "GameConstants.h"
#include "AbilityConstants.h"
#include "HeroConstants.h"
#include "Hero.h"

class Game {
public:

    Game();
    ~Game();//delete the vector items...


    //Getter & Setters:

    void set_map(const Map &_map);
    const Map &get_map() const;
    Map& map();


    void set_gameConstants(const GameConstants &_gameConstants);
    const GameConstants &get_gameConstants() const;
    GameConstants& gameConstants();

    void set_abilityConstants(const AbilityConstants &_abilityConstants);
    const AbilityConstants &get_abilityConstants() const;
    AbilityConstants& abilityConstants();

    void set_heroConstants(const HeroConstants &_heroConstants);
    const HeroConstants &get_heroConstants() const;
    HeroConstants& heroConstants();

    void set_AP(int _AP);
    int get_AP() const;
    int& AP();


    void set_score(int _score);
    int get_score() const;
    int& score();



    // For all Cell type inputs we will have another method with row-column inputs
    // For all hero id inputs we will have another method with Hero object
    // For all Ability Object inputs we will have another method with AbilityName enum

    Hero getHero(int id);
    Hero getMyHero(Cell cell);
    Hero getOppHero(Cell cell);

    // Get all the cells that collide with the ray line in at least one non corner point,
    // before reaching a wall. If it hits a wall cell just in the corner,
    // it would also stop too. should we implement this?
    const std::vector<Cell *> &getRayCells(Cell startCell, Cell endCell);
    Cell getImpactCell(Ability ability, Cell startCell, Cell targetCell);
    const std::vector<Direction *> &getPathMoveDirections(Cell startCell, Cell endCell);

    int manhattanDistance(Cell startCell, Cell endCell);
    bool isInVision(Cell startCell, Cell endCell);
    bool isAccessible(int row, int column);

    void castAbility(int id, Ability ability, Cell targetCell);
    void moveHero(int id, Direction direction);
    void pickHero(HeroName heroName);


private:

    Map _map;
    GameConstants _gameConstants;
    AbilityConstants _abilityConstants;
    HeroConstants _heroConstants;

    std::vector<Hero *> _myHeroes;
    std::vector<Hero *> _oppHeroes;
    std::vector<Hero *> _myDeadHeroes;

    std::vector<Cell *> _brokenWalls;
    std::vector<Cell *> _createdWalls;

    int _AP;
    int _score;
};


#endif //AIC18_CLIENT_CPP_GAME_H
