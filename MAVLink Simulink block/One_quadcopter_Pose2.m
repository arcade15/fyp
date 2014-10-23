function [ViconPose] = GetViconPose(u)
global MyClient;
global QuadRotationMatix;

while (MyClient.GetFrame().Result.Value) ~= (Result.Success)
	fprintf( '.' );
end 



% *********************************
% Testa
% *********************************


% X, Y, Z Global Coordinates of the Quad
Output_GetSegmentGlobalTranslation = MyClient.GetSegmentGlobalTranslation('0811V1', '0811V1');
ViconPose(1) = Output_GetSegmentGlobalTranslation.Translation(1);  % X-coordinate
ViconPose(2) = Output_GetSegmentGlobalTranslation.Translation(2);  % Y-coordinate
ViconPose(3) = Output_GetSegmentGlobalTranslation.Translation(3);  % Z-coordinate

% Euler Angles
QuadEulerXYZ = MyClient.GetSegmentGlobalRotationEulerXYZ('0811V1', '0811V1');
ViconPose(4) = QuadEulerXYZ.Rotation(1); % Roll
ViconPose(5) = QuadEulerXYZ.Rotation(2); % Pitch
ViconPose(6) = QuadEulerXYZ.Rotation(3); % Yaw

% *********************************
% 1st Marker
% *********************************


% X, Y, Z Global Coordinates of the Marker
Output_GetMarkerGlobalTranslation = MyClient.GetMarkerGlobalTranslation('0811V1', 'First');
ViconPose(7) = Output_GetMarkerGlobalTranslation('0811V1', 'First');
ViconPose(8) = Output_GetMarkerGlobalTranslation('0811V1', 'First');
ViconPose(9) = Output_GetMarkerGlobalTranslation('0811V1', 'First');

% *********************************
% 2nd Marker
% *********************************


% X, Y, Z Global Coordinates of the Marker
Output_GetMarkerGlobalTranslation = MyClient.GetMarkerGlobalTranslation('0811V1', 'Second');
ViconPose(10) = Output_GetMarkerGlobalTranslation('0811V1', 'Second');
ViconPose(11) = Output_GetMarkerGlobalTranslation('0811V1', 'Second');
ViconPose(12) = Output_GetMarkerGlobalTranslation('0811V1', 'Second');

% *********************************
% 3nd Marker
% *********************************


% X, Y, Z Global Coordinates of the Marker
Output_GetMarkerGlobalTranslation = MyClient.GetMarkerGlobalTranslation('0811V1', 'Third');
ViconPose(13) = Output_GetMarkerGlobalTranslation('0811V1', 'Third');
ViconPose(14) = Output_GetMarkerGlobalTranslation('0811V1', 'Third');
ViconPose(15) = Output_GetMarkerGlobalTranslation('0811V1', 'Third');



end 



