function y = myMeasurementFcn(x)
% vdpMeasurementFcn Example measurement function for discrete-time
% nonlinear state estimators. 
%
% The measurement is the first state.
%
% yk = vdpMeasurementFcn(xk)
%
% Inputs:
%    xk - x[k], states at time k
%
% Outputs:
%    yk - y[k], measurements at time k
%
% See also extendedKalmanFilter, unscentedKalmanFilter

%   Copyright 2016 The MathWorks, Inc.

%#codegen

% The tag %#codegen must be included if you wish to generate code with 
% MATLAB Coder.

m = 1.023;
ct = 1.4865e-07;

p = x(1);
q = x(2);
r = x(3);
w = x(4:9);
h = x(10:15);

y = zeros(4,1);
y = [
    1*p
    1*q
    1*r
    ct/m*h'*w.^2 % acceleration from total thrust
    ];
end