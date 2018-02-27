//
//  table.cpp
//  Coursework C++ 
//
//  Created by Sarath Vaman on 24/11/2017.
//  Copyright © 2017 Sarath Vaman. All rights reserved.
//

#include "table.h"
#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void table::add_score(const string &name, double score){m[name].add_score(score);}
int table::num_players() const {return int(m.size());}

// the methods is a binary predicate for print_best_recent(), comparing the value of pair A to B
bool compare_best_recent(const pair<string, record> &a, const pair<string, record> &b) {
    return a.second.recent_average() > b.second.recent_average();
}

//find the name of players with highest score
vector<string> table::print_best_recent(int n) const
{
    vector<string> names;                   //names of the players are stored in a vector
    vector<pair<string, record>> players;   //players name and their scores are stored in a vector in pairs
    
    typedef map<string, record>::const_iterator iter;
    for (iter p = m.cbegin(); p != m.cend(); ++p) {
        players.push_back(*p);  
    }     //iterator steps through the map and the map values are pushed to the back of the player vector
    
    sort(players.begin(), players.end(), compare_best_recent); // sorts player pairs from highest to lowest
    
    for (int i = 0; i < n && i < players.size(); ++i) {
        names.push_back(players[i].first);
    }
    return names;
}

//finds average of the best scores of all players
double table :: average_best() const {
    double sum = 0;
    if (m.size() == 0)
        return 0;
   
    typedef map<string,record>::const_iterator iter;
    for (iter p = m.cbegin(); p != m.cend(); ++p)
        sum += p->second.best_score();
    return sum / m.size();
}

//finds the player with highest overall average
string table :: best_overall() const {
    typedef map<string, record> :: const_iterator iter;
    double largest =0;
    double overall;
    string name;
    
    for(iter p = m.cbegin(); p!= m.cend(); ++p){
        overall= p->second.overall_average();
        if (largest<overall){
            name = p->first;
            largest=overall;
        }
    }
    return name;}

//the method is a unary predicate for the novice_count,
bool novice_test(pair<string, record> p){return p.second.novice();}

//counts the number of novices
int table ::novice_count() const {return count_if(m.cbegin(), m.cend(), novice_test);}
