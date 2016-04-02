#!/usr/bin/python
import os
import sys
import subprocess

def test_pentrs(f_arg, *argv):
    for arg in argv:
        print ("[+] Ping for ", arg);
        subprocess.call(["ping", arg]);
		
test_pentrs("google.pt")