//
//  record.h
//  Coursework C++ 
//
//  Created by Sarath Vaman on 24/11/2017.
//  Copyright © 2017 Sarath Vaman. All rights reserved.
//

#ifndef record_h
#define record_h

#include <vector>
#include <string>
#include <deque>

class record{
    // a container for storing record;
    std::deque <double> scores;
    
public:
    record();
    record(double score);
    void add_score(double score);
    
    double best_score() const;
    double overall_average() const;
    double recent_average() const;
    bool novice() const;
    int size() const;
};

#endif /* record_h */

