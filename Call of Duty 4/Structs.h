#pragma once
#include <stdint.h>
#include "COD4Structs.h"

typedef float vec_t;
typedef float vec2_t[2];
typedef float vec3_t[3];
typedef float Matrix3x3[9];

enum CommandType {
	UnknownCmd0 = 0,
	UnknownCmd1 = 1,
	LowerLeft = 2,
	CenterScreen = 3,
	MiddleLeft = 4,

};

enum EntityStance { // Not consistent if player dies in a specific position it's set to baseline 2
	Standing = 0,   // Could do a function of -2 for each stance to get correct position if stance is equal to 2
	StandFiring = 64,
	Crouching = 4,
	CrouchFiring = 68,
	Prone = 8,
	ProneFiring = 72
};

enum EntityState {
	Normal = 0,
	Dead = 2,
	DeadPaused = 34,
	Aiming = 4,
	Paused = 32,
	AimingPaused = 36,
};

enum EntityValid {
	Valid = 2,
	Invalid = 1
};

enum PlayerUsingEquipment {
	Grenade = 2,
	NightVision = 64,
	GrenadeNightView = 66,
};

enum PlayerGameState { // Not useful for telling if a player is alive!!!
	Playing = 4, // 4 (Even if player is dead or alive)
	Spectator = 0,
	Spawning = 10, // Only used when spawning for the first time, or when going from spectator to game
};

enum PlayerPlayState {
	Active = 3,
	Spectating = 0,
};

enum DynamicEntTypes
{
	TYPE_GENERAL = 0,
	TYPE_PLAYER = 1,
	TYPE_PLAYER_CORPSE = 2,
	TYPE_ITEM = 3,
	TYPE_EXPLOSIVE = 4,
	TYPE_HELDWEAPON = 5,
	TYPE_VEHICLE = 6,
	TYPE_CLAYMORELASER = 8,
	TYPE_TURRET = 11,
	TYPE_HELICOPTER = 12,
	TYPE_HARRIER = 13, // This may not be accurate ( test before using in production ) 
	TYPE_UNKNOWN_ONE = 20, // Something to do with the airstrike ( harrier )
	TYPE_OLDEXPLOSIVE = 78,
};

struct CClient
{
	__int32 GameTime; //0x0000 
	char _0x0004[16];
	__int32 controlState; //0x0014 //4 Playing | 8 Spectator
	char _0x0018[4];
	vec3_t vOrigin; //0x001C 
	char _0x0028[4];
	vec3_t vVelocity; //0x002C 
	char _0x006C[188];
	float ADSPercent; //0x00F4 
	char _0x00F8[16];
	vec3_t vAngles; //0x0108 
	char _0x0110[56];
	__int32 Health; //0x0148 
	char _0x014C[4];
	__int32 MaxHealth; //0x0150
};

struct CGame
{
	int MaxNumPlayers; //0x0000
	char pad_0004[4]; //0x0004
	int GameTime; //0x0008
	char pad_000C[16]; //0x000C
	int AxisScore; //0x001C
	int AlliesScore; //0x0020
	char pad_0024[20]; //0x0024
	int NumOfPlayers; //0x0038
	int Scoreboard; //0x003C // This address is #1 scoreboard position. The offset of +0x4, is each consecutive player position.
}; //Size: 0x0040
 static CGame* pCGame = (CGame*)0x13E388C;

 class Entity
 {
 public:
	 int32_t ClientNum; //0x0000
	 int32_t N00007D61; //0x0004
	 int8_t EntityStance; //0x0008
	 int8_t N00007DB3; //0x0009
	 int8_t EntityState; //0x000A
	 int8_t N00007DB4; //0x000B
	 int32_t N00007D63; //0x000C
	 char pad_0010[8]; //0x0010
	 vec3_t vOrigin; //0x0018
	 char pad_0024[12]; //0x0024
	 int32_t N00007D6A; //0x0030
	 char pad_0034[8]; //0x0034
	 vec2_t vAngles; //0x003C
	 char pad_0044[56]; //0x0044
	 uint8_t onGround; //0x007C
	 int8_t PlayState; //0x007D
	 int8_t N00007DC1; //0x007E
	 int8_t N00007DBF; //0x007F
	 char pad_0080[68]; //0x0080
	 int32_t WeaponID; //0x00C4
	 char pad_00C8[44]; //0x00C8
	 int16_t N00007D9A; //0x00F4
	 int16_t Valid; //0x00F6
	 char pad_00F8[8]; //0x00F8
	 int32_t N00007D9D; //0x0100
	 char pad_0104[24]; //0x0104
	 float CameraHeight; //0x011C
	 char pad_0120[4]; //0x0120
	 vec3_t N00007DA6; //0x0124
	 vec3_t CameraPos; //0x0130
	 vec3_t OldPos; //0x013C
	 char pad_0148[4]; //0x0148
	 float Yaw; //0x014C
	 char pad_0150[12]; //0x0150
	 void* pEquipment; //0x015C
	 char pad_0160[8]; //0x0160
	 int16_t CurrentClass; //0x0168
	 int8_t N00007DE1; //0x016A
	 int8_t bAlive; //0x016B
	 int16_t N00007DD1; //0x016C
	 int16_t DeadOrAlive; //0x016E
	 char pad_0170[8]; //0x0170
	 int32_t TeamNum; //0x0178
	 char pad_017C[36]; //0x017C
	 int32_t Health; //0x01A0
 }; //Size: 0x01A4


