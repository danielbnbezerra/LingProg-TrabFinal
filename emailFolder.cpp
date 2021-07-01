#include "emailFolder.h"

using namespace std;

vector<Email> EmailFolder::getEmailFolder() {
    return emailFolder;
}

const vector<Email> EmailFolder::getEmailFolder() const {
    return emailFolder;
}

ostream &operator<<(ostream &out, const EmailFolder &folder){
    out << "These are the current e-mails present in the folder:\n" << endl;
    for (auto email: folder.getEmailFolder()){
        out << email << endl;
    }
    return out;
}

Email* EmailFolder::operator()(string &emailFileName){
    Email * emailFound = new Email;
    if (emailFileName.length() != 0){
        for (auto email: emailFolder){
            if (email.fileName == emailFileName){
                *emailFound = email;
                return emailFound;
            }
        }
    }
    else{
        throw ExceptionEmailFileNameSearchIsEmpty();
    }
    return NULL;
}

EmailFolder &EmailFolder::operator+=(Email &email){
    if (emailFolder.size() == 0){
        emailFolder.push_back(email);
    }
    else{
        for (unsigned int index = 0; index < emailFolder.size(); index++){
            if (emailFolder.at(index).operator>(email)){
                    emailFolder.insert(emailFolder.begin() + index, 1, email);
                    return *this;
                }
        }
        emailFolder.push_back(email);
    }

    return *this;
}

EmailFolder &EmailFolder::operator-=(Email &email){
    if (this->operator()(email.fileName) == NULL){
        throw ExceptionEmailFileNotFound();
        return *this;
    }

    for (unsigned int index = 0; index < emailFolder.size(); index++){
        if (emailFolder.at(index).operator==(email)){
            emailFolder.erase(emailFolder.begin() + index);
        }
    }
    return *this;    
}