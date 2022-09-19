// Auto-generated. Do not edit!

// (in-package pick_drop_publisher.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class pick_drop {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.pickup_loc = null;
      this.dropoff_loc = null;
    }
    else {
      if (initObj.hasOwnProperty('pickup_loc')) {
        this.pickup_loc = initObj.pickup_loc
      }
      else {
        this.pickup_loc = new geometry_msgs.msg.Pose2D();
      }
      if (initObj.hasOwnProperty('dropoff_loc')) {
        this.dropoff_loc = initObj.dropoff_loc
      }
      else {
        this.dropoff_loc = new geometry_msgs.msg.Pose2D();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type pick_drop
    // Serialize message field [pickup_loc]
    bufferOffset = geometry_msgs.msg.Pose2D.serialize(obj.pickup_loc, buffer, bufferOffset);
    // Serialize message field [dropoff_loc]
    bufferOffset = geometry_msgs.msg.Pose2D.serialize(obj.dropoff_loc, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type pick_drop
    let len;
    let data = new pick_drop(null);
    // Deserialize message field [pickup_loc]
    data.pickup_loc = geometry_msgs.msg.Pose2D.deserialize(buffer, bufferOffset);
    // Deserialize message field [dropoff_loc]
    data.dropoff_loc = geometry_msgs.msg.Pose2D.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 48;
  }

  static datatype() {
    // Returns string type for a message object
    return 'pick_drop_publisher/pick_drop';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '711b7b4b694b3604c70b9f871c349cc7';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    geometry_msgs/Pose2D pickup_loc
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new pick_drop(null);
    if (msg.pickup_loc !== undefined) {
      resolved.pickup_loc = geometry_msgs.msg.Pose2D.Resolve(msg.pickup_loc)
    }
    else {
      resolved.pickup_loc = new geometry_msgs.msg.Pose2D()
    }

    if (msg.dropoff_loc !== undefined) {
      resolved.dropoff_loc = geometry_msgs.msg.Pose2D.Resolve(msg.dropoff_loc)
    }
    else {
      resolved.dropoff_loc = new geometry_msgs.msg.Pose2D()
    }

    return resolved;
    }
};

module.exports = pick_drop;
