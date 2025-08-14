% F550_data.m
clc; clear; close all;

d2r=pi/180;
r2d=180/pi;

% Add by SSLEE - T-motor Mn3110 470kv 대충
% motorCr = 732.67; % 최대 RPM 6000 잡고 선형으로 추력 곡선 계산
% motorWb = -73.3; % pwm 1100에서 돌기 시작
% motorTm = 0.01;  %Motor inertia time constant(s)
% motorJm = 0.0001287;    %Moment of inertia of motor rotor + propeller(kg.m^2)
% rotorCt = 2.487e-05;
% rotorCm = 1.779e-07;

% % Add by ETKIM % ----------------------------------------------------
% motorCr = 1148; %Motor throttle-speed curve slope(rad/s)
% motorWb =-141.4;  %Motor speed-throttle curve constant term(rad/s)
% motorTm = 0.02;
% rotorCm = 1.779e-07*1.2;    %Rotor torque coefficient(kg.m^2) %M=Cm*w^2
% rotorCt = 1.105e-05*1.3;    %Rotor thrust coefficient(kg.m^2) %T=Ct**w^   2
motorJm = 0.0001287;    %Moment of inertia of motor rotor + propeller(kg.m^2)

%% 
g=9.81;      %Gravity acceleration(m/s^2)

Mass = 2.06; %Mass of UAV(kg)

% F550 Moment of Inertia from  
Jxx = 0.03259;
Jyy = 0.03259;
Jzz = 0.06059*0.8*0.85;
Inertia= [Jxx, 0, 0;...
    0, Jyy, 0;...
    0, 0, Jzz];
Inertia_inv=inv(Inertia);

armLength = 0.275;   %Body radius(m)
Cd  = 0.010;      %Damping coefficient(N/(m/s)^2)
Cmd = [0.0035 0.0039 0.0034]; %Damping moment coefficient vector(N/(m/s)^2)
dzcg = 0.12;

%% ----------------------------------------------------
% Initial Condition

Alt_ground = 0;  % altidude ground

%% Wind ---------------------------------------------------
NoWind=0;
if NoWind==1;
    Wind_Strength=0;   
    Wind_Direc=0;      
    Wind_GustStrength =0;       
    Wind_GustDirec  = 0;      
    Wind_DiscreteGustAmp = [0 0 0];
else
    Wind_Strength=1;  % Wind speed at 6 m (m/sec)
    Wind_Direc=60;   %  Gust Wind directin at 6m (degree clockwise from north)
    Wind_GustStrength =1;      % Gust Wind speed at 6m (m/sec)
    Wind_GustDirec  = 0;         % Gust Wind directin at 6m  
    Wind_DiscreteGustAmp = [1.5 1.5 1.0]; % Gust Amplitue (m/sec)
end

%% Initial data
motorRpm0 =[0 0 0 0 0 0];
x0=[0 0 0 0 0 0 0 0 0 0 0 -0.01];
u0 = [0 0 0 0];



%% UAV Dynamics Constants

%rotorOffset = [0 0 0]; % Rotors position offsets from Gravity center
dragCoeffMov = 0.01; %drag coefficient for linear motion of quadcopter
windVel = [0 0 0]';

% Contact model
contact.translation.spring = 3100;
contact.translation.damper = 100;
contact.translation.friction = 0.5;
contact.translation.vd = 0.02;
contact.translation.maxFriction = 20;
contact.translation.maxNormal = 80;

contact.rotation.spring = 2;
contact.rotation.damper = 1;
contact.rotation.friction = 0.03;
control.rotation.maxMoment = 0.1;
control.rotation.friction = 0.025;
control.rotation.vd = 0.2;

% % Initial states
% init.equilibriumZ =  Mass*g/contact.translation.spring;
% init.posNED = [0, 0, init.equilibriumZ]; % m
% init.vb = [0 0 0]'; %m/s
% init.euler = [0, 0, 0]'; %Roll Pitch Yaw Rads
% init.angRates = [0, 0, 0]; %rad/s

rotorDir = [1 -1 1 -1 -1 1];

%Reference location: Chuungnam National Univ.
% This is the home position also 
ref_lat = 36.364905;
ref_lon = 127.344377;
ref_height = 23;

%% UAV Dynamics Data Serialization Constants

%Gain to convert m to mm
m_to_mm = 1000;

%Gain to convert uT to Gauss
uT_to_gauss = 0.01;

%Gain to convert m/s^2 to mg
ms2_to_mg = (1/9.80665)*1000;

%Gain to convert m/s to cm/s
ms_to_cms = 100;

% Maximum Serial data read size from Pixhawk
MAVLink_Input_Read_Size = 1024;

% Sample Time of Plant and Controller (100 Hz)
SampleTime = 1/100;
Ts_sensor = 1/100;
