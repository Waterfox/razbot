#!/bin/bash
#Start stuff up on Pawly

export LD_LIBRARY_PATH=/home/pi/mjpg-streamer/
/home/pi/mjpg-streamer/mjpg_streamer -o "output_http.so -w /home/pi/mjpg-streamer/www" -i "input_raspicam.so -x 640 -y 360 -fps 24 -sh 100 -quality 10"
