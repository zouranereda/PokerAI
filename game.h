#ifndef POKERAI_GAME_H
#define POKERAI_GAME_H

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include "pokerAI.h"
#include "cards.h"

using namespace std;

#define CALL_OR_CHECK 0
#define FOLD 1
#define RAISE 2

typedef struct _player{

    string name;
    int bankRoll;
    pair<int, int> hand;
    int pendingBet;

}player;

class game{
public:
    int pot;
    int buyIn;

    int nbPlayers;
    vector<player> players;
    vector<int> stillPlaying;

    pair<int, int> bigBlind;
    pair<int, int> smallBlind;

    int* deck;
    int indexDeck;

    int* communityCards;

    game(int buyin);
    ~game();
    void initializeRound();
    void dealPlayersCards();
    void collectBets(int nbCardsDealt);
    void evaluateRound();
    void nextRound();

};

#endif //POKERAI_GAME_H
