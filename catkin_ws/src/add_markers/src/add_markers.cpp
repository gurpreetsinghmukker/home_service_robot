/*
 * Copyright (c) 2010, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>

#include "pick_drop_publisher/pick_drop.h"
#include <cmath>

visualization_msgs::Marker marker;
visualization_msgs::Marker marker_drop;
float rover_x;
float rover_y;

void check_odom_callback(const nav_msgs::Odometry &msg){

  float x_diff = std::abs(msg.pose.pose.position.x - marker.pose.position.x);
  float y_diff = std::abs(msg.pose.pose.position.y - marker.pose.position.y);
  float z_diff = std::abs(msg.pose.pose.position.z - marker.pose.position.z);
  float rover_x = msg.pose.pose.position.x;
  float rover_y = msg.pose.pose.position.y;

 // ROS_INFO("rover_x: %0.3f, rover_y: %0.3f", msg.pose.pose.position.x, msg.pose.pose.position.y);
  //ROS_INFO("rover_x: %0.3f, rover_y: %0.3f", rover_x, rover_y);
  // ROS_INFO("Difference: [%0.3f]", std::abs(msg.pose.pose.position.x-marker.pose.position.x));

  
if(marker.action == visualization_msgs::Marker::ADD){
  ROS_INFO("x_diff: %0.3f, y_diff: %0.3f, z_diff: %0.3f", x_diff, y_diff, z_diff);
  if (x_diff < 0.2 && y_diff < 0.2 && z_diff < 0.2){
    marker.action = visualization_msgs::Marker::DELETE;
    marker_drop.action = visualization_msgs::Marker::ADD;
  }
}

if(marker_drop.action == visualization_msgs::Marker::ADD){
      //ROS_INFO("Inside IF rover_x: %0.3f, rover_y: %0.3f", rover_x, rover_y);
      //ROS_INFO("Inside IF rover_x: %0.3f, rover_y: %0.3f", marker_drop.pose.position.x, marker_drop.pose.position.y);
      float x_diff = std::abs(rover_x - marker_drop.pose.position.x);
      float y_diff = std::abs(rover_y - marker_drop.pose.position.y);
      //ROS_INFO("DropOff Location = x_diff: %0.3f, y_diff: %0.3f", x_diff, y_diff);
      if (x_diff < 0.2 && y_diff < 0.2){
          marker_drop.action = visualization_msgs::Marker::DELETE;
      }
    }
}

void pick_drop_loc_callback(const pick_drop_publisher::pick_drop& msg)
{

  // ROS_WARN("I heard: [%f], [%f], [%f]", msg.pickup_loc.x, msg.pickup_loc.y, msg.pickup_loc.theta);
    marker.pose.position.x = msg.pickup_loc.x;
    marker.pose.position.y = msg.pickup_loc.y;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = msg.pickup_loc.theta;

    marker_drop.pose.position.x = msg.dropoff_loc.x;
    marker_drop.pose.position.y = msg.dropoff_loc.y;
    marker_drop.pose.position.z = 0;
    marker_drop.pose.orientation.x = 0.0;
    marker_drop.pose.orientation.y = 0.0;
    marker_drop.pose.orientation.z = 0.0;
    marker_drop.pose.orientation.w = msg.dropoff_loc.theta;


    marker.action = visualization_msgs::Marker::ADD;
    marker_drop.action = visualization_msgs::Marker::DELETE;
    }
  
void update_goal_location( const geometry_msgs::PoseStamped& msg)
{
  marker.pose.position.x = msg.pose.position.x;
  marker.pose.position.y = msg.pose.position.y;
  marker.pose.position.z = msg.pose.position.z;
  marker.pose.orientation.x = msg.pose.orientation.x;
  marker.pose.orientation.y = msg.pose.orientation.y;
  marker.pose.orientation.z = msg.pose.orientation.z;
  marker.pose.orientation.w = msg.pose.orientation.w;
}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  
  ros::NodeHandle pickup_loc_subs;
  ros::NodeHandle get_odom;
  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Rate r(1);
  ros::Subscriber pickup_loc = pickup_loc_subs.subscribe("/pick_drop_loc", 1000, &pick_drop_loc_callback);
  ros::Subscriber odom = get_odom.subscribe("/odom", 1000, &check_odom_callback);


  if(pickup_loc){
    ROS_INFO("Subscribed to Position topic");
  }
  else{
    ROS_INFO("Failed to subscribe to Position topic");
  }
  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::SPHERE;

  marker.action = visualization_msgs::Marker::DELETE;
  marker_drop.action = visualization_msgs::Marker::DELETE;
  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  marker.header.frame_id = "/map";
  marker.header.stamp = ros::Time::now();
  marker_drop.header.frame_id = "/map";
  marker_drop.header.stamp = ros::Time::now();

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  marker.ns = "basic_shapes";
  marker.id = 0;
  
  marker_drop.ns = "basic_shapes";
  marker_drop.id = 1;

  // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  marker.type = shape;
  marker_drop.type = shape;


  // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)

  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = 0.3;
  marker.scale.y = 0.3;
  marker.scale.z = 0.3;
  
  marker_drop.scale.x = 0.3;
  marker_drop.scale.y = 0.3;
  marker_drop.scale.z = 0.3;

  // Set the color -- be sure to set alpha to something non-zero!
  marker.color.r = 0.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0;
  
  marker_drop.color.r = 0.0f;
  marker_drop.color.g = 1.0f;
  marker_drop.color.b = 0.0f;
  marker_drop.color.a = 1.0;

  marker.lifetime = ros::Duration();
  marker_drop.lifetime = ros::Duration();

  // Publish the marker
  while (marker_pub.getNumSubscribers() < 1)
  {
    if (!ros::ok())
    {
      return 0;
    }
    ROS_WARN("Please create a subscriber to the marker");
    sleep(1);
  }

  while(ros::ok()){
    marker_pub.publish(marker);
    marker_pub.publish(marker_drop);
    ros::spinOnce();
    r.sleep();
  }
  ROS_INFO("Exiting");
  return 0;
  }  

