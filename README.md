# scan_finger-vfs0097
Collection of tools that allows to use the fingerprint reader in e.g. the
ThinkPad X1 Carbon Gen5 (138a:0097) from linux without the need for a windows
VM. Also comes with a patched xtrlock-pam version that makes use of the
fingerprint authentification.

# Used Projects
* [uunicorn/python-validity](https://github.com/uunicorn/python-validity)
* [aanatoly/xtrlock-pam](https://github.com/aanatoly/xtrlock-pam)
* [usbreset](https://marc.info/?l=linux-usb&m=121459435621262&q=p3)

# Installation
## Arch Linux
Run `./gen_pkg.sh` in the repository folder (which itself cleans the directories
and then runs `makepkg`) and install with `pacman -U`.

# Tools
## scan_finger_enroll
Standalone script used for enrolling and validating fingerprints. Example:

```bash
scan_finger_enroll -i           # validates fingerprint

scan_finger_enroll -e -f 5      # enrolls new fingerprint in slot 5 (possible
                                # slots are 5,6,7,8,9)
```

## scan_finger_reset
Reset the fingerprint sensor and reupload firmware. Must be root to execute.

## scan_finger_reconnect
Reconnect the fingerprint reader (necessary if some other operations fail)

# C-Library (/usr/lib/libscan_finger.so, /usr/include/scan_finger.h)
## Functions

```C
int scan_finger_identify(void)
// returns 0 on match with database

int scan_finger_enroll(int finger)
// enroll new fingerprint. The argument can range from 1 to 5, corresponding
// to the slots 5 to 9 in scan_finger_enroll

int scan_finger_reset_and_pair_sensor(void)
// reset the fingerprint sensor, reupload firmware and repair

int scan_finger_reconnect(void)
// reset the USB connection to the fingerprint reader
```

# xtrlock-pam
Very similar to operation of regular xtrlock, but linked against
`libscan_finger.so` and with support of fingerprint authentification (before
password authentification) in regular mode. Can be switched to use password (or
other) authentification only with the `-f` flag.
