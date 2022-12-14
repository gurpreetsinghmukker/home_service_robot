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
xterm -hold -e " cd ../../; source devel/setup.bash; roslaunch my_robot add_markers.launch " &
sleep 5
xterm -hold -e " cd ../../; source devel/setup.bash; roslaunch my_robot pick_objects.launch " &
sleep 5
xterm -e " rosrun rviz rviz" &
sleep 5
xterm -hold -e " cd ../../; source devel/setup.bash;  rostopic pub -1 /pick_drop_loc pick_drop_publisher/pick_drop '{pickup_loc: {x: 1.5, y: -1.5, theta: -0.1}, dropoff_loc: {x: -2.7, y: 1.9, theta: -0.1}}' "
