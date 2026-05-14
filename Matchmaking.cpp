#include "Matchmaking.hpp"

// Questão 1
Matchmaking::Matchmaking() : size(0) {}

Matchmaking::~Matchmaking() {}

// Questão 2
bool Matchmaking::insert(Player player) {
    if (size < MAX_PLAYERS) {
        players[size] = player;
        size++;
        return true;
    }

    return false;
}

// Questão 3
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

// Questão 4
void Matchmaking::sortByScoreInsertion() {
    int i, j, score;
    Player curr;

    for(i = 1; i < size; i++) {
        curr = players[i];
        score = curr.getScore();
        j = i - 1;

        while(j >= 0 && (players[j].getScore() > score || 
                        (players[j].getScore() == curr.getScore() && players[j].getTimestamp() > curr.getTimestamp()))) {

            players[j + 1] = players[j];
            j--;
        }

        players[j + 1] = curr;
    }
}


void Matchmaking::merge(int left, int m, int right)
{
    int n1 = m - left + 1;
    int n2 = right - m;

    Player* up = new Player[n1];
    Player* down = new Player[n2];
    
    for (int i = 0; i < n1; i++) up[i] = players[left + i];
    for (int j = 0; j < n2; j++) down[j] = players[m + 1 + j];
    
    int i = 0;
    int j = 0;
    int k = left; // índice do array players

    while (i < n1 && j < n2)
    {
        if (up[i].getScore() < down[j].getScore()) {
            players[k] = up[i];
            i++;
        } else if (up[i].getScore() == down[j].getScore() && up[i].getTimestamp() < down[j].getTimestamp()) {
            players[k] = up[i];
            i++;
        } else {
            players[k] = down[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        players[k] = up[i];
        i++;
        k++;
    }
    while (j < n2) {
        players[k] = down[j];
        j++;
        k++;
    }

    delete[] up;
    delete[] down;
}

void Matchmaking::mergeAux(int left, int right)
{
  if (left < right) {
    int m = left + (right - left) / 2;

    mergeAux(left, m);
    mergeAux(m + 1, right);

    merge(left, m, right);
  } 
}

void Matchmaking::sortByScoreMerge() 
{
    if (size > 1) {
        mergeAux(0, size - 1);
    }
}

// Questão 5
bool Matchmaking::removeInterval(int start, int end) {
    if(end >= size) {
        return false;
    }

    int elementsToRemove = end - start + 1;
    int elementsToShift = size - end - 1;
    
    // Desloca os elementos após 'end' para a posição 'start'
    for (int i = 0; i < elementsToShift; i++) {
        players[start + i] = players[end + 1 + i];
    }
    
    size -= elementsToRemove;
    return true;
}

Player* Matchmaking::formGroup(int groupSize, int delta, int* n) {
    int head = 0;
    int tail = groupSize - 1;

    // Procura por um grupo de jogadore consecutivos dentro do delta
    while(tail < size) {
        if(players[tail].getScore() - players[head].getScore() <= delta) {
            break;
        }

        head++;
        tail++;
    }

    // Não encontrou um grupo
    if(tail >= size) {
        *n = 0;
        return nullptr;
    }

    *n = groupSize;

    // Copia os players do grupo para um array, enquanto
    // elimina-os da lista de espera
    Player* group = new Player[groupSize];

    for(int i = head; i <= tail; i++) {
        group[i - head] = players[i];
    }

    removeInterval(head, tail);

    return group;
}

// Questão 6
Player* Matchmaking::getWaitingPlayers(int* n) {
    *n = size;

    if(size == 0) {
        return nullptr;
    }

    Player* wp = new Player[size];
    for(int i = 0; i < size; i++) {
        wp[i] = players[i];
    }

    return wp;
}

// Questão 7
void Matchmaking::printWaitingPlayers() {

    if(size == 0) {
        std::cout << "(empty)\n\n";
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
    std::cout << "\n";
}
