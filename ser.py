#!/usr/bin/python

import serial
import time

ser = serial.Serial()
ser.baudrate = 115200
ser.port = '/dev/ttyACM0'
ser.open()

time.sleep(2)

ser.write(1)

data = ser.read(64)

import pdb;
pdb.set_trace()
print(data)

