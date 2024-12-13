%% partial_f/partial_X : Jacobian of system eqn
% 수업시간에 배웠던 accelerometer와 gyroscope를 이용한 자세 추정 문제에서 
% measurement eqn은 본래 선형이지만 EKF block을 사용하기위해 추가한 함수
function H = EKF2_fn_JH(x)
phi   = x(1);
theta = x(2);

H = [
    1 0 0
    0 1 0
    ];