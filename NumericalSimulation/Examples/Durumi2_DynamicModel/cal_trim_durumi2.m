%% cal_trim_durumi2.m
clear, warning off

durumi2_init
x0 = [100;0;0;0;0;0;0;0.1;0;0;0;-500];

%% Specify the model name
model = 'durumi2_model';

%% Create the operating point specification object.
opspec = operspec(model);

%% Set the constraints on the states in the model.
% State (1) - durumi2_model/dynamic and kinematic mdel/I.C : x0

opspec.States(1).Known       = [1;1;0;  1;1;1;  0;0;0; 0;0;0];
opspec.States(1).SteadyState = [1;1;1;  1;1;1;  1;1;1; 0;1;1];

%% Set the constraints on the inputs in the model.
opspec.Inputs(1).u =     [0; 0; 0;0.5];
opspec.Inputs(1).Known = [0; 0; 0;  0];

%% Create the options
opt = findopOptions('DisplayReport','iter');

%% Perform the operating point search.
[op,opreport] = findop(model,opspec,opt);

% u=[de da dr df dth]
u0=op.Inputs.u;
x0=op.States.x;
u0',x0'

save durumi2_trim_100 x0 u0


%% Simulation for trim data verification
u_de=0; u_da=0; u_dr=0; u_th=0;
tout=sim('durumi2_sim.slx',15);

figure(1)
n=3; m=3; k=1;

subplot(n,m,k), k=k+1; plot(tout, y(:,1),   'LineWidth',1.5), ylabel('U(kts)'), grid
subplot(n,m,k), k=k+1; plot(tout, y(:,2),   'LineWidth',1.5), ylabel('V(kts)'), grid
subplot(n,m,k), k=k+1; plot(tout, y(:,3),   'LineWidth',1.5), ylabel('W(kts)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*y(:,4),   'LineWidth',1.5), ylabel('p(deg/sec)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*y(:,5),   'LineWidth',1.5), ylabel('q(deg/sec)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*y(:,6),   'LineWidth',1.5), ylabel('r(deg/sec)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*y(:,7),   'LineWidth',1.5), ylabel('phi(deg)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*y(:,8),   'LineWidth',1.5), ylabel('theta(deg)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*y(:,9),   'LineWidth',1.5), ylabel('psi(deg)'), grid
