#!/usr/bin/python
import sys

import serial
import time
import codecs

ser = serial.Serial()
ser.baudrate = 9600
ser.port = '/dev/ttyUSB0'
ser.open()

time.sleep(2)

inside = False

frames = []

data = []

while True:
    data_byte = ser.read()

    if data_byte == b'R':
        data = []
        inside = True

    if inside:
        encoded = (codecs.encode(data_byte, "hex"))
        data.append(encoded)
        sys.stdout.buffer.write(encoded)

    if data_byte == b'\xcc':
        inside = False
        print()
        frames.append(data)

    if len(frames) > 10:
        break
