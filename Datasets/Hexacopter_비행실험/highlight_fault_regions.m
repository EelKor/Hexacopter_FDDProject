function highlight_fault_regions(time_vector, data_vector, threshold, color)
% 고장 구간을 patch로 시각화 (time_vector는 duration도 허용)

    % 시간 벡터가 duration이나 datetime이면 초 단위로 변환
    if isduration(time_vector)
        time_vector = seconds(time_vector);
    elseif isdatetime(time_vector)
        time_vector = seconds(time_vector - time_vector(1));  % datetime을 duration으로 변경
    end

    % 고장 여부
    flag = data_vector > threshold;

    % 고장 시작과 끝 인덱스
    start_idx = find(diff([0; flag]) == 1);
    end_idx   = find(diff([flag; 0]) == -1);

    hold on;
    ylims = get(gca, 'YLim');  % y축 범위

    % 고장 구간 patch 표시
    for i = 1:length(start_idx)
        x1 = time_vector(start_idx(i));
        x2 = time_vector(end_idx(i));
        h_patch = patch([x1 x2 x2 x1], [ylims(1) ylims(1) ylims(2) ylims(2)], ...
                        color, 'FaceAlpha', 0.2, 'EdgeColor', 'none');
        % 👇 legend에서 제외
        h_patch.Annotation.LegendInformation.IconDisplayStyle = 'off';
    end

    
end