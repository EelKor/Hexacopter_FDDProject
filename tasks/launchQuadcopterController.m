function launchQuadcopterController
%

%   Copyright 2021 The MathWorks, Inc.
    evalin('base', 'InitQuadcopterControllerVars;');
    %evalin('base', 'InitHexacopterControllerVars;');
    project = simulinkproject;
    projectRoot = project.RootFolder;
    open_system(fullfile(projectRoot,'controller','Quadcopter_ControllerWithNavigation.slx'));
end
