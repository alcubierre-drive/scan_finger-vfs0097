#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <scan_finger.h>

int main() {
    char* user = getenv("USER");
    if (user == NULL) {
        fprintf(stderr,"could not determine user.\n");
        return 1;
    }
    if (strcmp(user,"root")) {
        fprintf(stderr,"not root.\n");
        return 2;
    }
    char yesno = 'N';
    printf("Please confirm resetting the fingerprint sensor [y|N].\n");
    scanf("%c",&yesno);
    if (yesno == 'y') {
        printf("resetting…\n");
        int result = scan_finger_reset_and_pair_sensor();
        if (result) { printf("failed.\n"); exit(result); }
        else printf("done.\n");
    } else {
        printf("exiting.\n");
    }
    return 0;
}
