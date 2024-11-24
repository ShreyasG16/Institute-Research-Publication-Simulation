#include "Author.h"
using namespace std;

Author::Author(const string &name, const string &affiliation)
    : name(name), affiliation(affiliation) {}

string Author::getName() const {
    return name;
}

string Author::getAffiliation() const {
    return affiliation;
}