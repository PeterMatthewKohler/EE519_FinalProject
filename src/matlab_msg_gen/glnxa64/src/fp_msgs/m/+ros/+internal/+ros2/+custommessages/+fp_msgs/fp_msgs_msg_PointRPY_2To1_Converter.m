function ros1msg = fp_msgs_msg_PointRPY_2To1_Converter(message,ros1msg)
%fp_msgs_msg_PointRPY_2To1_Converter passes data of ROS 2 message to ROS message.
% Copyright 2019 The MathWorks, Inc.    
ros1msg.Position.X = message.position.x;
ros1msg.Position.Y = message.position.y;
ros1msg.Position.Z = message.position.z;
ros1msg.Roll = message.roll;
ros1msg.Pitch = message.pitch;
ros1msg.Yaw = message.yaw;
end