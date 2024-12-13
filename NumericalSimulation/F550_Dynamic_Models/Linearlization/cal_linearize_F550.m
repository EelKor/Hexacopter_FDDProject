clear; close all;
run ../F550_data.m
load ../Trim_Calculation/trim_V0_H500_dynamic_allocation.mat

%% Specify the model name
model = 'F550_model_CA';
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
% eval(['load trim_', oc]) % 앞서 j와 트림 파일을 연동할 때 사용

%% Specify the analysis I/Os
% Set the analysis I/Os from the model
io(1)=linio('F550_model_CA/u_throt',1,'openinput');
io(2)=linio('F550_model_CA/u_roll',1,'openinput');
io(3)=linio('F550_model_CA/u_pitch',1,'openinput');
io(4)=linio('F550_model_CA/u_yaw',1,'openinput');
io(5)=linio('F550_model_CA/F550_Dynamic_Model',1,'output');
% [A,B,C,D] = linmod('F550_Models', x0, u0)
setlinio(model,io);     % getlinio(sys
getlinio(model)

%% Specify the operating point
% Use the model initial condition
op = operpoint(model);
op.Inputs(1).u=u0(1);
op.Inputs(2).u=u0(2);
op.Inputs(3).u=u0(3);
op.Inputs(4).u=u0(4);

%% Specify the custom state ordering
% State 이름은 OperationPoint 데이터에서 구할 수 있음. op.States(1,1).Block
stateorder = {'F550_model_CA/F550_Dynamic_Model/F550_Dynamic_Model/dynamic and kinematic mdel1/states',...
    'F550_model_CA/F550_Dynamic_Model/F550_Dynamic_Model/Motor Model/MotorNonlinearDynamic1/Motor_Dynamics (1st order)/Integrator',...
    'F550_model_CA/F550_Dynamic_Model/F550_Dynamic_Model/Motor Model/MotorNonlinearDynamic2/Motor_Dynamics (1st order)/Integrator',...
    'F550_model_CA/F550_Dynamic_Model/F550_Dynamic_Model/Motor Model/MotorNonlinearDynamic3/Motor_Dynamics (1st order)/Integrator',...
    'F550_model_CA/F550_Dynamic_Model/F550_Dynamic_Model/Motor Model/MotorNonlinearDynamic4/Motor_Dynamics (1st order)/Integrator',...
    'F550_model_CA/F550_Dynamic_Model/F550_Dynamic_Model/Motor Model/MotorNonlinearDynamic5/Motor_Dynamics (1st order)/Integrator',...
    'F550_model_CA/F550_Dynamic_Model/F550_Dynamic_Model/Motor Model/MotorNonlinearDynamic6/Motor_Dynamics (1st order)/Integrator'
    };

%% Linearize the model
linsys = linearize(model,io,op,'StateOrder',stateorder);