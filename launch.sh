#!/bin/sh
xterm -e " source /opt/ros/kinetic/setup.bash; roscore" &
sleep 5
xterm -e " 
xterm -e " rosrun rviz rviz"