class DynamicEntityList
{
public:
	int EntityCount; //0x0000
	int NumberOfPlayers; //0x0004
}; //Size: 0x4

class DynamicEntity
{
public:
	int EntityID; //0x0008
	int EntityType; //0x000C
	char pad_0010[16]; //0x0010
	vec3_t vOrigin; //0x0020
}; //Size: 0x4


//class CTrace
//{
//public:
//	float Fraction; //0
//	vec3_t endpos; //4
//	int SurfaceFlags; //10
//	int unknown; //14
//	char* SurfaceName; //18
//	int contents; //1C
//	short EntityNumber; //20
//};

//struct CTrace
//{
//	float Fraction;
//	vec3_t endpos;
//	int SurfaceFlags;
//	int unknown;
//	char* SurfaceName;
//	unsigned char szUnknown0[268];
//};

struct CTrace
{
	float Fraction;
	vec3_t normal;
	int surfaceFlags;
	int contents;
	char* material;
	TraceHitType hitType;
	unsigned char szUnknown0[264];
};

//class RefDef
//{
//public:
//	char pad_0000[8]; //0x0000
//	int Width; //0x0008
//	int Height; //0x000C
//	vec2_t FoV; //0x0010
//	vec3_t vCameraPos; //0x0018
//	vec3_t mViewMatrix[3]; //0x0024
//	vec3_t vCameraPos2; //0x0048
//	int GameTime; //0x0054
//	char pad_0058[284]; //0x0058
//}; //Size: 0x0174

class ViewAngles
{
public:
	vec2_t vViewAngles; //0x0000
}; //Size: 0x4

//==================TEMP==================
// THESE ARE TEMPORARY AND SHOULD NOT BE USED
//==================TEMP==================
#define _USE_MATH_DEFINES

#define	PITCH					0
#define YAW						1
#define	ROLL					2

#define ANGLE2SHORT(x)          ((int)((x) * 65536 / 360) & 65535)
#define SHORT2ANGLE(x)          ((x)*(360.0 / 65536))

#define	VectorScale(v, s, o)	((o)[0]=(v)[0]*(s),(o)[1]=(v)[1]*(s),(o)[2]=(v)[2]*(s))
#define VectorCopy(a,b)			((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2])

//ImGui copy
#define ImVec4Copy(i,v)	(v.x=i.x, v.y=i.y, v.z=i.z, v.w=i.w)

#define VectorSubtract(a,b,c)	((c)[0]=(a)[0]-(b)[0],(c)[1]=(a)[1]-(b)[1],(c)[2]=(a)[2]-(b)[2])
#define	VectorMA(v, s, b, o)	((o)[0]=(v)[0]+(b)[0]*(s),(o)[1]=(v)[1]+(b)[1]*(s),(o)[2]=(v)[2]+(b)[2]*(s))
#define DotProduct(x,y)			((x)[0]*(y)[0]+(x)[1]*(y)[1]+(x)[2]*(y)[2])


#define DegreesToRadians(a) ((a)*((float)M_PI/180.0f))
#define RadiansToDegrees(a) ((a)*(180.0f/(float)M_PI))
#define AngleNormalize(a) (SHORT2ANGLE(ANGLE2SHORT((a))))

#define ABS(x) ((x < 0) ? (-x) : (x))