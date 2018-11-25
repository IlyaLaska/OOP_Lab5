//#define DEBUG

//RL - release log
//DL - debug log

#ifndef DEBUG

    #define RL
    #define DL if(0)

#else

    #define DL
    #define RL if(0)

#endif