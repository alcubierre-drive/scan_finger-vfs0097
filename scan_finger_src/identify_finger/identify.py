#!/usr/bin/env python3
#coding: utf8

import argparse
getopts = argparse.ArgumentParser()
getopts.add_argument('-e','--enroll',help="enroll fingerprint",action="store_true")
getopts.add_argument('-f','--finger',help="finger number to enroll (5..9)",type=int,default=5)
getopts.add_argument('-i','--identify',help="identify fingerprint",action="store_true")

opts = getopts.parse_args()

from prototype import *
import sys

def __main__():
    if opts.enroll:
        open97()
        enroll(sid_from_string('S-1-5-21-394619333-3876782012-1672975908-3333'),
                0xf0 + opts.finger)
        return 0
    elif opts.identify:
        open97()
        try:
            identify()
            return 0
        except:
            return 2
    else:
        print("no action given")
        return 1

sys.exit(__main__())
