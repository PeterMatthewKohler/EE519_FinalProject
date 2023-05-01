function odometrySubscriberCallback(message)
%ODOMETRYSUBSCRIBERCALLBACK Callback function for odom Subscriber
global odomPose;
global timerOdom;
odomPose = [odomPose, message.pose.pose];   % Equivalent to pushback
elapsedTime = toc;
timerOdom = [timerOdom,elapsedTime];    % pushback
end

