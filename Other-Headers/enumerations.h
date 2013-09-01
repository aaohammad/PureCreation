#ifndef ENUMERATIONS_H
#define ENUMERATIONS_H

enum WhichHandleIsNowActive
{
	ScaleStateActivated,
	MoveStateActivated,
	RotateStateActivated,
	NothingActivated
};

enum DrawingModes
{
	VertexMode,
	ObjectMode,
	FaceMode
};

enum CommandErrorType
{
	StructuralErrorInCommand,
	NoCommandToExecute,
	ErrorInCloseingParenthesis,
	ArgumentsAreNotEnough,
	EnteredArgumentIsNotNumber,
	ExecuteSuccessful,
	ModelNotFound
};

enum LightType
{
	PointLight,
	DirectionalLight,
	SpotLight
};

enum ThreeDDrawing
{
	HeightNotSet,
	WidthNotSet,
	LengthNotSet
};

#endif // ENUMERATIONS_H
