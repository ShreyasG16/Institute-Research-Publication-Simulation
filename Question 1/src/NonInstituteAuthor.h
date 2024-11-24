#ifndef NON_INSTITUTE_AUTHOR_H
#define NON_INSTITUTE_AUTHOR_H

#include "Author.h"
using namespace std;

class NonInstituteAuthor : public Author {
public:
    NonInstituteAuthor(const string &name, const string &affiliation);
};

#endif 