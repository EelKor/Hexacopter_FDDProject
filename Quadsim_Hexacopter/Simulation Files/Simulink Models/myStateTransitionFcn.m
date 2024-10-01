function x = myStateTransitionFcn(x,u)
% Example state transition function for discrete-time nonlinear state
% estimators.
%
% xk1 = vdpStateFcn(xk)
%
% Inputs:
%    xk - States x[k]
%
% Outputs:
%    xk1 - Propagated states x[k+1]
%
% See also extendedKalmanFilter, unscentedKalmanFilter

%   Copyright 2016 The MathWorks, Inc.

%#codegen

% The tag %#codegen must be included if you wish to generate code with
% MATLAB Coder.
%% Euler integration of continuous-time dynamics x'=f(x) with sample time dt
dt = 0.05; % [s] Sample time
x = x + StateFcnContinuous(x,u)*dt;
end

function dxdt = StateFcnContinuous(x,u)
%% vdpStateFcnContinuous Evaluate the van der Pol ODEs for mu = 1
% dxdt = [
%     x(2)
%     (1-x(1)^2)*x(2)-x(1)
%     ];
m = 1.023;
g = 9.81;
ct = 1.4865e-07;
cq = 2.92500000000000e-09;
Jb = [0.00949990000000000,0,0;
    0,0.00949990000000000,0;
    0,0,0.0185760000000000];
Jx = Jb(1,1);
Jy = Jb(2,2);
Jz = Jb(3,3);
Jm = [3.78822248603988e-06];
d = [0.222250000000000];
d1 = d*cos(60*pi/180);
d2 = d*sin(60*pi/180);
tw = [0.0760000000000000]; % motor time delay
th = 0.01; % fault time delay

p = x(1);
q = x(2);
r = x(3);
w = x(4:9);
h = x(10:15);


dxdt = zeros(15,1);
dxdt = [
    1/Jx*( ([-d1 d1 d d1 -d1 -d]'.*ct.*h)'*w.^2 + Jm*q*[-1 1 -1 1 -1 1]*w + (Jy-Jz)*q*r )
    1/Jy*( (d2*[-1 -1 0 1 1 0]'.*ct.*h)'*w.^2 + Jm*p*[1 -1 1 -1 1 -1]*w + (Jz-Jx)*r*p )
    1/Jz*( ([-1 1 -1 1 -1 1]'.*cq.*h)'*w.^2 + (Jx-Jy)*p*q )
    -1/tw*( w(1) - u(1) )
    -1/tw*( w(2) - u(2) )
    -1/tw*( w(3) - u(3) )
    -1/tw*( w(4) - u(4) )
    -1/tw*( w(5) - u(5) )
    -1/tw*( w(6) - u(6) )
    0
    0
    0
    0
    0
    0
    ];
end