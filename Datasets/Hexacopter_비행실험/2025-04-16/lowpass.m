function [x_lpf] = lowpass(x,alpha)
% Low pass Filter
%   y_k = alpha*x_k-1 + (1-alpha)*x_k
x_lpf = zeros(1,length(x));
for i = 2:length(x)
    x_lpf(i) = alpha*x(i-1) + (1-alpha)*x(i);
end
