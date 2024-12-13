%% f(x) : Nonlinear states eqn
function f = EKF1_fn_fx(x,u)
% x = [p q r, w1 w2 w3 w4 w5 w6]'
% u = [w1, w2, w3, w4, w5, w6]' : RPMs
%% Parameters
dt = 1/250;            % [s] Sample time
% dt = 1/500;
m = 41.97;                 % kg
g = 9.81;

Ixx = 1.3 * 8.094;       % kg*m^2
Iyy = 1.3 * 9.125;       % kg*m^2
Izz = 1.3 * 16.8615;   % kg*m^2
% Ixz = -1.3 * 0.308;      % kg*m^2 -> 생략함

% dx1 = 0.9815; dx2 = 0.0235; dx3 = 1.1235;  % 정확한 모델정보
dx1 = 1.0525; dx2 = 0; dx3 = 1.0525;             % PWM 실제값과의 차이를 줄이기 위해 대칭으로 가정함
dy1 = 0.717;   dy2 = dy1;

Tr = 0.1;                     % (가정) Motor and rotor time constant [sec]
%% EKF States
p = x(1);
q = x(2);
r = x(3);
w = x(4:9);
%% Thrust-PWM relationship
K = 9.81/1000;                                                  % 단위([g] -> [N])와 PWM 0~1 사이로 정규화하기위해 곱해진 텀
a = -19281; b = 36503; c = -992.75;               % 추력 테스트 결과 방정식의 계수

T1 = K*(a*w(1)^3 + b*w(1)^2 + c*w(1));
T2 = K*(a*w(2)^3 + b*w(2)^2 + c*w(2));
T3 = K*(a*w(3)^3 + b*w(3)^2 + c*w(3));
T4 = K*(a*w(4)^3 + b*w(4)^2 + c*w(4));
T5 = K*(a*w(5)^3 + b*w(5)^2 + c*w(5));
T6 = K*(a*w(6)^3 + b*w(6)^2 + c*w(6));

%% Torque-PWM relationship
A = -6.3961; B = 12.092; C = -0.3156;           % 토크 테스트 결과 방정식의 계수

tau1 = A*w(1)^3 + B*w(1)^2 + C*w(1);
tau2 = A*w(2)^3 + B*w(2)^2 + C*w(2);
tau3 = A*w(3)^3 + B*w(3)^2 + C*w(3);
tau4 = A*w(4)^3 + B*w(4)^2 + C*w(4);
tau5 = A*w(5)^3 + B*w(5)^2 + C*w(5);
tau6 = A*w(6)^3 + B*w(6)^2 + C*w(6);

%% Control Moment
Mx = dy1*(T3 + T2 + T6) - dy2*(T5 + T1 + T4);
My = dx1*(T3 + T5) - dx2*(T1 + T2) -dx3*(T4 + T6);
Mz = - tau1 + tau2 - tau3 + tau4 + tau5 - tau6;

%% Continuous system
xdot = zeros(9,1);
xdot(1) = 1/Ixx*( (Iyy-Izz)*q*r + Mx );
xdot(2) = 1/Iyy*( (Izz-Ixx)*p*r + My);
xdot(3) = 1/Izz*( (Ixx-Iyy)*p*q + Mz);

xdot(4) = -1/Tr*( w(1) - u(1) );
xdot(5) = -1/Tr*( w(2) - u(2) );
xdot(6) = -1/Tr*( w(3) - u(3) );
xdot(7) = -1/Tr*( w(4) - u(4) );
xdot(8) = -1/Tr*( w(5) - u(5) );
xdot(9) = -1/Tr*( w(6) - u(6) );
%% Discrete system
f = x + xdot*dt;
end