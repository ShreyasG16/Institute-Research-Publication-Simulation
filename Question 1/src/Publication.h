#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <vector>
#include <string>
#include <cassert>
#include "Author.h"
using namespace std;

class Publication {
private:
    string title;
    string venue;
    vector<Author*> authors; 
    string doi;             
    int year;                    

public:
    Publication(const string &title, const string &venue,const vector<Author*> &authors, const string &doi = "", int year = 0);
    
    ~Publication();
    
    void display() const; 
    int getYear() const;  
};

#endif 