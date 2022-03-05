#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    set<int> passerelles;
    map<int, set<int>> voisins;
    set<int> nodes;
    cin >> n >> l >> e; cin.ignore();
    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        cin >> n1 >> n2; cin.ignore();
        voisins[n1].insert(n2);
        voisins[n2].insert(n1);
        nodes.insert(n1);
        nodes.insert(n2);
    }
 

    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        cin >> ei; cin.ignore();
        passerelles.insert(ei);
    }

    // game loop
    while (1) {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        vector<int> file;
        map<int, int> predecesseur;
        map<int, bool> marque;

        auto it = nodes.begin();
        while(it != nodes.end())
        {
            marque.insert(make_pair(*it, false));
            it++;
        }

        marque[si] = true;
        file.push_back(si);
        int r1, r2;

        while(!file.empty())
        {
            
            int u = * file.begin();
            auto ite = voisins[u].begin();
            while(ite != voisins[u].end())
            {
    
                if(!marque[*ite])
                {
                    marque[*ite] = true;
                    predecesseur[*ite] = u;
                    file.push_back(*ite);
                }
                if(passerelles.find(*ite) != passerelles.end())
                {
               
                    r1 = u;
                    r2 = *ite;
                    auto supp = voisins[r1].find(r2);
                    auto supp2 = voisins[r2].find(r1);
                    if(supp != voisins[r1].end())
                        voisins[r1].erase(supp );
                    if(supp2 != voisins[r2].end())
                        voisins[r2].erase(supp2 );
                    goto end;
                }
                ite++;
            }
            
            file.erase(file.begin());
        }
        end:
          cout << r1 << " " << r2 << endl;
    }
}
