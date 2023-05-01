function [data, info] = pointRPY
%PointRPY gives an empty data for fp_msgs/PointRPY
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'fp_msgs/PointRPY';
[data.position, info.position] = ros.internal.ros2.messages.geometry_msgs.point;
info.position.MLdataType = 'struct';
[data.roll, info.roll] = ros.internal.ros2.messages.ros2.default_type('double',1,0);
[data.pitch, info.pitch] = ros.internal.ros2.messages.ros2.default_type('double',1,0);
[data.yaw, info.yaw] = ros.internal.ros2.messages.ros2.default_type('double',1,0);
info.MessageType = 'fp_msgs/PointRPY';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,7);
info.MatPath{1} = 'position';
info.MatPath{2} = 'position.x';
info.MatPath{3} = 'position.y';
info.MatPath{4} = 'position.z';
info.MatPath{5} = 'roll';
info.MatPath{6} = 'pitch';
info.MatPath{7} = 'yaw';
