#ifndef _SCAN_FINGER_H
#define _SCAN_FINGER_H

int scan_finger_reconnect();
int scan_finger_reset_and_pair_sensor();
int scan_finger_identify();
int scan_finger_enroll(int finger);

#endif
