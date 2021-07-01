#include "menu.h"
#include <numeric>

using namespace std;

void menuOpeningStatement() {
    cout << "\n-----------------------S-P-A-M----C-L-A-S-S-I-F-I-E-R----P-R-O-G-R-A-M----------------------\n" << endl;
    cout << "- Select (1) to list and exhibit all the e-mails." << endl;
    cout << "- Select (2) to exhibit the classification effiency degree of the algorithm." << endl;
    cout << "- Select (3) to classify an e-mail as spam/not spam utilizing an external algorithm."
         << " The User must then enter with an e-mail as a parameter." << endl;
    cout << "- Select (4) to include/remove an e-mail from the folder."
          << " The User must then enter with all the email's fields." << endl;
    cout << "- Select (5) to exhibit the help menu and a short explanation about the operation." << endl;
    cout << "- Select (0) to abort the program." << endl;
}

void mainMenu(EmailFolder &folder){
    int options;

    menuOpeningStatement();
    cin >> options;
    switch (options)
    {
        case 1:
            menuOptionOne(folder);
            mainMenu(folder);
            break;
        case 2:
            menuOptionTwo(folder);
            mainMenu(folder);
            break;
        case 3:
            menuOptionThree(folder);
            mainMenu(folder);
            break;
        case 4:
            menuOptionFour(folder);
            mainMenu(folder);
            break;
        case 5:
            menuOptionFive(folder);
            mainMenu(folder);
            break;
        case 0:
            cout << "Ending program..." << endl;
            unloadAllEmails(folder);
            Sleep(2000);
            cout << "Program ended."<< endl;
            break;
        default:
            throw ExceptionInvalidOption();
            mainMenu(folder);
    }
}

void menuOptionOne(EmailFolder &folder) {
    cout << folder;
}

void menuOptionTwo(EmailFolder &emailFolder) {
    //Py_SetPythonHome();
    Py_Initialize();
    FILE* pythonScriptFile = fopen("script1.py", "r");
    
    if(pythonScriptFile){
        PyRun_SimpleFile(pythonScriptFile, "script1.py");
        fclose(pythonScriptFile);
    }
    Py_Finalize();
}

void menuOptionThree(EmailFolder &folder) {
    string filenameSearch, newString;
    
    Email *emailFound;
    
    //Py_SetPythonHome();

    cout << "\nType the filename of the e-mail which you want to use the algorithm. E-mails available are:\n" << endl;
    for (auto email: folder.getEmailFolder()) {
       cout << email.fileName << endl;
    }
    cin.ignore();
    getline(cin, filenameSearch);
    emailFound = folder.operator()(filenameSearch);
    if (emailFound == NULL) {
        throw ExceptionEmailFileNotFound();
    }
    else {
	newString = accumulate(begin(emailFound->emailBodyText), end(emailFound->emailBodyText), newString);
	
	Py_Initialize();
        
        PyObject* pythonFilename = PyUnicode_FromString((char*)"script2");
        PyObject* pythonImportModule = PyImport_Import(pythonFilename);
        PyObject* pythonFunction = PyObject_GetAttrString(pythonImportModule, "emailClassifier");
        PyObject* pythonArgs = PyTuple_New(1);
        const char * cppToPythonArg = newString.c_str();
        PyObject* pythonEmailBodyText = PyUnicode_FromString(cppToPythonArg);
        PyTuple_SetItem(pythonArgs, 0, pythonEmailBodyText);
        PyObject* pythonFuncValue = PyObject_CallObject(pythonFunction, pythonArgs);
        	
	Py_Finalize();
    }
}

void menuOptionFour(EmailFolder &folder) {
    int optionFourOptions;
    Email newEmail;
    Email *emailDeleted = new Email;
    string emailToDelete;

    cout << "Select (1) to add a new e-mail to the folder." << endl;
    cout << "Select (2) to remove an e-mail from the folder." << endl;
    cin >> optionFourOptions;

    switch (optionFourOptions) {
        case 1:
            cin >> newEmail;
            folder.operator+=(newEmail);
            break;
        case 2:
            cout << "\nType the filename of the e-mail which you wish to delete. E-mails available are:\n";
            for (auto email: folder.getEmailFolder()) {
                cout << email.fileName << endl;
            }
            cin.ignore();
            getline (cin, emailToDelete);
            emailDeleted = folder.operator()(emailToDelete);
            if (emailDeleted == NULL){
                throw ExceptionEmailFileNotFound();
            }
            else{
                folder.operator-=(*emailDeleted);
            }
            break;
        default:
            throw ExceptionInvalidOption();
            menuOptionFour(folder);
    }
}

void menuOptionFive(EmailFolder &folder) {
    menuHelp();
}

void menuHelp(){

    cout << "\nWelcome to the Spam E-mail Classifier Program.\n" << endl;
    
    cout << "This program uses the SVM method to analyse" << endl; 
    cout << "the selected e-mail to predict if it is ok or if it is spam. The e-mail" << endl;
    cout << "put through test is chosen by the user, from a folder pre-loaded from" << endl;
    cout << "the files which contains each said e-mail. It also can test the classification"<< endl;
    cout << "effiency degree of a classifier, allowing the user to check its efficiency" << endl;
    cout << "before even using to evaluate the e-mails.\n" << endl;

    cout << "The folder also has funcionalities in order to interact with the" << endl;
    cout << "classifier, such as inserting and removing the e-mails used for the" << endl;
    cout << "classifier the predict, list and exhibition of each e-mail stored in" << endl;
    cout << "the folder and exhibition of this help.\n\n" << endl;

    cout << "Exhibiting again the menu options...\n\n" << endl;
}

