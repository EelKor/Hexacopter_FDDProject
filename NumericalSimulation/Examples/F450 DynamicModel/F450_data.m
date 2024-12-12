% F450_data.m

d2r=pi/180;
r2d=180/pi;

% Add by ETKIM % ----------------------------------------------------
motorCr = 1148; %Motor throttle-speed curve slope(rad/s)
motorWb =-141.4;  %Motor speed-throttle curve constant term(rad/s)
motorTm = 0.02;  %Motor inertia time constant(s)
motorRpm0 =[4000 4000 4000 4000];

motorJm = 0.0001287;    %Moment of inertia of motor rotor + propeller(kg.m^2)

rotorCm = 1.779e-07;    %Rotor torque coefficient(kg.m^2) %M=Cm*w^2
rotorCt = 1.105e-05;    %Rotor thrust coefficient(kg.m^2) %T=Ct**w^2


g=9.81;      %Gravity acceleration(m/s^2)

Mass = 1.4; %Mass of UAV(kg)
Jxx = 0.0211;
Jyy = 0.0219;
Jzz = 0.0366;
Inertia= [Jxx, 0, 0;...
    0, Jyy, 0;...
    0, 0, Jzz];
Inertia_inv=inv(Inertia);


d_prop = 0.225;   %Body radius(m)
Cd  = 0.055;      %Damping coefficient(N/(m/s)^2)
Cmd = [0.0035 0.0039 0.0034]; %Damping moment coefficient vector(N/(m/s)^2)
dzcg = 0.12;

% ----------------------------------------------------
% Initial Condition

Alt_ground = 0;  % altidude ground

% Wind ---------------------------------------------------

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
