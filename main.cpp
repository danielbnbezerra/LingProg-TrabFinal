#define PY_SSIZE_T_CLEAN
#include "python3.8/Python.h"

#include <pylifecycle.h>
#include <pythonrun.h>
#include <unicodeobject.h>
#include <import.h>
#include <object.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "menu.h"
#include "exceptions.h"
#include "file.h"
#include "emailFolder.h"
#include "email.h"

#define OK  0

/* Final Evaluation
 * Spam E-mail Classifier.
 * Professor: Miguel Campista
 * Authors: Daniel Bernardo do Nascimento Bezerra
 *          Letícia Tavares dos Santos
 */

using namespace std;

int main(){   
    EmailFolder emailFolder;
    try{
        emailFolder = loadAllEmails();
        mainMenu(emailFolder);
    }
    
    catch (ExceptionEmailFileNotFound &error1){
        cout << error1.what() << endl;
    }

    catch (ExceptionEmailFileIsCorrupted &error2){
        cout << error2.what() << endl;
    }

    catch (ExceptionFilenamesFileNotFound &error3){
        cout << error3.what() << endl;
    }

    catch (ExceptionFilenamesFileIsCorrupted &error4){
        cout << error4.what() << endl;
    }

    catch (ExceptionEmailFileNameSearchIsEmpty &error5){
        cout << error5.what() << endl;
    }
    
    return OK;
}
