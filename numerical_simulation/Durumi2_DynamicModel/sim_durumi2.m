%% cal_trim_durumi2.m
clear

durumi2_init

load durumi2_trim_100 

%% Specify the model name
model = 'durumi2_model';

%% Simulation for trim data verification
u_de=0; u_da=0.; u_dr=0.1; u_th=0;
tout=sim('durumi2_sim.slx',50);


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
shg