;; Auto-generated. Do not edit!


(when (boundp 'pick_drop_publisher::pick_drop)
  (if (not (find-package "PICK_DROP_PUBLISHER"))
    (make-package "PICK_DROP_PUBLISHER"))
  (shadow 'pick_drop (find-package "PICK_DROP_PUBLISHER")))
(unless (find-package "PICK_DROP_PUBLISHER::PICK_DROP")
  (make-package "PICK_DROP_PUBLISHER::PICK_DROP"))

(in-package "ROS")
;;//! \htmlinclude pick_drop.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass pick_drop_publisher::pick_drop
  :super ros::object
  :slots (_pickup_loc _dropoff_loc ))

(defmethod pick_drop_publisher::pick_drop
  (:init
   (&key
    ((:pickup_loc __pickup_loc) (instance geometry_msgs::Pose2D :init))
    ((:dropoff_loc __dropoff_loc) (instance geometry_msgs::Pose2D :init))
    )
   (send-super :init)
   (setq _pickup_loc __pickup_loc)
   (setq _dropoff_loc __dropoff_loc)
   self)
  (:pickup_loc
   (&rest __pickup_loc)
   (if (keywordp (car __pickup_loc))
       (send* _pickup_loc __pickup_loc)
     (progn
       (if __pickup_loc (setq _pickup_loc (car __pickup_loc)))
       _pickup_loc)))
  (:dropoff_loc
   (&rest __dropoff_loc)
   (if (keywordp (car __dropoff_loc))
       (send* _dropoff_loc __dropoff_loc)
     (progn
       (if __dropoff_loc (setq _dropoff_loc (car __dropoff_loc)))
       _dropoff_loc)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Pose2D _pickup_loc
    (send _pickup_loc :serialization-length)
    ;; geometry_msgs/Pose2D _dropoff_loc
    (send _dropoff_loc :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Pose2D _pickup_loc
       (send _pickup_loc :serialize s)
     ;; geometry_msgs/Pose2D _dropoff_loc
       (send _dropoff_loc :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Pose2D _pickup_loc
     (send _pickup_loc :deserialize buf ptr-) (incf ptr- (send _pickup_loc :serialization-length))
   ;; geometry_msgs/Pose2D _dropoff_loc
     (send _dropoff_loc :deserialize buf ptr-) (incf ptr- (send _dropoff_loc :serialization-length))
   ;;
   self)
  )

(setf (get pick_drop_publisher::pick_drop :md5sum-) "711b7b4b694b3604c70b9f871c349cc7")
(setf (get pick_drop_publisher::pick_drop :datatype-) "pick_drop_publisher/pick_drop")
(setf (get pick_drop_publisher::pick_drop :definition-)
      "geometry_msgs/Pose2D pickup_loc
geometry_msgs/Pose2D dropoff_loc

================================================================================
MSG: geometry_msgs/Pose2D
# Deprecated
# Please use the full 3D pose.

# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.

# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.


# This expresses a position and orientation on a 2D manifold.

float64 x
float64 y
float64 theta

")



(provide :pick_drop_publisher/pick_drop "711b7b4b694b3604c70b9f871c349cc7")


