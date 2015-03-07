#!/usr/bin/env python
import rospy
#import roslib; roslib.load_manifest('pawly_joy')
import math
from sensor_msgs.msg import Joy
from std_msgs.msg import UInt16, ColorRGBA

#blue button is [0]
#green button is [1]
#red button is [2]
#yellow button is [3]

def callback(joy):
	motor = ColorRGBA()
	color = ColorRGBA()

	if joy.buttons[0]>0:
		color.r =  0
		color.g =  0
		color.b =  150
	if joy.buttons[1]>0:
		color.r =  0
		color.g =  150
		color.b =  0
	if joy.buttons[2]>0:
		color.r =  150
		color.g =  0
		color.b =  0
	if joy.buttons[3]>0:
		color.r =  150
		color.g =  80
		color.b =  0
	y=joy.axes[3]*100.0
	x=joy.axes[2]*-100.0

	##Ouputs throttle from -100 to 100
	f = math.fabs(y/100.0)
	left = y*f+(1-f)*x
	right = y*f -(1-f)*x

	#Change to 0..127..255
	motor.b = left*254.0/200.0 +127.0
	motor.a = left*254.0/200.0 +127.0
	motor.r = right*254.0/200.0 +127.0
	motor.g = right*254.0/200.0 +127.0
	pub_motor.publish(motor)
	pub_color.publish(color)


def joy2pi():
	COMMAND_HZ = 5
	global pub_motor, pub_color
	pub_motor =rospy.Publisher('piBot_motors',ColorRGBA, queue_size=1)
	pub_color = rospy.Publisher('piBot_color',ColorRGBA, queue_size=1)
	rospy.Subscriber("joy",Joy,callback)
	
	rospy.init_node('joy2pi')
	rate = rospy.Rate(COMMAND_HZ)
	rospy.spin()
	rate.sleep()
	
if __name__ =='__main__':
	try:
		joy2pi()
	except rospy.ROSInterruptException:
		pass

