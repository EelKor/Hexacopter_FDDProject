%% partial_f/partial_X : Jacobian of system eqn
% �����ð��� ����� accelerometer�� gyroscope�� �̿��� �ڼ� ���� �������� 
% measurement eqn�� ���� ���������� EKF block�� ����ϱ����� �߰��� �Լ�
function H = EKF2_fn_JH(x)
phi   = x(1);
theta = x(2);

H = [
    1 0 0
    0 1 0
    ];