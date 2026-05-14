#include "Matchmaking.hpp"

int main() {
    int n = 0;

    // Criando o matchmaking. Tema: Xadrez e Damas
    std::cout << "\n#____# Criando o matchmaking. Tema: Xadrez e Damas #____#\n\n";
    std::cout << "Matchmaking xadrez;\nMatchmaking damas;\n\n";
    Matchmaking xadrez;
    Matchmaking damas;

    // Adicionando jogadores
    std::cout << "#____# Adicionando jogadores #____#\n";
    std::cout << "xadrez.insert(Player(1, \"Ana\", 1240, 1));\n";
    std::cout << "xadrez.insert(Player(2, \"Bruna\", 1030, 2));\n";
    std::cout << "xadrez.insert(Player(3, \"Carlos\", 1010, 3));\n";
    std::cout << "xadrez.insert(Player(4, \"Daniel\", 1000, 4));\n";
    std::cout << "xadrez.insert(Player(5, \"Estácio\", 1650, 5));\n";
    std::cout << "\n";
    std::cout << "damas.insert(Player(1, \"Alana\", 1950, 1));\n";
    std::cout << "damas.insert(Player(2, \"Bernardo\", 1900, 2));\n";
    std::cout << "damas.insert(Player(3, \"Carolina\", 1950, 3));\n\n";
    xadrez.insert(Player(1, "Ana", 1240, 1));
    xadrez.insert(Player(2, "Bruna", 1030, 2));
    xadrez.insert(Player(3, "Carlos", 1010, 3));
    xadrez.insert(Player(4, "Daniel", 1000, 4));
    xadrez.insert(Player(5, "Estácio", 1650, 5));

    damas.insert(Player(1, "Alana", 1950, 1));
    damas.insert(Player(2, "Bernardo", 1900, 2));
    damas.insert(Player(3, "Carolina", 1950, 3));

    // Mostrando os jogadores
    std::cout << "#____# Exibindo os jogadores de xadrez #____#\n";
    xadrez.printWaitingPlayers();
    std::cout << "#____# Exibindo os jogadores de damas #____#\n";
    damas.printWaitingPlayers();

    // Removendo um jogador: encontrou e não encontrou
    std::cout << "#____# Removendo um jogador existente do xadrez #____#\n";
    std::cout << "xadrez.removePlayer(2);\n\n";
    xadrez.removePlayer(2);
    xadrez.printWaitingPlayers();

    std::cout << "#____# Tentando remover um jogador não existente em damas #____#\n";
    std::cout << "damas.removerPlayer(0);\n\n";
    damas.removePlayer(0);
    damas.printWaitingPlayers();

    // Ordenando xadrez e damas com, respectivamente, merge e inserction
    std::cout << "#____# Ordenando xadrez e damas com, respectivamente, merge e inserction #____#\n";
    std::cout << "xadrez.sortByScoreMerge();\n\n";
    xadrez.sortByScoreMerge();
    xadrez.printWaitingPlayers();

    std::cout << "damas.sortByScoreInserction();\n\n";
    damas.sortByScoreInsertion();
    damas.printWaitingPlayers();

    // Formando um grupo: Deu certo
    std::cout << "#____# Pareando dois jogadores de xadrez #____#\n";
    std::cout << "Player* p = xadrez.formGroup(3, 30, &n);\n\n";
    Player* p = xadrez.formGroup(2, 30, &n);

    std::cout << "#____# Oponentes pareados: Que vença o melhor! #____#\n";
    std::cout << "De brancas: ";
    p[0].print();
    std::cout << "De pretas: ";
    p[1].print();
    std::cout << "\n";

    // Tentando parear um grupo
    std::cout << "#____# Tentando parear dois jogadores de xadrez #____#\n";
    std::cout << "Player* r = xadrez.formGroup(2, 30, &n);\n\n";
    Player* r = xadrez.formGroup(2, 30, &n);
    std::cout << "Erro! Diferença muito grande entre os scores:\n";
    xadrez.printWaitingPlayers();

    // Pareando todos os jogadores
    std::cout << "#____# Pareando os 3 jogadores de damas #____#\n";
    std::cout << "(Não me pergunte como eles jogarão damas em trio)\n";
    std::cout << "Player* q = damas.formGroup(3, 100, &n);\n\n";
    Player* q = damas.formGroup(3, 100, &n);

    std::cout << "#____# Oponentes pareados! #____#\n";
    std::cout << "De brancas: ";
    q[0].print();
    std::cout << "De pretas: ";
    q[1].print();
    std::cout << "De ????: ";
    q[2].print();
    std::cout << "\n";

    // Tentando parear sem jogadores na lista de espera
    std::cout << "Seja lá o que aconteceu nas damas em trio, vamos tentar parear uma\n";
    std::cout << "nova partida, agora entre 2 jogadores:\n";
    std::cout << "Player* s = damas.formGroup(2, 50, &n);\n\n";
    Player* s = damas.formGroup(2, 50, &n);
    std::cout << "Erro, não há ninguém na lista de espera:\n\n";
    damas.printWaitingPlayers();

    std::cout << "#____# getWaintingPlayers #____#\n";
    std::cout << "Antes de ir embora, vamos ver os jogadores de xadrez\n";
    std::cout << "que ficarão esperando para ser pareados:\n";
    std::cout << "Player* t = xadrez.getWaitingPlayers();\n\n";
    Player* t = xadrez.getWaitingPlayers(&n);
    for(int i = 0; i < n; i++) {
        t[i].print();
    }
    std::cout << "\nÉ isso, espero que tenha gostado!\n";

    delete[] p;
    delete[] q;
    delete[] r;
    delete[] s;
    delete[] t;
    return 0;
}