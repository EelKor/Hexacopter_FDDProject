%% vehicle MoI
J = quadModel.Jb; 
I_xx = J(1,1);
I_yy = J(2,2);
I_zz = J(3,3);
%% Q-filter for roll/pitch
a0 = 1;
a1 = 3;
tau = 0.1;
num_Qfilter = a0/tau^2;
den_Qfilter = [1 a1/tau a0/tau^2];
% Q_Filter = tf(num_Qfilter,den_Qfilter);
%% x axis
% Simple System
num_X = 1;
den_X = [I_xx 0 0];

num_Inv_X = conv(den_X,num_Qfilter);
den_Inv_X = conv(num_X,den_Qfilter);
% Q_Filter2 = tf(num_Inv_X,den_Inv_X);
%% y axis
% Simple System
num_Y = 1;
den_Y = [I_yy 0 0];

num_Inv_Y = conv(den_Y, num_Qfilter);
den_Inv_Y = conv(num_Y, den_Qfilter);
%% Q-filter for yaw
a0 = 1;
a1 = 3;
tau = 0.3;
num_Qfilter_Z = a0/tau^2;
den_Qfilter_Z = [1 a1/tau a0/tau^2];
% Q_Filter_yaw = tf(num_Qfilter,den_Qfilter);
%% z axis
% Simple System
num_Z = 1;
den_Z = [I_zz 0 0];

num_Inv_Z = conv(den_Z, num_Qfilter_Z);
den_Inv_Z = conv(num_Z, den_Qfilter_Z);
% Q_Filter2_yaw = tf(num_Inv_X,den_Inv_X);
%% Linear Extended-State Observer (LESO)
alpha = tau; % sec
alpha = 0.08; % sec
mu = 0.2;
wc = 2*pi/alpha;
w0 = wc/mu;
% w0 = sqrt(a0/tau^2)
A = [
    0 1 0
    0 0 1
    0 0 0
    ];   
B = [0 1 0]';
C = [1 0 0];
observability = rank(obsv(A,C));
% check if the disturbance F can be estimated.
l1 = 3*w0;
l2 = 2*w0^2;
l3 = w0^3;
L = [l1 l2 l3]';
%% Neural Network Adaptive Control
kp = 2.0;
kd = 1.2;
An = [
    0 1;
    -kd -kp
    ];
Bn = [0 1]';
P = lyap(An',eye(2));
n_in = 6; % no of input layer
n_hid = 20; % no of hidden layer
n_out = 1; % no of output layer
V0 = randn(n_hid,n_in+1); % +1 means for bias input 
W0 = randn(n_out,n_hid+1); % +1 means for bias input