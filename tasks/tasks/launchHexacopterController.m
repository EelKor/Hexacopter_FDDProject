function launchHexacopterController
%

%   Copyright 2021 The MathWorks, Inc.

    project = simulinkproject;
    projectRoot = project.RootFolder;
    open_system(fullfile(projectRoot,'controller','Hexacopter_ControllerWithNavigation.slx'));
end
