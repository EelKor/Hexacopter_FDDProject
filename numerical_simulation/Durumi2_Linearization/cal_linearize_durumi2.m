%% cal_trim_durumi2.m
clear
warning off

durumi2_init

load durumi2_trim_100 

%% Linearization

[A, B, C, D] = linmod('durumi2_model',x0,u0);

ku   = 1; kv     = 2;  kw   = 3; 
kp   = 4; kq     = 5;  kr   = 6;
kphi = 7; ktheta = 8;  kpsi = 9; 
kpx  =10; kpy    =11;  kpz  =12;

kde =1;  kda =2;  kdr =3;  kdp =4;

% Longitudinal Motion (states = u w q theta)
A_lon = A([ku kw kq ktheta], [ku kw kq ktheta]);
B_lon = B([ku kw kq ktheta], [kde kdp]);

% Lateral Directional Motion (states = v p r psi)
A_lat = A([kv kp kr kphi], [kv kp kr kphi]);
B_lat = B([kv kp kr kphi], [kda kdr]);

A12 = A([ku kw kq ktheta],[kv kp kr kphi]);
A21 = A([kv kp kr kphi],[ku kw kq ktheta]);
[A_lon A12;A21 A_lat];

save durumi2_linmodel_100 A B C D A_lon B_lon A_lat B_lat