%% h(x) : nonlinear measurement eqn
% 수업시간에 배웠던 accelerometer와 gyroscope를 이용한 자세 추정 문제에서 
% measurement eqn은 본래 선형이지만 EKF block을 사용하기위해 추가한 함수
function y = EKF2_fn_hx(x)
phi   = x(1);
theta = x(2);

y = zeros(2,1);
y(1) = 1*phi;
y(2) = 1*theta;

end