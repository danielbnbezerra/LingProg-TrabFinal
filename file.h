#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>
#include "exceptions.h"
#include "emailFolder.h"
#include "email.h"

const vector<string> separators {"To: ", "From: ", "Subject: ", "BodyText:"};

static vector<string> fileNames;

//limpa a pontuacao de uma palavra
string limparString(string);

void loadEmailFileNames(vector<string> &); 
Email loadEmail (const string &);
EmailFolder loadAllEmails();
void unloadEmail (const Email &);
void unloadAllEmails(const EmailFolder &);

#endif
