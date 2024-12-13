%% h(x) : nonlinear measurement eqn
% �����ð��� ����� accelerometer�� gyroscope�� �̿��� �ڼ� ���� �������� 
% measurement eqn�� ���� ���������� EKF block�� ����ϱ����� �߰��� �Լ�
function y = EKF2_fn_hx(x)
phi   = x(1);
theta = x(2);

y = zeros(2,1);
y(1) = 1*phi;
y(2) = 1*theta;

end