#ifndef PUBLICATION_MANAGER_H
#define PUBLICATION_MANAGER_H

#include <vector>
#include "Publication.h"
using namespace std;

class PublicationManager {
private:
    vector<Publication*> publications; 

public:
    ~PublicationManager();
    
    void addPublication(Publication* pub); 
    void viewPublications() const;          
    void viewPublicationsByYear(int startYear, int endYear) const; 
    void clearPublications();               
};

#endif 