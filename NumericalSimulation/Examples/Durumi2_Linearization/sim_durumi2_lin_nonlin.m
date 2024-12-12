% sim_durumi2_lin_nonlin.m

clear
warning off

% Load aircraft data
durumi2_init
load durumi2_trim_100 
load durumi2_linmodel_100

sim_model='durumi2_comp_lin_nonlin.slx';

% Control Inputs
u_de=2;     
u_da=2;     
u_dr=2;     
u_th=0.1;   

% Simulation
simout=sim(sim_model,20);

%% plot 
y1   = Lin + x0(1:9)';
y2   = NonLin;
tout=simout;

figure(1)
n=3; m=3; k=1;

subplot(n,m,k), k=k+1; plot(tout, [y1(:,1)  y2(:,1)],   'LineWidth',1.5), ylabel('U(kts)'), grid, legend('Linear','NonLinear')
subplot(n,m,k), k=k+1; plot(tout, [y1(:,2)  y2(:,2)],   'LineWidth',1.5), ylabel('V(kts)'), grid
subplot(n,m,k), k=k+1; plot(tout, [y1(:,3)  y2(:,3)],   'LineWidth',1.5), ylabel('W(kts)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*[y1(:,4) y2(:,4)], 'LineWidth',1.5), ylabel('p(deg/sec)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*[y1(:,5) y2(:,5)], 'LineWidth',1.5), ylabel('q(deg/sec)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*[y1(:,6) y2(:,6)], 'LineWidth',1.5), ylabel('r(deg/sec)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*[y1(:,7) y2(:,7)], 'LineWidth',1.5), ylabel('phi(deg)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*[y1(:,8) y2(:,8)], 'LineWidth',1.5), ylabel('theta(deg)'), grid
subplot(n,m,k), k=k+1; plot(tout, 57.3*[y1(:,9) y2(:,9)], 'LineWidth',1.5), ylabel('psi(deg)'), grid

