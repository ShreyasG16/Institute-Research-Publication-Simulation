#include <iostream>
#include <vector>
#include "Publication.h"
#include "InstituteAuthor.h"
#include "NonInstituteAuthor.h"
#include "PublicationManager.h"

using namespace std;

int main() {
    PublicationManager manager;
    
    while (true) {
        cout << "1. Add New Publication\n";
        cout << "2. View All Publications\n";
        cout << "3. View Publications by Year Range\n";
        cout << "4. Clear All Publications\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: { 
                string title, venue, doi;
                int year, numAuthors;

                cout << "Enter title: ";
                cin.ignore();  
                getline(cin, title);

                cout << "Enter venue: ";
                getline(cin, venue);

                cout << "Enter number of authors: ";
                cin >> numAuthors;

                vector<Author*> authors;
                bool hasInstituteAuthor = false; 

                for (int i = 0; i < numAuthors; ++i) {
                    string name, affiliation;
                    
                    cin.ignore(); 
                    cout << "Enter author name: ";
                    getline(cin, name);
                    
                    cout << "Enter author affiliation: ";
                    getline(cin, affiliation);

                    
                    if (affiliation == "IIIT-Delhi") {
                        authors.push_back(new InstituteAuthor(name));
                        hasInstituteAuthor = true; 
                    } else {
                        authors.push_back(new NonInstituteAuthor(name, affiliation));
                    }
                }

                if (!hasInstituteAuthor) {
                    cout << "Error: At least one author must have 'Institute Affiliation'.\n";
                  
                    for (auto author : authors) {
                        delete author;
                    }
                    break; 
                }

                cout << "Enter DOI (optional): ";
                cin.ignore(); 
                getline(cin, doi);

                if (!doi.empty()) {
                    doi = "https://doi.org/" + doi;
                }

                cout << "Enter year of publication: ";
                cin >> year;

                Publication* newPub = new Publication(title, venue, authors, doi, year);
                manager.addPublication(newPub);
                
                break;
            }
            case 2: { 
                manager.viewPublications();
                break;
            }
            case 3: { 
                int startYear, endYear;
                cout << "Enter start year: ";
                cin >> startYear;
                cout << "Enter end year: ";
                cin >> endYear;

                manager.viewPublicationsByYear(startYear, endYear);
                break;
            }
            case 4: { 
                manager.clearPublications();
                cout << "All publications cleared.\n";
                break;
            }
            case 5: { 
                return 0;
            }
            default:
                cout << "Invalid option. Please try again.\n";
        }
        
        cout << endl; 
    }

    return 0;
}
