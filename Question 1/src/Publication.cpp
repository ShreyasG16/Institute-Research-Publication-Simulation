#include "Publication.h"
#include <iostream>
using namespace std;

Publication::Publication(const string &title, const string &venue,const vector<Author*> &authors, const string &doi, int year): title(title), venue(venue), authors(authors), doi(doi), year(year)
{
        assert(!authors.empty());       
        bool hasInstituteAffiliation = false;
        for (const auto& author : authors) 
        {
            if (author->getAffiliation() == "Institute Affiliation") {
                hasInstituteAffiliation = true;
                break;
            }
        }
        assert(hasInstituteAffiliation); 
}

Publication::~Publication() {
    for (auto author : authors) {
        delete author; 
    }
}

void Publication::display() const {
    cout << "Title: " << title << "\nVenue: " << venue << "\nYear: " << year << "\nDOI: " << doi << "\nAuthors:\n";
    for (const auto& author : authors) {
        cout << "- " << author->getName() << " (" << author->getAffiliation() << ")\n";
    }
}

int Publication::getYear() const
{
    return year;
}