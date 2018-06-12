#!/usr/bin/python
import sys

import serial
import time
import codecs
import subprocess
import datetime

ser = serial.Serial()
ser.baudrate = 9600
ser.port = '/dev/ttyACM0'
ser.open()

time.sleep(2)

inside = False

data = []

def writeFrame(frame):
    data = ''
    for i in frame:
        data += 'frame'

    path = datetime.datetime.now().strftime("%Y-%m-%d-%h:%m:%S") + '.json'

    f = open('frames/' + path, 'w')
    res = subprocess.call(['./api', data], stdout = f)
    f.close()

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
        print('ended')
        writeFrame(data)
