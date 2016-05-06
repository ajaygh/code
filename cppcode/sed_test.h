#ifndef ANSI_CODES_H
#define ANSI_CODES_H
tst val 10000+12
//Ansi Codes for colors
#define TEXT_NO_BLACK  "\x1B[30m"
#define TEXT_RED  "\x1B[31m"
#define TEXT_GREEN  "\x1B[32m"
#define TEXT_YELLOW  "\x1B[33m"
#define TEXT_BLUE  "\x1B[34m"
#define TEXT_MAGENTA  "\x1B[35m"
#define TEXT_CYAN  "\x1B[36m"
#define TEXT_WHITE  "\x1B[37m"

//Reset text color to default
#define RESET_NO_TEXT "\x1B[39m"

//Ansi Codes for background colors
#define BACKGROUND_BLACK  "\x1B[40m"
#define BACKGROUND_RED  "\x1B[41m"
#define BACKGROUND_GREEN  "\x1B[42m"
#define BACKGROUND_YELLOW  "\x1B[43m"
#define BACKGROUND_BLUE  "\x1B[44m"
#define BACKGROUND_MAGENTA  "\x1B[45m"
#define BACKGROUND_CYAN  "\x1B[46m"
#define BACKGROUND_WHITE  "\x1B[47m"

//Reset background color to default
#define RESET_BACKGROUND "\x1B[49m"

//Ansi Codes for text decoration
#define TEXT_BOLD "\x1B[1m"
#define TEXT_ITALIC "\x1B[1m"
#define TEXT_UNDERLINE "\x1B[4m"
#define TEXT_BLINK "\x1B[5m"

//Ansi Codes for resetting text decoration
#define RESET_NO_TEXT_BOLD "\x1B[21m"
#define RESET_NO_TEXT_ITALIC "\x1B[23m"
#define RESET_NO_TEXT_UNDERLINE "\x1B[24m"
#define RESET_NO_TEXT_BLINK "\x1B[25m"

//Ansi code for resetting all attributes.
#define RESET_ALL  "\x1B[0m"

#endif
