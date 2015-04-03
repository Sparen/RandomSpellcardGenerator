

typedef int Config;

// will have more flags in the future?
enum {F_VERBOSE, F_EIRIN} ConfigFlags;

#define SET(conf,flag) conf |= (1 << flag)
#define RESET(conf,flag) conf &= ~(1 << flag)
#define HAS(conf,flag) conf & (1 << flag)