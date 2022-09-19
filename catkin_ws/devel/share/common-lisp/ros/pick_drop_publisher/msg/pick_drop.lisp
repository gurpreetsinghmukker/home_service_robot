; Auto-generated. Do not edit!


(cl:in-package pick_drop_publisher-msg)


;//! \htmlinclude pick_drop.msg.html

(cl:defclass <pick_drop> (roslisp-msg-protocol:ros-message)
  ((pickup_loc
    :reader pickup_loc
    :initarg :pickup_loc
    :type geometry_msgs-msg:Pose2D
    :initform (cl:make-instance 'geometry_msgs-msg:Pose2D))
   (dropoff_loc
    :reader dropoff_loc
    :initarg :dropoff_loc
    :type geometry_msgs-msg:Pose2D
    :initform (cl:make-instance 'geometry_msgs-msg:Pose2D)))
)

(cl:defclass pick_drop (<pick_drop>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pick_drop>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pick_drop)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pick_drop_publisher-msg:<pick_drop> is deprecated: use pick_drop_publisher-msg:pick_drop instead.")))

(cl:ensure-generic-function 'pickup_loc-val :lambda-list '(m))
(cl:defmethod pickup_loc-val ((m <pick_drop>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pick_drop_publisher-msg:pickup_loc-val is deprecated.  Use pick_drop_publisher-msg:pickup_loc instead.")
  (pickup_loc m))

(cl:ensure-generic-function 'dropoff_loc-val :lambda-list '(m))
(cl:defmethod dropoff_loc-val ((m <pick_drop>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pick_drop_publisher-msg:dropoff_loc-val is deprecated.  Use pick_drop_publisher-msg:dropoff_loc instead.")
  (dropoff_loc m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pick_drop>) ostream)
  "Serializes a message object of type '<pick_drop>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pickup_loc) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'dropoff_loc) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pick_drop>) istream)
  "Deserializes a message object of type '<pick_drop>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pickup_loc) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'dropoff_loc) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pick_drop>)))
  "Returns string type for a message object of type '<pick_drop>"
  "pick_drop_publisher/pick_drop")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pick_drop)))
  "Returns string type for a message object of type 'pick_drop"
  "pick_drop_publisher/pick_drop")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pick_drop>)))
  "Returns md5sum for a message object of type '<pick_drop>"
  "711b7b4b694b3604c70b9f871c349cc7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pick_drop)))
  "Returns md5sum for a message object of type 'pick_drop"
  "711b7b4b694b3604c70b9f871c349cc7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pick_drop>)))
  "Returns full string definition for message of type '<pick_drop>"
  (cl:format cl:nil "geometry_msgs/Pose2D pickup_loc~%geometry_msgs/Pose2D dropoff_loc~%~%================================================================================~%MSG: geometry_msgs/Pose2D~%# Deprecated~%# Please use the full 3D pose.~%~%# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.~%~%# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.~%~%~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pick_drop)))
  "Returns full string definition for message of type 'pick_drop"
  (cl:format cl:nil "geometry_msgs/Pose2D pickup_loc~%geometry_msgs/Pose2D dropoff_loc~%~%================================================================================~%MSG: geometry_msgs/Pose2D~%# Deprecated~%# Please use the full 3D pose.~%~%# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.~%~%# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.~%~%~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pick_drop>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pickup_loc))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'dropoff_loc))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pick_drop>))
  "Converts a ROS message object to a list"
  (cl:list 'pick_drop
    (cl:cons ':pickup_loc (pickup_loc msg))
    (cl:cons ':dropoff_loc (dropoff_loc msg))
))
