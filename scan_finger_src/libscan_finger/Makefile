CC := gcc
LD := gcc

CFLAGS += -fPIC -D_IDPYPATH_="\"/usr/share/identify_finger/\"" \
	  -D_PYTHON_="\"/usr/bin/python3\"" \
	  -D_BASH_="\"/bin/bash\"" \
	  -I.
LDFLAGS += -shared

.PHONY: all

SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o,$(SRCS))

all: libscan_finger.so

libscan_finger.so: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.c %.h Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

%.o: %.c Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	-$(RM) libscan_finger.so $(OBJS)
