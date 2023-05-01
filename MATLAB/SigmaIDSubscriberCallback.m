function SigmaIDSubscriberCallback(message)
% EKFStateSubscriberCallback - Callback function for EKFState topic
global SigmaID
global SigmaIDTimer

SigmaID = [SigmaID, message];
elapsedtime = toc;
SigmaIDTimer = [SigmaIDTimer,elapsedtime];
end

