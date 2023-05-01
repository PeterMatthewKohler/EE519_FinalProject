function [data, info] = sigmaID
%SigmaID gives an empty data for fp_msgs/SigmaID
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'fp_msgs/SigmaID';
[data.sigma, info.sigma] = ros.internal.ros2.messages.ros2.default_type('double',1,0);
[data.id, info.id] = ros.internal.ros2.messages.ros2.default_type('int8',1,0);
info.MessageType = 'fp_msgs/SigmaID';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,2);
info.MatPath{1} = 'sigma';
info.MatPath{2} = 'id';
