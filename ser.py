#!/usr/bin/python

import serial
import time

ser = serial.Serial()
ser.baudrate = 115200
ser.port = '/dev/ttyACM0'
ser.open()

time.sleep(2)

while True:
    ser.write(1)

    data = ser.readline()[:-1]

    print(data)

