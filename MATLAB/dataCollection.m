%% Testing out ROS2 MATLAB Functionality
clear;clc;close all;
setenv("ROS_DOMAIN_ID","30");

addpath('Documents/MATLAB/MEGN_544'); % Function definitions

global odomPose;
global timerOdom;
global EKFState
global timerEKFState
global UKFState
global timerUKFState
global SigmaID
global SigmaIDTimer

EKFState = [];
odomPose = [];
UKFState = [];
SigmaID = [];
timerOdom = [];
timerEKFState = [];
timerUKFState = [];
SigmaIDTimer = [];
dataCollector = ros2node("/collectorNode");
pause(5)
% Start timer
tic;
odomSub = ros2subscriber(dataCollector, "/odom", @odometrySubscriberCallback);
EKFStateSub = ros2subscriber(dataCollector, "/EKFState", @EKFStateSubscriberCallback);
UKFStateSub = ros2subscriber(dataCollector, "/UKFState", @UKFStateSubscriberCallback);
SigmaIDSub = ros2subscriber(dataCollector, "/SigmaID", @SigmaIDSubscriberCallback);
%jointStateNoiseSub = ros2subscriber(dataCollector, "/joint_states_with_noise", @jointStateNoiseSubscriberCallback);
pause(60)

clear odomSub EKFStateSub UKFStateSub jointStateNoiseSub

%% Plotting recorded data
%figure(1)
[~,c] = size(odomPose);
xodom = zeros(1,c);
yodom = zeros(1,c);
x_q = zeros(1,c);
y_q = zeros(1,c);
z_q = zeros(1,c);
w_q = zeros(1,c);
Y = zeros(1,c);
for i = 1:c
    xodom(i) = odomPose(i).position.x;
    yodom(i) = odomPose(i).position.y;
    x_q(i) = odomPose(i).orientation.x;
    y_q(i) = odomPose(i).orientation.y;
    z_q(i) = odomPose(i).orientation.z;
    w_q(i) = odomPose(i).orientation.w;
    Q = [w_q(i) x_q(i) y_q(i) z_q(i)];
    Rot = quat2Rot(Q);
    [Roll, Pitch, Yaw] = rot2RPY(Rot);
    %R(i) = Roll(1);
    %P(i) = Pitch(1);
    Y(i) = Yaw(1);
end

%figure(2)
[~,c] = size(EKFState);
x_ekf = zeros(1,c);
y_ekf = zeros(1,c);
yaw_ekf = zeros(1,c);
for i = 1:c
    x_ekf(i) = EKFState(i).position.x;
    y_ekf(i) = EKFState(i).position.y;
    yaw_ekf(i) = EKFState(i).yaw;
end

[~,c] = size(UKFState);
x_ukf = zeros(1,c);
y_ukf = zeros(1,c);
yaw_ukf = zeros(1,c);
for i = 1:c
    x_ukf(i) = UKFState(i).position.x;
    y_ukf(i) = UKFState(i).position.y;
    yaw_ukf(i) = UKFState(i).yaw;
end

[~,c] = size(SigmaID);
sigma = zeros(1,c);
ID = zeros(1,c);
for i = 1:c
    sigma(i) = SigmaID(i).sigma;
    ID(i) = SigmaID(i).id;
end

figure(1)
plot(timerOdom, xodom, timerEKFState, x_ekf, timerUKFState, x_ukf);
title("X")
legend("x odom","x ekf", "x ukf")

figure(2)
plot(timerOdom, yodom, timerEKFState, y_ekf, timerUKFState, y_ukf);
title("Y")
legend("y odom","y ekf", "y ukf")

figure(3)
plot(timerOdom, Y, timerEKFState, yaw_ekf, timerUKFState, yaw_ukf);
title("Yaw")
legend("yaw odom", "yaw ekf", "yaw ukf")

figure(4)
plot(SigmaIDTimer, sigma, SigmaIDTimer, ID);
title("Sigma and ID")
legend("Sigma", "ID")

%% Calculate Mean Square Error
MSE_ekf_x = 0;
MSE_ekf_y = 0;
MSE_ekf_yaw = 0;
MSE_ukf_x = 0;
MSE_ukf_y = 0;
MSE_ukf_yaw = 0;
clc
[~,c] = size(xodom);
for i = 1:c
    MSE_ekf_x = MSE_ekf_x + (xodom(i) - x_ekf(i))^2;
    MSE_ekf_y = MSE_ekf_y + (yodom(i) - y_ekf(i))^2;
    
    MSE_ukf_x = MSE_ukf_x + (xodom(i) - x_ukf(i))^2;
    MSE_ukf_y = MSE_ukf_y + (yodom(i) - y_ukf(i))^2;
    % Since the time indices don't align perfectly, we need to remove the
    % few cases where one yaw value gets wrapped by pi and the other doesn't yet 
    if (abs(Y(i) - yaw_ekf(i)) < 0.75)
        MSE_ekf_yaw = MSE_ekf_yaw + (Y(i) - yaw_ekf(i))^2;
    end
    if (abs(Y(i) - yaw_ukf(i)) < 0.75)
        MSE_ukf_yaw = MSE_ukf_yaw + (Y(i) - yaw_ukf(i))^2;
    end
end

MSE_ekf_x = (1/c)*MSE_ekf_x
MSE_ekf_y = (1/c)*MSE_ekf_y
MSE_ekf_yaw = (1/c)*MSE_ekf_yaw
MSE_ukf_x = (1/c)*MSE_ukf_x
MSE_ukf_y = (1/c)*MSE_ukf_y
MSE_ukf_yaw = (1/c)*MSE_ukf_yaw


% ros2genmsg build commands:
% Taken from: https://www.mathworks.com/help/ros/ref/ros2genmsg.html
% setenv('LD_LIBRARY_PATH', '/usr/lib/x86_64-linux-gnu/');
% pe = pyenv("Version","/home/peter/anaconda3/envs/matlabros2/bin/python3.9")
% folderpath = fullfile(pwd, "Documents/EENG_519/Final_Project/src")
% ros2genmsg(folderpath)



