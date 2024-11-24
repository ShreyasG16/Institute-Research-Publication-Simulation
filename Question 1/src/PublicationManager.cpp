#include "PublicationManager.h"
#include <iostream>

PublicationManager::~PublicationManager() {
    for (auto pub : publications) {
        delete pub; 
    }
}

void PublicationManager::addPublication(Publication* pub) {
    publications.push_back(pub);
}

void PublicationManager::viewPublications() const {
    if (publications.empty()) {
        std::cout << "No publications available.\n";
        return;
    }
    
    for (const auto& pub : publications) {
        pub->display();
        std::cout << "------------------------\n";
    }
}

void PublicationManager::viewPublicationsByYear(int startYear, int endYear) const {
    bool found = false;
    
    for (const auto& pub : publications) {
        if (pub->getYear() >= startYear && pub->getYear() <= endYear) {
            pub->display();
            found = true;
            std::cout << "------------------------\n";
        }
    }
    
    if (!found) {
        std::cout << "No publications found in the specified year range.\n";
    }
}

void PublicationManager::clearPublications() {
    for (auto pub : publications) {
        delete pub; 
    }
    publications.clear(); 
}