function EKFStateSubscriberCallback(message)
% EKFStateSubscriberCallback - Callback function for EKFState topic
global EKFState
global timerEKFState

EKFState = [EKFState, message];
elapsedtime = toc;
timerEKFState = [timerEKFState,elapsedtime];
end

