// Include all standard libraries (play it safe, as we should)
#include <bits/stdc++.h>
using namespace std;

struct Data
{
    int ROUNDS;
    int N_PLAYERS;
    int ORDER;
    int HANDS;
    int DEALERS;
    map<int, int> DECK;
    vector<int> PLAYERS_DATA;
}
DATA;

void SET_DECK(map<int, int> &DECK)
{
    for(int i = 1; i <= 10; i++) {DECK[i] = (i == 10)? 16 : 4;}
}

void PRINT_DECK(map<int, int> DECK)
{
    for(auto x : DECK) {cout << "[ " << x.first << " ]  -->>  " << x.second << '\n';}
}

void GAME_SETUP(Data *DATA)
{
    // Initiate Deck;
    SET_DECK((*DATA).DECK);

    // Initiate game data
    cout << "Enter number of rounds : ";
    int rounds; cin >> rounds;
    (*DATA).ROUNDS = rounds;
    cout << "Enter number of players : ";
    int players; cin >> players;
    (*DATA).N_PLAYERS =  players;
    for(int i = 0; i < players; i++) {(*DATA).PLAYERS_DATA.push_back(0);}
    cout << "Enter your position on the table : ";
    int orders; cin >> orders;
    (*DATA).ORDER = orders;
}

void ROUND_SETUP(Data *DATA)
{
    SET_DECK((*DATA).DECK);
    for(int i = 0; i < (*DATA).N_PLAYERS; i++)
    {
        (*DATA).PLAYERS_DATA[i] = 0;
    }
}

int CHECK(int x)
{
    if(x >= 21)
    {
        if(x > 21)
        {
            cout << "---BUST---" << '\n';
        }
        else
        {
            cout << "---YOU WIN---" << '\n';
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

double GENERATE_HIT_PROBABILITY(Data *DATA)
{
    int total_cards = 0;
    int available_cards = 0;
    int upper_bound = (21 - (*DATA).HANDS);
    for(auto x : (*DATA).DECK) {total_cards += x.second;}
    for(auto x : (*DATA).DECK) {available_cards += (x.first <= upper_bound)? x.second : 0;}
    // cout << upper_bound << available_cards << ' ' << total_cards << '\n';
    return ((double)available_cards/(double)total_cards)*100;
}

double GENERATE_STAND_PROBABILITY(Data *DATA)
{
    int total_cards = 0;
    int available_cards = 0;
    int lower_bound = ((*DATA).HANDS - (*DATA).DEALERS);
    for(auto x : (*DATA).DECK) {total_cards += x.second;}
    for(auto x : (*DATA).DECK) {available_cards += (x.first < lower_bound)? x.second : 0;}
    // cout << lower_bound << available_cards << ' ' << total_cards << '\n';
    return ((double)available_cards/(double)total_cards)*100;
}

void GENERATE_PROBABILITY(Data *DATA)
{
    double HIT = GENERATE_HIT_PROBABILITY(DATA);
    double STAND = GENERATE_STAND_PROBABILITY(DATA);
    cout << "----------------" << '\n';
    cout << "WIN% IF YOU  --HIT--  : " << HIT << "%" <<  '\n';
    cout << "WIN% IF YOU --STAND-- : " << STAND << "%" << '\n';
    cout << "----------------" << '\n';
}

void PLAY(Data *DATA)
{
    // WELCOME MESSAGE
    cout << '\n' << "---WELCOME TO BLACKJACK---" << '\n';

    // PLAYERS CARD SETUP
    for(int i = 1; i <= (*DATA).N_PLAYERS; i++)
    {
        int first, second;
        if(i == (*DATA).ORDER)
        {
            cout << "--Enter your cards--" << '\n';
            cout << "CARD 1 : "; cin >> first;
            cout << "CARD 2 : "; cin >> second;
            (*DATA).DECK[first]--; (*DATA).DECK[second]--;
            (*DATA).HANDS = first + second;
        }
        else
        {
            cout << "--Enter player " << i << " cards--" << '\n';
            cout << "CARD 1 : "; cin >> first;
            cout << "CARD 2 : "; cin >> second;
            (*DATA).DECK[first]--; (*DATA).DECK[second]--;
        }
        (*DATA).PLAYERS_DATA[i-1] += (first+second);
    }
    
    // DEALERS CARD SETUP
    cout << "--ENTER DEALERS CARD--" << '\n';
    cout << "CARD : "; cin >> (*DATA).DEALERS;
    (*DATA).DECK[(*DATA).DEALERS]--;
    
    // ACTIONS PLAY
    for(int i = 1; i <= (*DATA).N_PLAYERS; i++)
    {
        string actions;
        if(i == (*DATA).ORDER)
        {
            cout << "\n" << "---GAMETIME---" << '\n';
            GENERATE_PROBABILITY(DATA);
            cout << "HIT/STAND : "; cin >> actions;
            if(actions == "HIT")
            {
                while(actions == "HIT")
                {
                    int card; 
                    cout << "ENTER OBTAINED CARD : "; cin >> card;
                    (*DATA).HANDS += card; 
                    (*DATA).DECK[card]--; (*DATA).PLAYERS_DATA[i-1] += card;
                    if(CHECK((*DATA).PLAYERS_DATA[i-1])) break;
                    GENERATE_PROBABILITY(DATA);
                    cout << "HIT/STAND : "; cin >> actions;
                }
            }
            else continue;    
        }
        else
        {
            cout << '\n' << "PLAYER " << i << " TURNS!" << '\n';
            cout << "HIT/STAND : "; cin >> actions;
            if(actions == "HIT")
            {
                int card;
                while(actions == "HIT")
                {
                    cout << "ENTER OBTAINED CARD : "; cin >> card;
                    (*DATA).DECK[card]--; (*DATA).PLAYERS_DATA[i-1] += card;
                    if(CHECK((*DATA).PLAYERS_DATA[i-1])) break;
                    cout << "HIT/STAND : "; cin >> actions;
                }
            }
            else continue;
        }
    }
    ROUND_SETUP(DATA);
}

int main()
{
    GAME_SETUP(&DATA);
    while(DATA.ROUNDS--)
    {
        PLAY(&DATA);
    }
}


