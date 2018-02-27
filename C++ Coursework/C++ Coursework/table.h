//
//  table.h
//  Coursework C++ 
//
//  Created by Sarath Vaman on 24/11/2017.
//  Copyright © 2017 Sarath Vaman. All rights reserved.
//

#ifndef table_h
#define table_h

#include "record.h" 
#include <vector>
#include <map>

class table {
    //add contain for storing names and records
    std::map<std::string, record>m;
    
public:
    
    void add_score(const std::string &name, double score);
    int num_players() const;
    std::vector<std::string> print_best_recent(int n) const;
    double average_best() const;
    std::string best_overall() const;
    int novice_count() const;
};

#endif /* table_h */

