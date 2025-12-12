clear all;
clc;
close all;
format long g;
warning off;

%% Set Modeling Parameters
dt = 1/500; %0.1;
SimTime = 100;
Timer = [0:dt:SimTime];
temp_y = 0.000;
%% Aircraft Parameters
dx1 = 0.9325+0.049;                          % m
dx2 = 0.0725-0.049;
dx3 = 1.1725-0.049;
dy1 = 0.717 + temp_y;                        % m
dy2 = 0.717 - temp_y;                        % m

Ixx = 1.3 * 8.094;                        % kg*m^2
Iyy = 1.3 * 9.125;                        % kg*m^2
Izz = 1.3 * 16.8615;                    % kg*m^2
Ixz = -1.3 * 0.308;                       % kg*m^2

InertiaM = [Ixx 0 Ixz; 0 Iyy 0; Ixz 0 Izz];

g = 9.81;                         % kg * m/s^2
m = 41.97;                        % kg

S1 = 0.2624;
S2 = 0.5898;
S = S1 + S2;
c = 0.551;                        % Main Wing chord Length
b = 1.1;                          % Main Wing Half Span
d = 0.849;                        % Momnet arm length

inc = 0;                          % Wing incidence angle

%Ele PitchMoment Coefficient[1/rad]
Cm_del_E = -0.676;
Cm_del_A = 0.001156;

% Rolling Moment Coefficient[1/rad]
Cll_beta = -0.0518;
Cll_p = -0.4624;
Cll_r = 0.0218;
Cll_del_A = -0.0369 * 5;
Cll_del_R = 0.0026;

% Yawing Moment Coefficient[1/rad]
Cn_beta = 0.0866;
Cn_p = -0.0048;
Cn_r = -0.0723;
Cn_del_R = -0.0190;
Cn_del_A = -0.000385;

% y axis force Coefficient[1/rad]
Cy_beta = -1.1269;
Cy_p = 0.0;
Cy_r = 0.2374;
Cy_del_R = 0.0534;