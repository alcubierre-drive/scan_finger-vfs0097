all: scan_finger_reset usbreset
scan_finger_reset: scan_finger_reset.c
	$(CC) $(CFLAGS) $(LDFLAGS) scan_finger_reset.c -o scan_finger_reset -L. -lscan_finger -I.
usbreset: usbreset.c
	$(CC) $(CFLAGS) $(LDFLAGS) usbreset.c -o usbreset
