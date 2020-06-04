#!/bin/bash

rm -rf src/ pkg/ scan_finger-*-any.pkg.tar
makepkg --printsrcinfo > .SRCINFO
tar c scan_finger_src | gzip > scan_finger_src.tgz
makepkg
