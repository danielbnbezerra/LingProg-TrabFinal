#include "file.h"


string limparString(string palavras){
  vector <char> delim = { '\n' ,'\r','\t'};
  size_t ocorrencia;

  for (int j = 0; j < delim.size(); j++){
    ocorrencia = palavras.find(delim[j]);
    if (ocorrencia!=string::npos){
      palavras.erase(ocorrencia);
    }
  }
  return palavras;
}

Email loadEmail(const string &fileName) {
    ifstream file;
    Email email;
    string buffer;
    int counter = 0;
    
    email.fileName = fileName;
    file.open(fileName);
    if (!file){
        throw ExceptionEmailFileNotFound();
    }

    if (file.is_open()) {
        while(getline(file, buffer)){
            if (buffer != ""){
                if (counter == 0){
                    buffer = buffer.substr(separators.at(0).length());
                    email.emailRecipient = buffer;
                    counter++;
                }else if (counter == 1){
                    buffer = buffer.substr(separators.at(1).length());
                    email.emailAuthor = buffer;
                    counter++;
                }
                else if (counter == 2){
                    buffer = buffer.substr(separators.at(2).length());
                    email.emailSubject = buffer;
                    counter++;
                }
                else {
                    if (buffer != separators.at(3)){
                    	buffer = limparString(buffer) + ' ';
                    	//email.emailBodyText.push_back(limparString(buffer));
                       email.emailBodyText.push_back(buffer);
                    }
                }
            }
        }
        email.emailBodyText.erase(email.emailBodyText.begin());
        //email.emailBodyText.at(0) = email.emailBodyText.at(0).substr(separators.at(3).length());
    }
    else{
        throw ExceptionEmailFileIsCorrupted();
    }

    file.close();
    
    return email;
}

void loadEmailFileNames(vector<string> &fileNamesEntry){
    ifstream file;
    string buffer;
    
    fileNamesEntry.clear();
    file.open("fileNames.txt");
    if (!file){
        throw ExceptionFilenamesFileNotFound();
    }

    if (file.is_open()) {
        while (getline (file, buffer)){
            fileNamesEntry.push_back(buffer);
        }
    }
    else{
        throw ExceptionFilenamesFileIsCorrupted();
    }

    file.close();
}

EmailFolder loadAllEmails(){
    EmailFolder folder;
    Email newEmail;

    loadEmailFileNames(fileNames);
    for (auto fileName : fileNames){
        newEmail = loadEmail(fileName);
        folder.operator+=(newEmail);
    }
    return folder;
}

void unloadEmail (const Email &email){
    ofstream file;

    file.open(email.fileName);
    if (file.is_open()){
        file << email << endl;
    }
    else {
       throw ExceptionEmailFileIsCorrupted();
    }
    file.close();
}

void unloadAllEmails(const EmailFolder &folder){
    vector<Email> emailFolder;
    ofstream file;
    
    fileNames.clear();
    emailFolder = folder.getEmailFolder();
    for (auto email: emailFolder){
        unloadEmail(email);
        fileNames.push_back(email.fileName);
    }

    file.open("fileNames.txt");
    for (auto fileName: fileNames){
        file << fileName << endl;
    }
    file.close();

}
