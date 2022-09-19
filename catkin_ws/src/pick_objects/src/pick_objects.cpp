#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "std_msgs/String.h"

#include <sstream>

#include "pick_drop_publisher/pick_drop.h"

// %EndTag(INCLUDES)%

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
move_base_msgs::MoveBaseGoal pickup_location;
move_base_msgs::MoveBaseGoal dropoff_location;
int new_locations = 0;

void pick_drop_loc_callback(const pick_drop_publisher::pick_drop& msg)
{

  ROS_WARN("I heard: [%f], [%f], [%f]", msg.pickup_loc.x, msg.pickup_loc.y, msg.pickup_loc.theta);
    pickup_location.target_pose.pose.position.x = msg.pickup_loc.x;
    pickup_location.target_pose.pose.position.y = msg.pickup_loc.y;
    pickup_location.target_pose.pose.orientation.w = msg.pickup_loc.theta;

    dropoff_location.target_pose.pose.position.x = msg.dropoff_loc.x;
    dropoff_location.target_pose.pose.position.y = msg.dropoff_loc.y;
    dropoff_location.target_pose.pose.orientation.w = msg.dropoff_loc.theta;
    new_locations = 1;

}



int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  ros::NodeHandle pickup_loc_subs;
  ros::Subscriber pickup_loc = pickup_loc_subs.subscribe("/pick_drop_loc", 1000, &pick_drop_loc_callback);

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Create a new node handle for goal position publisher
  //ros::NodeHandle n;

  //ros::Publisher robot_status = n.advertise<std_msgs::String>("chatter", 1000);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }


  // set up the frame parameters
  pickup_location.target_pose.header.frame_id = "map";
  pickup_location.target_pose.header.stamp = ros::Time::now();

  dropoff_location.target_pose.header.frame_id = "map";
  dropoff_location.target_pose.header.stamp = ros::Time::now();
ros::Rate r(1);
while(ros::ok()){

if(new_locations == 1){
   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending the pickup goal");
  ac.sendGoal(pickup_location);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    	ROS_INFO("Hooray, Robot reached the pickup station");
	    ros::Duration(5).sleep();
      // Send the goal position and orientation for the robot to reach
      ROS_INFO("Sending the return location");
      ac.sendGoal(dropoff_location);
      ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
		ROS_INFO("Hooray, The robot reached the dropoff location");
	else
	 	ROS_INFO("The base failed to move forward 1 meter for some reason");
}
  else
    ROS_INFO("The base failed to move forward 1 meter for some reason");

}
    new_locations = 0;
    ros::spinOnce();
    r.sleep();
}

  // Define a position and orientation for the robot to reach
  // goal.target_pose.pose.position.x = 2.14;
  // goal.target_pose.pose.position.y = 2.28;
  // goal.target_pose.pose.orientation.w = -0.1;
  return 0;
}
