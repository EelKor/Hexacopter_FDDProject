function J = myMeasurementJacobian(x)
m = 1.023;
ct = 1.4865e-07;
w = x(4:9);
h = x(10:15);

J = zeros(4,15);
J(1,1) = 1;
J(2,2) = 1;
J(3,3) = 1;

J(4,:) = [0,0,0,...
    2*ct/m*h(1)*w(1),2*ct/m*h(2)*w(2),2*ct/m*h(3)*w(3),...
    2*ct/m*h(4)*w(4),2*ct/m*h(5)*w(5),2*ct/m*h(6)*w(6),...
    ct/m*w(1)^2,ct/m*w(2)^2,ct/m*w(3)^2,ct/m*w(4)^2,ct/m*w(5)^2,ct/m*w(6)^2
    ];
    

