% cal_trim_F450.m

clear,  clc
warning off

F450_data
% dzcg =0*0.12/4; 

%% Specify the model name
model  = 'F450_model_CA';
j=2;   % =1 : Hover
       % =2 : V=5mps,H=100
       % =3 : theta=10 deg

motorRpm0 =[4000 4000 4000 4000];
x0=zeros(12,1);

%% Specify the model name
opspec = operspec(model);

for i=1:4   % Actuator
    opspec.States(i).SteadyState = 1;
    opspec.States(i).x           = 300;
    opspec.States(i).Known       = 0;
end

if j==1
    oc='hover';
    % Hover
    opspec.States(5).SteadyState = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1];
    opspec.States(5).x           = [0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -100];
    opspec.States(5).Known       = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1];
elseif j==2
    oc='V5';
    opspec.States(5).SteadyState = [1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1];
    opspec.States(5).x           = [5 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -100];
    opspec.States(5).Known       = [0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1];
    opspec.Outputs(2).y = 5;
    opspec.Outputs(2).Known = true;
elseif j==3
    oc='theta10';
    opspec.States(5).SteadyState = [1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1];
    opspec.States(5).x           = [5 ,0, 0, 0, 0, 0, 0, -10/57.3, 0, 0, 0, -100];
    opspec.States(5).Known       = [0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1];
end

%% Set the constraints on the inputs in the model.
opspec.Inputs(1).u =  0.5;
opspec.Inputs(2).u =  0;
opspec.Inputs(3).u =  0;
opspec.Inputs(4).u =  0;

%% Perform the operating point search.
opt = findopOptions('DisplayReport','iter');
[op,opreport] = findop(model,opspec,opt);

opreport.states

for i=1:4
    u0(i)=opreport.inputs(i).u;
end
for i=1:4
    motorRpm0(i)=30/pi*opreport.states(i).x;
end
x0=opreport.states(5).x;

fprintf('u0 = '), fprintf('%8.4f ',u0), fprintf(' \n')
x0', motorRpm0

eval(['save trim_', oc, ' u0 x0 motorRpm0'])

%% Verification of trim data
simout = sim('sim_F450_bare_trim.slx',10);
a=simout.y;
tout=simout.tout;

% plot response
n=3; m=3; k=1;
subplot(n,m,k), k=k+1; plot(tout, a(:,1), 'LineWidth',1.5), ylabel('U(mps)'), grid
subplot(n,m,k), k=k+1; plot(tout, a(:,2), 'LineWidth',1.5), ylabel('V(mps)'), grid
subplot(n,m,k), k=k+1; plot(tout, a(:,3), 'LineWidth',1.5), ylabel('W(mps)'), grid

subplot(n,m,k), k=k+1; plot(tout, 57.3*a(:,4), 'LineWidth',1.5), ylabel('p(deg/sec)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*a(:,5), 'LineWidth',1.5), ylabel('q(deg/sec)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*a(:,6), 'LineWidth',1.5), ylabel('r(deg/sec)'), grid

subplot(n,m,k), k=k+1; plot(tout, 57.3*a(:,7), 'LineWidth',1.5), ylabel('phi(deg)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*a(:,8), 'LineWidth',1.5), ylabel('theta(deg)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*a(:,9), 'LineWidth',1.5), ylabel('psi(deg)'), grid
shg
