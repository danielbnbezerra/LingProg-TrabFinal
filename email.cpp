#include "email.h"

using namespace std;

ostream &operator<<(ostream &out , const Email &email){
    out << "To: " << email.emailRecipient << endl; 
    out << "From: " << email.emailAuthor << endl; 
    out << "Subject: " << email.emailSubject << endl;
    out << "BodyText:" << endl;
    for (auto textline : email.emailBodyText) {
        out << textline << endl;
    }
    out << endl;

    return out; 
}

istream &operator>>(istream &in, Email &email){
    string buffer;

    cout << "To: ";
    in >> email.emailRecipient;
    cout << "From: ";
    in >> email.emailAuthor;
    cout << "Subject: ";
    in.ignore();
    getline(in, email.emailSubject);
    cout << "BodyText: <Type in one line \"END\" to abort this field>" << endl;
    buffer.clear();
    while (buffer != EOBT){
        //in.ignore();     //precisa de teste para ver se funciona corretamente
        getline(in, buffer);
        if (buffer != EOBT){
            email.emailBodyText.push_back(buffer);
        }
    }
    cout << "FileName: ";
    getline(in, email.fileName);

    return in;
}
// Comparacoes feitas usando nome do arquivo. Melhor parametro seria outro (?)
bool Email::operator> (const Email &email){
    return (this->fileName > email.fileName);
}

bool Email::operator< (const Email &email){
    return (this->fileName < email.fileName);
}

bool Email::operator== (const Email &email){
    return this->fileName == email.fileName;
}
