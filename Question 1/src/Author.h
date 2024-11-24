#ifndef AUTHOR_H
#define AUTHOR_H
using namespace std;

#include <string>

class Author {
protected:
    string name;
    string affiliation;

public:
    Author(const string &name, const string &affiliation);
    virtual ~Author() {}
    
    string getName() const;
    string getAffiliation() const;
};

#endif 