#!/bin/bash

sudo cp src/xtrlock-pam /usr/bin/
sudo cp src/40-libfprint-vfs0090-custom.rules /lib/udev/rules.d/
sudo cp src/xtrlock-pam-auth /etc/pam.d/

echo "
You might want the following in the file ´/etc/systemd/system/suspend@.service´:

´´´
[Unit]
Description=User suspend actions
Before=suspend.target

[Service]
User=lennart
Type=simple
Environment=DISPLAY=:0
ExecStart=+/usr/bin/xtrlock-pam -s

[Install]
WantedBy=suspend.target
´´´
"
