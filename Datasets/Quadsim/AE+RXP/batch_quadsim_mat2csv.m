% batch_quadsim_mat2csv.m

% 현재 작업 디렉토리의 모든 .mat 파일 목록 가져오기
matFiles = dir('*.mat');

% .mat 파일이 있는지 확인
if isempty(matFiles)
    disp('현재 디렉토리에 .mat 파일이 없습니다.');
else
    % 각 .mat 파일에 대해 quadsim_mat2csv 함수 실행
    for k = 1:length(matFiles)
        % 현재 파일명 추출
        matFileName = matFiles(k).name;
        
        % 함수 호출 (필요 시 전체 경로를 지정할 수 있습니다)
        try
            quadsim_mat2csv(matFileName);
            fprintf('성공적으로 처리되었습니다: %s\n', matFileName);
        catch ME
            fprintf('처리 중 오류 발생: %s\n', matFileName);
            fprintf('오류 메시지: %s\n', ME.message);
        end
    end
    disp('모든 .mat 파일에 대한 처리가 완료되었습니다.');
end
