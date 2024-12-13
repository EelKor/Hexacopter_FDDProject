%% partial_f/partial_X : Jacobian of system eqn
function F = EKF1_fn_JF(x,u)
%% Parameters
dt = 1/250; % [s] Sample time
m = 41.97;                 % kg
g = 9.81;

Ixx = 1.3 * 8.094;       % kg*m^2
Iyy = 1.3 * 9.125;       % kg*m^2
Izz = 1.3 * 16.8615;   % kg*m^2
% Ixz = -1.3 * 0.308;      % kg*m^2 -> 생략함

% dx1 = 0.9815; dx2 = 0.0235; dx3 = 1.1235;  % 정확한 모델정보
dx1 = 1.0525; dx2 = 0; dx3 = 1.0525;             % PWM 실제값과의 차이를 줄이기 위해 대칭으로 가정함
dy1 = 0.717;   dy2 = dy1;

Tr = 0.1;            % (가정) Motor and rotor time constant [sec]
%% EKF states
p = x(1);
q = x(2);
r = x(3);
w = x(4:9);
%% 추력방정식 미분식
K = 9.81/1000;                                                  % 단위([g] -> [N])와 PWM 0~1 사이로 정규화하기위해 곱해진 텀
a = -19281; b = 36503; c = -992.75;               % 추력 테스트 결과 방정식의 계수

dTdw1 = K*( 3*a*w(1)^2 + 2*b*w(1) + c);
dTdw2 = K*( 3*a*w(2)^2 + 2*b*w(2) + c);
dTdw3 = K*( 3*a*w(3)^2 + 2*b*w(3) + c);
dTdw4 = K*( 3*a*w(4)^2 + 2*b*w(4) + c);
dTdw5 = K*( 3*a*w(5)^2 + 2*b*w(5) + c);
dTdw6 = K*( 3*a*w(6)^2 + 2*b*w(6) + c);

%% 토크방정식 미분식
A = -6.3961; B = 12.092; C = -0.3156;           % 토크 테스트 결과 방정식의 계수

dtdw1 = 3*A*w(1)^2 + 2*B*w(1) + C;
dtdw2 = 3*A*w(2)^2 + 2*B*w(2) + C;
dtdw3 = 3*A*w(3)^2 + 2*B*w(3) + C;
dtdw4 = 3*A*w(4)^2 + 2*B*w(4) + C;
dtdw5 = 3*A*w(5)^2 + 2*B*w(5) + C;
dtdw6 = 3*A*w(6)^2 + 2*B*w(6) + C;

%%
A = zeros(9,9);

A(1,1) = 0;
A(1,2) = 1/Ixx*( (Iyy-Izz)*r );
A(1,3) = 1/Ixx*( (Iyy-Izz)*q );
A(1,4) = 1/Ixx*( -dy2*dTdw1 );
A(1,5) = 1/Ixx*(  dy1*dTdw2 );
A(1,6) = 1/Ixx*(  dy1*dTdw3 ); 
A(1,7) = 1/Ixx*( -dy2*dTdw4 );
A(1,8) = 1/Ixx*( -dy2*dTdw5 );
A(1,9) = 1/Ixx*(  dy1*dTdw6 );

A(2,1) = 1/Iyy*( (Izz-Ixx)*r );
A(2,2) = 0;
A(2,3) = 1/Iyy*( (Izz-Ixx)*p );
A(2,4) = 1/Iyy*( -dx2*dTdw1 );
A(2,5) = 1/Iyy*( -dx2*dTdw2 );
A(2,6) = 1/Iyy*(  dx1*dTdw3 );
A(2,7) = 1/Iyy*( -dx3*dTdw4 );
A(2,8) = 1/Iyy*(  dx1*dTdw5 );
A(2,9) = 1/Iyy*( -dx3*dTdw6 );

A(3,1) = 1/Izz*( (Ixx-Iyy)*q );
A(3,2) = 1/Izz*( (Ixx-Iyy)*p );
A(3,3) = 0;
A(3,4) = 1/Izz*( -dtdw1 );
A(3,5) = 1/Izz*(  dtdw2 );
A(3,6) = 1/Izz*( -dtdw3 );
A(3,7) = 1/Izz*(  dtdw4 );
A(3,8) = 1/Izz*(  dtdw5 );
A(3,9) = 1/Izz*( -dtdw6 );

A(4,4) = -1/Tr;
A(5,5) = -1/Tr;
A(6,6) = -1/Tr;
A(7,7) = -1/Tr;
A(8,8) = -1/Tr;
A(9,9) = -1/Tr;

F = eye(9,9) + A*dt;