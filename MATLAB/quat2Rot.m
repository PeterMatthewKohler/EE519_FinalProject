% quat2Rot(Q) Returns a rotation matrix 
% 
%
% R = quat2Rot(Q) 
% Returns the 3x3 rotation matrix that corresponds to 
% the input quaternion.
%
% Q = 1x4 quaternion input in the form Q = [q0; q_vec]
% R = 3x3 rotation matrix output
%
% Name: Peter Kohler
% Student Number: 10429312
% Course: MEGN 544
% Date: 9/10/21

function R = quat2Rot(Q)

q=zeros(3,1);
q_0 = Q(1);
q(1:3,1) = Q(2:4);
R = ((q_0^2)-(q'*q))*eye(3) + 2*q_0*cpMap(q) + 2*q*q';
end





