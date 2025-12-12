%% f(x) : nonlinear states eqn
function f = EKF2_fn_fx(x,rates)
dt = 1/250;    % [s] Sample time
phi   = x(1);
theta = x(2);

p = rates(1);
q = rates(2);
r = rates(3);
%% Continuous system
xdot = zeros(3,1);
xdot(1) = p + q*sin(phi)*tan(theta) + r*cos(phi)*tan(theta);
xdot(2) =     q*cos(phi)            - r*sin(phi);
xdot(3) =     q*sin(phi)*sec(theta) + r*cos(phi)*sec(theta);

%% Discrete system
f = x + xdot*dt;     % Euler integration