#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

deque<int>* deck1, * deck2;
map<string, int> order;
//vector<string> win_cards;
vector<int> pot1, pot2;
int nbWar = 1;
bool currently_in_war = false;

void init()
{
    order.insert(make_pair("2", 1));
    order.insert(make_pair("3", 2));
    order.insert(make_pair("4", 3));
    order.insert(make_pair("5", 4));
    order.insert(make_pair("6", 5));
    order.insert(make_pair("7", 6));
    order.insert(make_pair("8", 7));
    order.insert(make_pair("9", 8));
    order.insert(make_pair("10", 9));
    order.insert(make_pair("J", 10));
    order.insert(make_pair("Q", 11));
    order.insert(make_pair("K", 12));
    order.insert(make_pair("A", 13));
}

bool gagne(string s1, string s2)
{
    s1.erase(std::prev(s1.end()));
    s2.erase(std::prev(s2.end())); 
    if(order.find(s1) == order.end())
        cerr << "aaa";
    else if(order.find(s2) == order.end())
        cerr << "aaa";
    else if(order[s1] > order[s2])
        return true;
    else
        return false;

    return false;
}

void war() 
{

    int v1 = deck1->front();
    deck1->pop_front();
    int v2 = deck2->front();
    deck2->pop_front();
 
    

    if(v1!=v2)
    {
        pot1.push_back(v1);
        pot2.push_back(v2);
        if(v1 > v2)
        {
            for(auto a : pot1)
            {
                deck1->push_back(a);
            }
            for(auto a : pot2)
            {
                deck1->push_back(a);
            }
        }
        else
        {
            for(auto a : pot1)
            {
                deck2->push_back(a);
            }
            for(auto a : pot2)
            {
                deck2->push_back(a);
            }
        }
        pot1.clear();
        pot2.clear();
        if(deck1->size() == 0)
        {
            cout << "2 "<< nbWar << endl;
            return;
        }
        else if(deck2->size() == 0)
        {
            cout << "1 "<< nbWar << endl;
            return;
        }
        nbWar++;;
        
        
    }
    else if(deck1->size() < 3 || deck2->size() < 3)
    {
        cout << "PAT" << endl;
        return;
    }
    else
    {
        pot1.push_back(v1);
        pot2.push_back(v2);
        for(int i = 0; i < 3; i ++)
        {
            int a = deck1->front();
            deck1->pop_front();
            pot1.push_back(a);
        }
        for(int i = 0; i <3; i ++)
        {
            int a = deck2->front();
            deck2->pop_front();
            pot2.push_back(a);
        }
        
    }
    war();
}

int main()
{
    init();
    deck1 = new deque<int>();
    deck2 = new deque<int>();
    int n; // the number of cards for player 1
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string cardp_1; // the n cards of player 1
        cin >> cardp_1; cin.ignore();
        cardp_1.erase(std::prev(cardp_1.end()));
        deck1->push_back(order[cardp_1]);
    }
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        string cardp_2; // the m cards of player 2
        cin >> cardp_2; cin.ignore();
        cardp_2.erase(std::prev(cardp_2.end()));
        deck2->push_back(order[cardp_2]);
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    war();
    return 0;
}
