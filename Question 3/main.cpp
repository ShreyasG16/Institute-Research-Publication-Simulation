#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cstdlib> 

using namespace std;

struct BibEntry {
    string title;
    string venue;
    int year;
    string doi;
    vector<string> coAuthors; 
};

string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
}

void processBibFile(map<string, vector<BibEntry>>& authorMap, const string& bibFile) {
    ifstream file(bibFile);
    string line;
    BibEntry currentEntry;

    if (file.is_open()) {
        while (getline(file, line)) {
           
            if (line.find("author") != string::npos) 
            {
                
                size_t pos = line.find("author");
                size_t start = line.find("{", pos);
                size_t end = line.find("}", start);
                string authorList = line.substr(start + 1, end - start - 1);

                replace(authorList.begin(), authorList.end(), ',', ' ');
                stringstream ss(authorList);
                vector<string> authors;
                string author;
                while (ss >> author) {
                    authors.push_back(trim(author));  
                }

                for(const string& author : authors) 
                {             
                    currentEntry.coAuthors = authors; 
                    authorMap[author].push_back(currentEntry);
                }
            }

            if (line.find("title") != string::npos) {
                size_t pos = line.find("title");
                size_t start = line.find("{", pos);
                size_t end = line.find("}", start);
                currentEntry.title = line.substr(start + 1, end - start - 1);
            }

            if (line.find("year") != string::npos) {
                size_t pos = line.find("year");
                size_t start = line.find("{", pos);
                size_t end = line.find("}", start);
                currentEntry.year = stoi(line.substr(start + 1, end - start - 1));
            }

            if (line.find("venue") != string::npos) {
                size_t pos = line.find("venue");
                size_t start = line.find("{", pos);
                size_t end = line.find("}", start);
                currentEntry.venue = line.substr(start + 1, end - start - 1);
            }

            if (line.find("doi") != string::npos) {
                size_t pos = line.find("doi");
                size_t start = line.find("{", pos);
                size_t end = line.find("}", start);
                currentEntry.doi = line.substr(start + 1, end - start - 1);
            }
        }
        file.close();
    }
}

void displayPublicationsByAuthor(const map<string, vector<BibEntry>>& authorMap, const string& authorName) 
{
    bool found = false;

    string normalizedAuthorName = authorName;
    transform(normalizedAuthorName.begin(), normalizedAuthorName.end(), normalizedAuthorName.begin(), ::tolower);

    for (const auto& entry : authorMap) 
    {
        string storedAuthor = entry.first;
        string normalizedStoredAuthor = storedAuthor;
        transform(normalizedStoredAuthor.begin(), normalizedStoredAuthor.end(), normalizedStoredAuthor.begin(), ::tolower);

        if (normalizedStoredAuthor == normalizedAuthorName) {
            found = true;
           
            for (const auto& pub : entry.second) {
                cout << "Title: " << pub.title << endl;
                cout << "Venue: " << pub.venue << endl;
                cout << "Year: " << pub.year << endl;
                cout << "DOI: " << pub.doi << endl;
                cout << "Authors: ";
                for (const auto& coAuthor : pub.coAuthors) {
                    cout << coAuthor << ", ";
                }
                cout << endl << endl;
            }
        }
    }

    if (!found) {
        cout << "No publications found for the author: " << authorName << endl;
    }
}

void calculateAverageCoAuthors(const map<string, vector<BibEntry>>& authorMap, const string& authorName) {
    bool found = false;
    int totalCoAuthors = 0;
    int paperCount = 0;

    string normalizedAuthorName = authorName;
    transform(normalizedAuthorName.begin(), normalizedAuthorName.end(), normalizedAuthorName.begin(), ::tolower);

    for (const auto& entry : authorMap) {
        string storedAuthor = entry.first;
        string normalizedStoredAuthor = storedAuthor;
        transform(normalizedStoredAuthor.begin(), normalizedStoredAuthor.end(), normalizedStoredAuthor.begin(), ::tolower);

        if (normalizedStoredAuthor == normalizedAuthorName) {
            found = true;
            for (const auto& pub : entry.second) {
                totalCoAuthors += pub.coAuthors.size() - 1;  
                paperCount++;
            }
        }
    }

    if (found) {
        double averageCoAuthors = (paperCount > 0) ? static_cast<double>(totalCoAuthors) / paperCount : 0.0;
        cout << "Average number of co-authors per paper for " << authorName << ": " << averageCoAuthors << endl;
    } else {
        cout << "No publications found for the author: " << authorName << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please provide at least one author name as a command-line argument." << endl;
        return 1;
    }

    map<string, vector<BibEntry>> authorMap;

    string bibFile = "C:\\Users\\shreyas\\Documents\\MTech IIIT Delhi\\Semester 1\\OOPD\\Assignment 4\\Question 2\\publist.bib"; // Name of your BibTeX file
    processBibFile(authorMap, bibFile);

    for (int i = 1; i < argc; ++i) {
        string authorName = argv[i];
        cout << "Displaying publications for author: " << authorName << endl;
        displayPublicationsByAuthor(authorMap, authorName);
        calculateAverageCoAuthors(authorMap, authorName);
    }

    return 0;
}
