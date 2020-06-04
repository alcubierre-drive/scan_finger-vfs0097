#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <scan_finger.h>

#ifndef _IDPYPATH_
#define _IDPYPATH_ "/usr/share/identify_finger/"
#endif

#ifndef _PYTHON_
#define _PYTHON_ "/usr/bin/python3"
#endif

#ifndef _BASH_
#define _BASH_ "/bin/bash"
#endif

static int run_as_child( char* prog, char** argv ) {
    pid_t parent = getpid();
    pid_t pid = fork();

    if (pid == -1)
    {
        return -2;
    }
    else if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
        return status;
    }
    else
    {
        // we are the child
        execv(prog, argv);
        _exit(EXIT_FAILURE);   // exec never returns
    }
}

int scan_finger_reconnect() {
    static char* argv_reconnect[]={_BASH_, "/usr/bin/scan_finger_reconnect", NULL};
    return run_as_child(_BASH_,argv_reconnect);
}

int scan_finger_reset_and_pair_sensor() {
    static char *argv_reset[]={_PYTHON_, _IDPYPATH_ "factory-reset.py", NULL};
    int status_reset = run_as_child(_PYTHON_,argv_reset);
    fprintf(stderr,"Sleeping…\n");
    sleep(2);
    static char *argv_pair[]={_PYTHON_, _IDPYPATH_ "pair.py", NULL};
    int status_pair = run_as_child(_PYTHON_,argv_pair);
    return status_reset + status_pair;
}

int scan_finger_identify() {
    static char *argv_identify[]={_PYTHON_, _IDPYPATH_ "identify.py",
        "-i", NULL};
    int status_identify = run_as_child(_PYTHON_, argv_identify);
    return status_identify;
}

int scan_finger_enroll(int finger) {
    static char *argv_enroll[]={_PYTHON_, _IDPYPATH_ "identify.py",
        "-f", "FINGER", "-e", NULL};
    if (finger >= 1 && finger <= 5) {
        sprintf(argv_enroll[3],"%i",finger+4);
    } else {
        fprintf(stderr,"finger needs to be (1..5) using 1.");
        sprintf(argv_enroll[3],"%i",1+4);
    }
    int status_enroll = run_as_child(_PYTHON_,argv_enroll);
    return status_enroll;
}

