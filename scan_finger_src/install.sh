#!/bin/sh
custom_prefix=${PREFIX:=/}
install -d $custom_prefix/usr/share
cp -r identify_finger/ $custom_prefix/usr/share/
cd libscan_finger
make
cd ..
install -D -m 755 libscan_finger/libscan_finger.so $custom_prefix/usr/lib/libscan_finger.so
install -D -m 644 libscan_finger/scan_finger.h $custom_prefix/usr/include/scan_finger.h
install -D -m 644 libscan_finger/libscan_finger.3.gz $custom_prefix/usr/share/man/man3/libscan_finger.3.gz
install -D -m 755 scan_finger_enroll $custom_prefix/usr/bin/scan_finger_enroll
ln -sf libscan_finger/scan_finger.h libscan_finger/libscan_finger.so .
make
install -D -m 755 scan_finger_reset $custom_prefix/usr/bin/scan_finger_reset
install -D -m 755 scan_finger_reconnect $custom_prefix/usr/bin/scan_finger_reconnect
install -D -m 755 usbreset $custom_prefix/usr/share/identify_finger/usbreset
install -D -m 644 scan_finger.1.gz $custom_prefix/usr/share/man/man1/scan_finger.1.gz
cd xtrlock-pam
cd src
ln -sf ../../libscan_finger/scan_finger.h ../../libscan_finger/libscan_finger.so .
cd ..
./configure
make
cd ..
install -D -m 755 xtrlock-pam/src/xtrlock-pam $custom_prefix/usr/bin/xtrlock-pam
install -D -m 644 xtrlock-pam/src/40-libfprint-vfs0090-custom.rules $custom_prefix/usr/lib/udev/rules.d/40-libfprint-vfs0090-custom.rules
