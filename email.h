#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string EOBT = "END";

struct Email
{
    friend class EmailFolder;

    friend ostream &operator<<(ostream &, const Email &);
    friend istream &operator>>(istream &, Email &);
    bool operator> (const Email &);
    bool operator< (const Email &);
    bool operator== (const Email &);


    string fileName;
    string emailAuthor;
    string emailRecipient;
    string emailSubject;
    vector<string> emailBodyText;
};

#endif