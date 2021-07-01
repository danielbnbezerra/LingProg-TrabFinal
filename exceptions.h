#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

using namespace std;

class ExceptionEmailFileNotFound: public runtime_error {
    public:
        ExceptionEmailFileNotFound():
        runtime_error("\nERROR #1: File in which contains the e-mail was not found. Aborting program...\n") {};
};

class ExceptionEmailFileIsCorrupted: public runtime_error {
    public:
        ExceptionEmailFileIsCorrupted():
        runtime_error("\nERROR #2: File in which contains the e-mail is corrupted. Aborting program...\n") {};
};

class ExceptionFilenamesFileNotFound: public runtime_error {
    public:
        ExceptionFilenamesFileNotFound():
        runtime_error("\nERROR #3: File in which contains the filenames was not found. Aborting program...\n") {};
};

class ExceptionFilenamesFileIsCorrupted: public runtime_error {
    public:
        ExceptionFilenamesFileIsCorrupted():
        runtime_error("\nERROR #4: File in which contains the filenames is corrupted. Aborting program...\n") {};
};

class ExceptionEmailFileNameSearchIsEmpty: public runtime_error {
    public:
        ExceptionEmailFileNameSearchIsEmpty():
        runtime_error("\nERROR #5: FileName is an empty string. Aborting Program...\n") {};
};

class ExceptionEmailDoesNotExist: public runtime_error {
    public:
        ExceptionEmailDoesNotExist():
        runtime_error("\nE-mail does not Exist. Exhibiting menu options again.\n") {};
};

class ExceptionInvalidOption: public runtime_error {
    public:
        ExceptionInvalidOption():
        runtime_error("\nInvalid menu option. Exhibiting menu options again.\n") {};
};

#endif