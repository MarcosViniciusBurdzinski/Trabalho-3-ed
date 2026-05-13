#include "Matchmaking.hpp"

Matchmaking::Matchmaking() : size(0) {}

Matchmaking::~Matchmaking() {}

bool Matchmaking::insert(Player player) {
    if (size < MAX_PLAYERS) {
        players[size] = player;
        size++;
        return true;
    }

    return false;
};

bool Matchmaking::removePlayer(int id) {

    int i = 0;

    // Percorre a lista em busca de um player com tal id
    for(i = 0; i < size; i++) {
        if(players[i].getId() == id) {
            break;
        }
    }

    // Completou o loop sem encontrar alguém com tal id
    if(i == size) {
        return false;
    }

    // Encontrou: Atualiza a lista de jogadores
    for(int j = i + 1; j < size; j++) {
        players[j - 1] = players[j];
    }

    size--;
    return true;
};

void Matchmaking::sortByScoreInsertion() {};
void Matchmaking::sortByScoreMerge() {};
Player* Matchmaking::formGroup(int groupSize, int delta, int* n) {};
Player* Matchmaking::getWaitingPlayers(int* n) {};
void Matchmaking::printWaitingPlayers() {};
