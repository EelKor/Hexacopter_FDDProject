clear; clc; close all;

run ../F550_data.m
x0 = [0 0 0 0 0 0 0 0 0 0 0 -100]; % initial Condition

%% Run Simulation
out = sim("F550_CompareCA.slx");

%% Plot 
% pinvCA_states =
% [ u,v,w,p,q,r,phi,theta,psi,x,y,z] 1x12 vector

% pinvCA_cmd = 
% [p_sp, q_sp, r_sp, phi_sp, theta_sp, w_sp, z_sp] 1x7 vector

label_states = {'u','v','w','p','q','r','phi','theta','psi','x','y','z'};
label_cmds = {'p_sp','q_sp','r_sp','phi_sp','theta_sp','w_sp','z_sp'};
label_cmds_index = {0,0,6,1,2,3,4,5,0,0,0,7};

%% Plot psuedo-inverse CA
figure;
for i = 1:12
    subplot(4,3,i);
    
    % 셀 배열의 내용을 중괄호 {}로 접근
    current_state = label_states{i};
    current_cmd_index = label_cmds_index{i};
    
    % 상태 데이터 플롯
    plot(out.tout, out.pinvCA_states(:,i), 'b', 'DisplayName', 'State');
    hold on;
    grid on;
    
    % 명령 데이터가 0이 아닌 경우 플롯
    if ~(current_cmd_index == 0)
        plot(out.tout, out.pinvCA_cmd(:,label_cmds_index{i}), 'r--', 'DisplayName', 'Command');
    end
    
    % 제목 설정
    title(current_state);
    
    % 범례 추가
    legend('show');
    
    hold off;
end
sgtitle("Psuedo-Inverse CA")
%% Plot quadratic programming CA
figure;
for i = 1:12
    subplot(4,3,i);
    
    % 셀 배열의 내용을 중괄호 {}로 접근
    current_state = label_states{i};
    current_cmd_index = label_cmds_index{i};
    
    % 상태 데이터 플롯
    plot(out.tout, out.qpCA_states(:,i), 'b', 'DisplayName', 'State');
    hold on;
    grid on;
    
    % 명령 데이터가 0이 아닌 경우 플롯
    if ~(current_cmd_index == 0)
        plot(out.tout, out.qpCA_cmd(:,label_cmds_index{i}), 'r--', 'DisplayName', 'Command');
    end
    
    % 제목 설정
    title(current_state);
    
    % 범례 추가
    legend('show');
    
    hold off;
end
sgtitle("Quadratic Programming CA")

figure;
plot(out.tout, out.qpCA_rpms);
title("Quadratic Programming CA - RPMS")

%% Plot Static Mixer CA
figure;
for i = 1:12
    subplot(4,3,i);
    
    % 셀 배열의 내용을 중괄호 {}로 접근
    current_state = label_states{i};
    current_cmd_index = label_cmds_index{i};
    
    % 상태 데이터 플롯
    plot(out.tout, out.staticCA_states(:,i), 'b', 'DisplayName', 'State');
    hold on;
    grid on;
    
    % 명령 데이터가 0이 아닌 경우 플롯
    if ~(current_cmd_index == 0)
        plot(out.tout, out.staticCA_cmd(:,label_cmds_index{i}), 'r--', 'DisplayName', 'Command');
    end
    
    % 제목 설정
    title(current_state);
    
    % 범례 추가
    legend('show');
    
    hold off;
end
sgtitle("Static Mixer CA")
