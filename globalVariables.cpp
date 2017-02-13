#include "globalVariables.h"

QString globalVar::clara_home = getenv("CLARA_HOME");
QRegularExpression globalVar::rx("(\\:)");
QString globalVar::errorMessage = "";
