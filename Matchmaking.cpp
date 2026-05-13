#include "Matchmaking.hpp"

Matchmaking::Matchmaking() {
    size = 0;

    for(int i = 0; i < MAX_PLAYERS; i++) {
        players[i] = Player();
    }

}

Matchmaking::~Matchmaking() {}

bool Matchmaking::insert(Player player) {
    if (size < MAX_PLAYERS) {
        players[size] = player;
        size++;
        return true;
    }

    return false;
};

// Busca binária pelos id's (Custo O(log(100000)))
bool Matchmaking::removePlayer(int id) {};
void Matchmaking::sortByScoreInsertion() {};
void Matchmaking::sortByScoreMerge() {};
Player* Matchmaking::formGroup(int groupSize, int delta, int* n) {};
Player* Matchmaking::getWaitingPlayers(int* n) {};
void Matchmaking::printWaitingPlayers() {};