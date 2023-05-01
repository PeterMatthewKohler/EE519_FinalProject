function ros2msg = fp_msgs_msg_PointRPY_1To2_Converter(message,ros2msg)
%fp_msgs_msg_PointRPY_1To2_Converter passes data of ROS message to ROS 2 message.
% Copyright 2019 The MathWorks, Inc.
ros2msg.position.x = message.Position.X;
ros2msg.position.y = message.Position.Y;
ros2msg.position.z = message.Position.Z;
ros2msg.roll = message.Roll;
ros2msg.pitch = message.Pitch;
ros2msg.yaw = message.Yaw;
end