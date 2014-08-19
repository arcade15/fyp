function [ViconPose] = GetViconPose(u)
global MyClient;
global QuadRotationMatix;

while (MyClient.GetFrame().Result.Value) ~= (Result.Success)
	fprintf( '.' );
end 



% *********************************
% trial1
% *********************************


% X, Y, Z Global Coordinates of the Quad
Output_GetSegmentGlobalTranslation = MyClient.GetSegmentGlobalTranslation('trial1', 'trial1');
ViconPose(1) = Output_GetSegmentGlobalTranslation.Translation(1);  % X-coordinate
ViconPose(2) = Output_GetSegmentGlobalTranslation.Translation(2);  % Y-coordinate
ViconPose(3) = Output_GetSegmentGlobalTranslation.Translation(3);  % Z-coordinate

% Euler Angles
QuadEulerXYZ = MyClient.GetSegmentGlobalRotationEulerXYZ('trial1', 'trial1');
ViconPose(4) = QuadEulerXYZ.Rotation(1); % Roll
ViconPose(5) = QuadEulerXYZ.Rotation(2); % Pitch
ViconPose(6) = QuadEulerXYZ.Rotation(3); % Yaw


% *********************************
% trial2
% *********************************


% X, Y, Z Global Coordinates of the Quad
Output_GetSegmentGlobalTranslation = MyClient.GetSegmentGlobalTranslation('trial2', 'trial2');
ViconPose(7) = Output_GetSegmentGlobalTranslation.Translation(1);  % X-coordinate
ViconPose(8) = Output_GetSegmentGlobalTranslation.Translation(2);  % Y-coordinate
ViconPose(9) = Output_GetSegmentGlobalTranslation.Translation(3);  % Z-coordinate

% Euler Angles
QuadEulerXYZ = MyClient.GetSegmentGlobalRotationEulerXYZ('trial2', 'trial2');
ViconPose(10) = QuadEulerXYZ.Rotation(1); % Roll
ViconPose(11) = QuadEulerXYZ.Rotation(2); % Pitch
ViconPose(12) = QuadEulerXYZ.Rotation(3); % Yaw

% *********************************
% trial3
% *********************************


% X, Y, Z Global Coordinates of the Quad
Output_GetSegmentGlobalTranslation = MyClient.GetSegmentGlobalTranslation('trial3', 'trial3');
ViconPose(13) = Output_GetSegmentGlobalTranslation.Translation(1);  % X-coordinate
ViconPose(14) = Output_GetSegmentGlobalTranslation.Translation(2);  % Y-coordinate
ViconPose(15) = Output_GetSegmentGlobalTranslation.Translation(3);  % Z-coordinate

% Euler Angles
QuadEulerXYZ = MyClient.GetSegmentGlobalRotationEulerXYZ('trial3', 'trial3');
ViconPose(16) = QuadEulerXYZ.Rotation(1); % Roll
ViconPose(17) = QuadEulerXYZ.Rotation(2); % Pitch
ViconPose(18) = QuadEulerXYZ.Rotation(3); % Yaw


% *********************************
% trial4
% *********************************

% X, Y, Z Global Coordinates of the Quad
Output_GetSegmentGlobalTranslation = MyClient.GetSegmentGlobalTranslation('trial4', 'trial4');
ViconPose(19) = Output_GetSegmentGlobalTranslation.Translation(1);  % X-coordinate
ViconPose(20) = Output_GetSegmentGlobalTranslation.Translation(2);  % Y-coordinate
ViconPose(21) = Output_GetSegmentGlobalTranslation.Translation(3);  % Z-coordinate

% Euler Angles
QuadEulerXYZ = MyClient.GetSegmentGlobalRotationEulerXYZ('trial4', 'trial4');
ViconPose(22) = QuadEulerXYZ.Rotation(1); % Roll
ViconPose(23) = QuadEulerXYZ.Rotation(2); % Pitch
ViconPose(24) = QuadEulerXYZ.Rotation(3); % Yaw

end 



