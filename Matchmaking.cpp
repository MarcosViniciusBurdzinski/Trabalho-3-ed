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
}

bool Matchmaking::removePlayer(int id) 
{
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
}

void Matchmaking::sortByScoreInsertion() {
    int i, j, score;
    Player curr;

    for(i = 1; i < size; i++) {
        curr = players[i];
        score = curr.getScore();
        j = i - 1;

        while(j >= 0 && players[j].getScore() > score) {
            players[j + 1] = players[j];
            j--;
        }

        players[j + 1] = curr;
    }
}

void Matchmaking::sortByScoreMerge() {}
Player* Matchmaking::formGroup(int groupSize, int delta, int* n) {}
Player* Matchmaking::getWaitingPlayers(int* n) {}

void Matchmaking::printWaitingPlayers() {

    if(size == 0) {
        std::cout << "(empty)\n";
        return;
    }

    std::cout << "Waiting players:\n";
    for(int i = 0; i < size; i++) {

        int id = players[i].getId();
        std::string n = players[i].getName();
        int s = players[i].getScore();
        int t = players[i].getTimestamp();

        std::cout << "[" << id << " | " << n << " | " << s << " | " << t << "]\n";
    }
}
