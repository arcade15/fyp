function [ViconPose] = GetViconPose(u)
global MyClient;
global QuadRotationMatix;

while (MyClient.GetFrame().Result.Value) ~= (Result.Success)
	fprintf( '.' );
end 



% *********************************
% Quad1
% *********************************
% SubjectName = 'k1'; SegmentName = 'k1';

% X, Y, Z Global Coordinates of the Quad
Output_GetSegmentGlobalTranslation = MyClient.GetSegmentGlobalTranslation('K platform', 'K platform');
ViconPose(1) = Output_GetSegmentGlobalTranslation.Translation(1);  % X-coordinate
ViconPose(2) = Output_GetSegmentGlobalTranslation.Translation(2);  % Y-coordinate
ViconPose(3) = Output_GetSegmentGlobalTranslation.Translation(3);  % Z-coordinate

% Euler Angles
QuadEulerXYZ = MyClient.GetSegmentGlobalRotationEulerXYZ('K platform', 'K platform');
ViconPose(4) = QuadEulerXYZ.Rotation(1); % Roll
ViconPose(5) = QuadEulerXYZ.Rotation(2); % Pitch
ViconPose(6) = QuadEulerXYZ.Rotation(3); % Yaw

% *********************************
% Platform1
% *********************************
% SubjectName = 'p1'; SegmentName = 'p1';

% X, Y, Z Global Coordinates of the Quad
Output_GetSegmentGlobalTranslation = MyClient.GetSegmentGlobalTranslation('test', 'test');
ViconPose(7) = Output_GetSegmentGlobalTranslation.Translation(1);  % X-coordinate
ViconPose(8) = Output_GetSegmentGlobalTranslation.Translation(2);  % Y-coordinate
ViconPose(9) = Output_GetSegmentGlobalTranslation.Translation(3);  % Z-coordinate

% Euler Angles
QuadEulerXYZ = MyClient.GetSegmentGlobalRotationEulerXYZ('test', 'test');
ViconPose(10) = QuadEulerXYZ.Rotation(1); % Roll
ViconPose(11) = QuadEulerXYZ.Rotation(2); % Pitch
ViconPose(12) = QuadEulerXYZ.Rotation(3); % Yaw

% *********************************
% Quad2
% *********************************
% SubjectName = 'k2'; SegmentName = 'k2';

% X, Y, Z Global Coordinates of the Quad
Output_GetSegmentGlobalTranslation = MyClient.GetSegmentGlobalTranslation('AS_330_1', 'AS_330_1');
ViconPose(13) = Output_GetSegmentGlobalTranslation.Translation(1);  % X-coordinate
ViconPose(14) = Output_GetSegmentGlobalTranslation.Translation(2);  % Y-coordinate
ViconPose(15) = Output_GetSegmentGlobalTranslation.Translation(3);  % Z-coordinate

% Euler Angles
QuadEulerXYZ = MyClient.GetSegmentGlobalRotationEulerXYZ('AS_330_1', 'AS_330_1');
ViconPose(16) = QuadEulerXYZ.Rotation(1); % Roll
ViconPose(17) = QuadEulerXYZ.Rotation(2); % Pitch
ViconPose(18) = QuadEulerXYZ.Rotation(3); % Yaw

% *********************************
% Platform2
% *********************************
% SubjectName = 'p2'; SegmentName = 'p2';

% X, Y, Z Global Coordinates of the Quad
Output_GetSegmentGlobalTranslation = MyClient.GetSegmentGlobalTranslation('AS_330_2', 'AS_330_2');
ViconPose(19) = Output_GetSegmentGlobalTranslation.Translation(1);  % X-coordinate
ViconPose(20) = Output_GetSegmentGlobalTranslation.Translation(2);  % Y-coordinate
ViconPose(21) = Output_GetSegmentGlobalTranslation.Translation(3);  % Z-coordinate

% Euler Angles
QuadEulerXYZ = MyClient.GetSegmentGlobalRotationEulerXYZ('AS_330_2', 'AS_330_2');
ViconPose(22) = QuadEulerXYZ.Rotation(1); % Roll
ViconPose(23) = QuadEulerXYZ.Rotation(2); % Pitch
ViconPose(24) = QuadEulerXYZ.Rotation(3); % Yaw

% *********************************
% Quad2
% *********************************
% SubjectName = 'k2'; SegmentName = 'k2';

% X, Y, Z Global Coordinates of the Quad
Output_GetSegmentGlobalTranslation = MyClient.GetSegmentGlobalTranslation('AS_330_3', 'AS_330_3');
ViconPose(25) = Output_GetSegmentGlobalTranslation.Translation(1);  % X-coordinate
ViconPose(26) = Output_GetSegmentGlobalTranslation.Translation(2);  % Y-coordinate
ViconPose(27) = Output_GetSegmentGlobalTranslation.Translation(3);  % Z-coordinate

% Euler Angles
QuadEulerXYZ = MyClient.GetSegmentGlobalRotationEulerXYZ('AS_330_3', 'AS_330_3');
ViconPose(28) = QuadEulerXYZ.Rotation(1); % Roll
ViconPose(29) = QuadEulerXYZ.Rotation(2); % Pitch
ViconPose(30) = QuadEulerXYZ.Rotation(3); % Yaw

% *********************************
% Platform2
% *********************************
% SubjectName = 'p2'; SegmentName = 'p2';

% X, Y, Z Global Coordinates of the Quad
Output_GetSegmentGlobalTranslation = MyClient.GetSegmentGlobalTranslation('AS_330_4', 'AS_330_4');
ViconPose(31) = Output_GetSegmentGlobalTranslation.Translation(1);  % X-coordinate
ViconPose(32) = Output_GetSegmentGlobalTranslation.Translation(2);  % Y-coordinate
ViconPose(33) = Output_GetSegmentGlobalTranslation.Translation(3);  % Z-coordinate

% Euler Angles
QuadEulerXYZ = MyClient.GetSegmentGlobalRotationEulerXYZ('AS_330_4', 'AS_330_4');
ViconPose(34) = QuadEulerXYZ.Rotation(1); % Roll
ViconPose(35) = QuadEulerXYZ.Rotation(2); % Pitch
ViconPose(36) = QuadEulerXYZ.Rotation(3); % Yaw

end 



