function ros1msg = fp_msgs_msg_SigmaID_2To1_Converter(message,ros1msg)
%fp_msgs_msg_SigmaID_2To1_Converter passes data of ROS 2 message to ROS message.
% Copyright 2019 The MathWorks, Inc.    
ros1msg.Sigma = message.sigma;
ros1msg.Id = message.id;
end