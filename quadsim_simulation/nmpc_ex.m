i = 0:100;
x0 = 0;
rN = 10;
a = 0.99;
b = 0.1;
N=100;

[x, u] = scoptco_fixed(a, b, 0, N, x0, 10);
[x1, u1] = scoptco_fixed(a, b, 0.1, N, x0, 8.2);
[x2, u2] = scoptco_fixed(a, b, 0.5, N, x0, 4.8);
[x3, u3] = scoptco_fixed(a, b, 1, N, x0, 3);
[x4, u4] = scoptco_fixed(a, b, 10, N, x0, 0.45);
figure
plot(i, x, i, x1, i, x2, i, x3, i, x4)
legend({'r = 0','r = 0.1','r = 0.5','r = 1','r = 10'},'Location','northwest')
xlabel('iteration number k')
ylabel('optimal state trajectory x*')
title('fixed-final-state problem')

[x5, u5] = scoptco_free(a, b, exp(-10), N, x0, rN);
[x6, u6] = scoptco_free(a, b, 0.1, N, x0, rN);
[x7, u7] = scoptco_free(a, b, 0.5, N, x0, rN);
[x8, u8] = scoptco_free(a, b, 1, N, x0, rN);
[x9, u9] = scoptco_free(a, b, 10, N, x0, rN);
figure
plot(i, u5, i, u6, i, u7, i, u8, i, u9)
legend({'r = 0','r = 0.1','r = 0.5','r = 1','r = 10'},'Location','northwest')
xlabel('iteration number k')
ylabel('optimal control input u*')
title('free-final-state problem')

function [x, u] =scoptco_fixed (a, b, r, N, x0, rN)
% Simulation of Optimal Control for Scalar Systems
% Fixed Final State Case
x(1) =x0;
alam= (1-a^(2*N)) / (1-a^2); alam=alam*b^2;
u(1) =b*(rN-x(1)*a^N)*a^N/ (alam);
u(1) =u(1) / a;
    for k=1:N
    % Update the Plant State
        x(k+1)=a*x(k) +b*u(k);
    % Update the Optimal Control Input
        u(k+1) =u(k) /a;
    end
end

function [x, u]=scoptco_free (a, b, r, N, x0, rN)
% Simulation of Optimal Control for Scalar Systems
% Free Final State Case
x(1) =x0;
alam=(1-a^(2*N)) / (1-a^2); alam=alam*b^2/r;
u(1) =b*(rN-x(1)*a^N)*a^N/ (r*(alam+1));
u(1) =u(1) /a;
    for k=1:N
    % Update the Plant State
        x(k+1) =a*x(k) +b*u(k);
    % Update the Optimal Control Input
        u(k+1) =u(k) /a;
    end
end



