#!/bin/sh
xterm -e " pwd; source /opt/ros/kinetic/setup.bash; roscore" &
sleep 5
xterm -e " cd ../../; source devel/setup.bash; roslaunch my_robot world.launch " &
#sleep 5
#xterm -e " cd ../../; source devel/setup.bash; roslaunch gmapping slam_gmapping_pr2.launch " &
#sleep 5
#xterm -e " cd ../../; source devel/setup.bash; roslaunch my_robot teleop.launch " &
sleep 5
xterm -hold -e " cd ../../; source devel/setup.bash; roslaunch my_robot amcl.launch " &
sleep 5
xterm -e " rosrun rviz rviz"

