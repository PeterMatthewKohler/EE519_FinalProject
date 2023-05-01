function UKFStateSubscriberCallback(message)
% EKFStateSubscriberCallback - Callback function for EKFState topic
global UKFState
global timerUKFState

UKFState = [UKFState, message];
elapsedtime = toc;
timerUKFState = [timerUKFState,elapsedtime];
end


