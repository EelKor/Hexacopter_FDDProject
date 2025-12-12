% Controller Gains by Adding Angular Rate Feedback
% NCMS Quad 

SampleTime = 0.01;
g = 9.81;

% PID_pitch_rate
Kppr =    0.1;
Kipr =    0.1;
Kdpr =    0.004;
Npr  =    50;

% PID_roll_rate
Kprr =    0.1;
Kirr =    0.1;
Kdrr =    0.004;
Nrr  =    50;

% PID_yaw_rate 
Kpyr =    0.3744;   % approxi_oid_design.m result
Kiyr =    0.7395;
Kdyr =    0.0298;
Nyr  =    50;

% Angle Controller Gains

% P_pitch_angle
Kpp = 3.3894;

% P_roll_angle
Kpr = 3.3894;

% P_yaw_angle
Kpy = 3.3894;

% Velocity Controller Gains

% % PID_vx
Kpvx = 2.1109/g;
Kivx = 0.0728/g;
% 
% % PID_vy
Kpvy = 2.1109/g;
Kivy = 0.0728/g;

% PID_vz.
Kpvz = 0.3191;
Kivz = 0.6304;
Kdvz = 0.0254;
Nvz  = Npr;

% Position Controller Gains

% % P_x
Kpx = 1;
Kix = 0.02;
% 
% % P_y
Kpyaxis = 1;
Kiyaxis = 0.02;

% % P_z.
Kpz = 2.4;
Kiz = 0.09;

%max control angle,default 10deg
MAX_CONTROL_ANGLE_ROLL = 20*pi/180;
MAX_CONTROL_ANGLE_PITCH  = 20*pi/180;

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

%throttle when UAV is hovering
THR_HOVER = 0.6085;
THR_IDLE = 0.2;
%THR_HOVER = 0;

TAKEOFF_VEL = 1; % [m/s]

%Preceision Landing velocity
LAND_PRES_VEL = 0.2; % [m/s]

Transition_radius = 2; % This parameter should be similar to NAV_ACC_RAD

