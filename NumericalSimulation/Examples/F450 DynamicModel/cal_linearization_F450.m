% cal_linearization_F450.m

clear,  clc
warning off

F450_data

%% Specify the model name
model  = 'F450_model_CA';
j=1;   % =1 : Hover
       % =2 : V=5mps,H=100
       % =3 : theta=10 deg

if j==1
    oc='hover';
elseif j==2
    oc='V5';
elseif j==3
    oc='theta10';
end

eval(['load trim_', oc])

%[A1,B1,C1,D1] = linmod(model,[motorRpm0'; x0],u0);

%% Calculate linear model

%% Specify the analysis I/Os
% Set the analysis I/Os from the model
io(1)=linio('F450_model_CA/u_throt',1,'openinput');
io(2)=linio('F450_model_CA/u_roll',1,'openinput');
io(3)=linio('F450_model_CA/u_pitch',1,'openinput');
io(4)=linio('F450_model_CA/u_yaw',1,'openinput');
io(5)=linio('F450_model_CA/F450dynamicModel',1,'output');

setlinio(model,io);     % getlinio(sys

%% Specify the operating point
% Use the model initial condition
op = operpoint(model);
op.Inputs(1).u=u0(1);
op.Inputs(2).u=u0(2);
op.Inputs(3).u=u0(3);
op.Inputs(4).u=u0(4);

%% Specify the custom state ordering
stateorder = {'F450_model_CA/F450dynamicModel|F450_model/Quadcopter_Dynamic_Model/dynamic and kinematic model/states',...
    'F450_model_CA/F450dynamicModel|F450_model/Quadcopter_Dynamic_Model/Motor Model/MotorNonlinearDynamic1/Motor_Dynamics (1st order)/Integrator',...
    'F450_model_CA/F450dynamicModel|F450_model/Quadcopter_Dynamic_Model/Motor Model/MotorNonlinearDynamic2/Motor_Dynamics (1st order)/Integrator',...
    'F450_model_CA/F450dynamicModel|F450_model/Quadcopter_Dynamic_Model/Motor Model/MotorNonlinearDynamic3/Motor_Dynamics (1st order)/Integrator',...
    'F450_model_CA/F450dynamicModel|F450_model/Quadcopter_Dynamic_Model/Motor Model/MotorNonlinearDynamic4/Motor_Dynamics (1st order)/Integrator'};
%% Linearize the model

%% Linearize the model
linsys = linearize(model,io,op,'StateOrder',stateorder);
A=linsys.A;
B=linsys.B;
C=linsys.C;
D=linsys.D;

eval(['save linmodel_', oc, ' A B C D'])

ku   = 1; kv     = 2;  kw   = 3;
kp   = 4; kq     = 5;  kr   = 6;
kphi = 7; ktheta = 8;  kpsi = 9;
kpx  =10; kpy    =11;  kpz  =12;

% Longitudinal Motion (states = u w q theta)
A_lon = A([ku kw kq ktheta], [ku kw kq ktheta]);

% Lateral Directional Motion (states = v p r psi)
A_lat = A([kv kp kr kphi], [kv kp kr kphi]);

A12 = A([ku kw kq ktheta],[kv kp kr kphi]);
A21 = A([kv kp kr kphi],[ku kw kq ktheta]);
[A_lon A12;A21 A_lat];

eval(['save linmodel2_', oc, ' A B C D A_lon A_lat'])