#include "Player.hpp"

const int MAX_PLAYERS = 100;

class Matchmaking {

private:

    Player players[MAX_PLAYERS];
    int size;

public:

    Matchmaking();
    ~Matchmaking();

    bool insert(Player player);
    bool removePlayer(int id);
    bool removeInterval(int start, int end);

    void sortByScoreInsertion();
    void sortByScoreMerge();
    
    // Auxiliares para o Merge Sort
    void mergeAux(int l, int r);
    void merge(int l, int m, int r);

    Player* formGroup(int groupSize, int delta, int* n);

    Player* getWaitingPlayers(int* n);

    void printWaitingPlayers();

};
