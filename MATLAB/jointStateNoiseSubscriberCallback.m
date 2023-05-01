function jointStateNoiseSubscriberCallback(message)
%jointStateNoiseSubscriberCallback Callback function for joint state Subscriber
global jointStateNoise;
global timerJointStateNoise;
% We just want the velocity
jointStateNoise = [jointStateNoise, message.velocity];   % Equivalent to pushback
elapsedTime = toc;
timerJointStateNoise = [timerJointStateNoise,elapsedTime];    % pushback
end