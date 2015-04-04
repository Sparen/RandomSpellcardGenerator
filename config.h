/**Configuration Flags**/
/*
 * Insert Information here on what the flags are
 * F_VERBOSE: show guide messages
 * F_HELP: print help and exit
 * F_INVALID_AS_DEFAULT: do not exit the program when given an invalid name
 * F_LIST_NAMES: list all names and exit
 */

typedef int Config;

enum {F_VERBOSE, F_HELP, F_INVALID_AS_DEFAULT, F_LIST_NAMES} ConfigFlags;

#define SET(conf,flag) conf |= (1 << flag)
#define RESET(conf,flag) conf &= ~(1 << flag)
#define HAS(conf,flag) ((conf) & (1 << (flag)))
