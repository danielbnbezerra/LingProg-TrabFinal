#ifndef EMAILFOLDER_H
#define EMAILFOLDER_H

#include <iostream>
#include <vector>
#include <string>
#include "email.h"
#include "exceptions.h"

using namespace std;

class EmailFolder {
    friend ostream &operator<<(ostream &, const EmailFolder &);

    public:
        
        EmailFolder &operator+=(Email &);
        EmailFolder &operator-=(Email &);
        Email* operator()(string &);
        vector<Email> getEmailFolder();
        const vector<Email> getEmailFolder() const;
    private:
        vector<Email> emailFolder;
};

#endif