//
//  record.cpp
//  Coursework C++ 
//
//  Created by Sarath Vaman on 24/11/2017.
//  Copyright © 2017 Sarath Vaman. All rights reserved.
//

#include "record.h"
#include <stdio.h>
#include <deque>
#include <algorithm>

using namespace std;
 
record::record(){}
record::record(double score){scores.push_back(score);}
void record:: add_score(double score){scores.push_back(score);}

// finds the highest score in the record
double record:: best_score() const {
    deque<double>::const_iterator p = scores.cbegin();
    double largest = 0;
    while (p != scores.cend()) {
        if (*p > largest)
            largest = *p;
        ++p; }
    return largest;
    
}

//finds the overall average of scores stored in record
double record::overall_average() const {
    double sum = 0;
    if (scores.size()==0)
        return 0; // no score is found in record returns 0
    
    typedef deque<double>::const_iterator iter;
    for (iter p = scores.cbegin(); p != scores.cend(); ++p)
        sum += *p;
    return sum / scores.size(); 
    
} 

// finds the average of the 10 most recent scores added to record
double record::recent_average() const {
    double sum = 0;
    if (scores.size() == 0)
        return 0; // no score is found in record, it returns 0
    typedef deque <double> :: const_iterator iter;
    if (scores.size() <10){
        for (iter p = scores.cbegin(); p !=scores.cend(); ++p)
            sum+=*p;
        return sum/scores.size();} //10 or less scores are found, scores are added together then a mean is taken
    else{
        for (iter p = scores.cend(); p !=scores.cend()-10; --p)
            sum+=*p;
        return sum/10;} // 10 or more scores are found , the last 10 scores stored at the end of the record are averaged out
    ;}  


bool record::novice() const {return scores.size() < 10;} // returns true if fewer than 10 scores have been recorded

int record :: size() const {return scores.size();}
