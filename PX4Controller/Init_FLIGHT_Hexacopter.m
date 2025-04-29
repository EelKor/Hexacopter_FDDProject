% Controller Gains by Adding Angular Rate Feedback
%CNU 고장진단 Hexacopter

SampleTime = 1/250;
SampleTime_SAS = 1/1000;

g = 9.81;
r2d = 180/pi;
d2r = pi/180;

%max control angle,default 10deg
MAX_CONTROL_ANGLE_ROLL = 30*pi/180;
MAX_CONTROL_ANGLE_PITCH  = 30*pi/180;

%max control angle rate,rad/s 
MAX_CONTROL_ANGLE_RATE_PITCH = 360*pi/180;
MAX_CONTROL_ANGLE_RATE_ROLL = 360*pi/180;
MAX_CONTROL_ANGLE_RATE_Y = 120*pi/180;

%Maximum control speed, m/s
MAX_CONTROL_VELOCITY_XY = 1.5;
MAX_CONTROL_VELOCITY_Z = 1;

%Throttle amplitude
MAX_MAN_THR = 0.9;
MIN_MAN_THR = 0.05;
