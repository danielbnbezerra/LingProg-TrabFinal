#ifndef MENU_H
#define MENU_H

#define PY_SSIZE_T_CLEAN
#include "python3.8/Python.h"
#include <pylifecycle.h>
#include <pythonrun.h>
#include <unicodeobject.h>
#include <import.h>
#include <object.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

#include <iostream>
#include <vector>
#include <string>
#include "file.h"
#include "emailFolder.h"
#include "email.h"
#include "exceptions.h"

void menuOpeningStatement();
void mainMenu(EmailFolder &);
void menuOptionOne(EmailFolder &);
void menuOptionTwo(EmailFolder &);
void menuOptionThree(EmailFolder &);
void menuOptionFour(EmailFolder &);
void menuOptionFive(EmailFolder &);
void menuHelp();

#endif
