#include "sqrat.h"
#include "squirrel.h"
//#pragma comment(lib,"squirrelD.lib")
//#pragma comment(lib,"sqstdlibD.lib")
//#pragma comment(lib,"sqplusD.lib")

using namespace Sqrat;

#include "cg_local.h"

HSQUIRRELVM vm;

int RegisterEffect(const char* path)
{
	return trap_FX_RegisterEffect(path);
}

int RegisterSound(const char* path)
{
	return trap_S_RegisterSound(path);
}

int RegisterModel(const char* path)
{
	return trap_R_RegisterModel(path);
}

class E11Test
{
public:
	static void SetMuzzleEffect(fxHandle_t fx)
	{
		cg_weapons[WP_BLASTER].muzzleEffect = fx;
	}

	static void SetSelectSound(sfxHandle_t sfx)
	{
		cg_weapons[WP_BLASTER].selectSound = sfx;
	}

	static void SetFlashSound(sfxHandle_t sfx)
	{
		cg_weapons[WP_BLASTER].flashSound = sfx;
	}

	static void SetFiringSound(sfxHandle_t sfx)
	{
		cg_weapons[WP_BLASTER].firingSound = sfx;
	}

	static void SetChargeSound(sfxHandle_t sfx)
	{
		cg_weapons[WP_BLASTER].chargeSound = sfx;
	}

	static void SetMissileSound(sfxHandle_t sfx)
	{
		cg_weapons[WP_BLASTER].missileSound = sfx;
	}

	static void SetMissileHitSound(sfxHandle_t sfx)
	{
		cg_weapons[WP_BLASTER].missileHitSound = sfx;
	}

	static void SetAltFlashSound(sfxHandle_t sfx)
	{
		cg_weapons[WP_BLASTER].altFlashSound = sfx;
	}

	static void SetAltFiringSound(sfxHandle_t sfx)
	{
		cg_weapons[WP_BLASTER].altFiringSound = sfx;
	}

	static void SetAltChargeSound(sfxHandle_t sfx)
	{
		cg_weapons[WP_BLASTER].altChargeSound = sfx;
	}

	static void SetAltMuzzleEffect(fxHandle_t fx)
	{
		cg_weapons[WP_BLASTER].altMuzzleEffect = fx;
	}

	static void SetAltMissileSound(sfxHandle_t sfx)
	{
		cg_weapons[WP_BLASTER].altMissileSound = sfx;
	}

	static void SetWallImpactEffect(fxHandle_t fx)
	{
		cgs.effects.blasterWallImpactEffect = fx;
	}

	static void SetFleshImpactEffect(fxHandle_t fx)
	{
		cgs.effects.blasterFleshImpactEffect = fx;
	}

	static void SetDroidImpactEffect(fxHandle_t fx)
	{
		cgs.effects.blasterDroidImpactEffect = fx;
	}

	static void SetShotEffect(fxHandle_t fx)
	{
		cgs.effects.blasterShotEffect = fx;
	}

	static void SetAltMissileHitSound(sfxHandle_t sfx)
	{
		cg_weapons[WP_BLASTER].altMissileHitSound = sfx;
	}

	static void SetMissileModel(qhandle_t fx)
	{
		cg_weapons[WP_BLASTER].missileModel = fx;
	}

	static void SetAltMissileModel(qhandle_t fx)
	{
		cg_weapons[WP_BLASTER].altMissileModel = fx;
	}

	static void SetMissileDLight(float light)
	{
		cg_weapons[WP_BLASTER].missileDlight = light;
	}

	static void SetAltMissileDLight(float light)
	{
		cg_weapons[WP_BLASTER].altMissileDlight = light;
	}

	E11Test() {}
};

class EffectManager
{
public:
	static int Register(const char* path)
	{
		return trap_FX_RegisterEffect(path);
	}
};

void printFunc(HSQUIRRELVM v, const SQChar *s, ...) 
{ 
	va_list arglist; 
	char		text[1024];

	va_start(arglist, s); 
	vsprintf(text, s, arglist);
	CG_Printf(va("[Script] %s", text));
	va_end(arglist); 
}

void printErrorFunc(HSQUIRRELVM v, const SQChar *s, ...) 
{ 
	va_list arglist; 
	char		text[1024];

	va_start(arglist, s); 
	vsprintf(text, s, arglist);
	CG_Printf(va("[Script Error] %s", text));
	va_end(arglist); 
}

void LoadSquirrel(void)
{

	vm = sq_open(1024);
	sq_setprintfunc(vm, printFunc, printErrorFunc);
	DefaultVM::Set(vm);

	//RegisterGlobal(RegisterEffect, "RegisterEffect");
	//RegisterGlobal(RegisterSound,"RegisterSound");
	//RegisterGlobal(RegisterModel,"RegisterModel");

	//BindConstant<int>(NULL_SOUND,"NULL_SOUND");
	//BindConstant<int>(NULL_HANDLE,"NULL_MODEL");
	ConstTable(vm)
		.Const("NULL_SOUND", NULL_SOUND)
		.Const("NULL_MODEL", NULL_HANDLE)
		;

	RootTable().Bind("E11", Class<E11Test>()
		.StaticFunc("SetMuzzleEffect", &E11Test::SetMuzzleEffect)
		.StaticFunc("SetFlashSound", &E11Test::SetFlashSound)
		.StaticFunc("SetSelectSound", &E11Test::SetSelectSound)
		.StaticFunc("SetFiringSound", &E11Test::SetFiringSound)
		.StaticFunc("SetChargeSound", &E11Test::SetChargeSound)
		.StaticFunc("SetMissileSound", &E11Test::SetMissileSound)
		.StaticFunc("SetMissileHitSound", &E11Test::SetMissileHitSound)
		.StaticFunc("SetAltFlashSound", &E11Test::SetAltFlashSound)
		.StaticFunc("SetAltFiringSound", &E11Test::SetAltFiringSound)
		.StaticFunc("SetAltChargeSound", &E11Test::SetAltChargeSound)
		.StaticFunc("SetAltMuzzleEffect", &E11Test::SetAltMuzzleEffect)
		.StaticFunc("SetAltMissileSound", &E11Test::SetAltMissileSound)
		.StaticFunc("SetWallImpactEffect", &E11Test::SetWallImpactEffect)
		.StaticFunc("SetFleshImpactEffect", &E11Test::SetFleshImpactEffect)
		.StaticFunc("SetDroidImpactEffect", &E11Test::SetDroidImpactEffect)
		.StaticFunc("SetShotEffect", &E11Test::SetShotEffect)
		.StaticFunc("SetAltMissileHitSound", &E11Test::SetAltMissileHitSound)
		.StaticFunc("SetMissileModel", &E11Test::SetMissileModel)
		.StaticFunc("SetAltMissileModel", &E11Test::SetAltMissileModel)
		.StaticFunc("SetMissileDLight", &E11Test::SetMissileDLight)
		.StaticFunc("SetAltMissileDLight", &E11Test::SetAltMissileDLight)
	);

	/*SQClassDef<E11Test>("E11")
		.staticFunc(&E11Test::SetMuzzleEffect,"SetMuzzleEffect")
		.staticFunc(&E11Test::SetFlashSound,"SetFlashSound")
		.staticFunc(&E11Test::SetSelectSound,"SetSelectSound")
		.staticFunc(&E11Test::SetFiringSound,"SetFiringSound")
		.staticFunc(&E11Test::SetChargeSound,"SetChargeSound")
		.staticFunc(&E11Test::SetMissileSound,"SetMissileSound")
		.staticFunc(&E11Test::SetMissileHitSound,"SetMissileHitSound")
		.staticFunc(&E11Test::SetAltFlashSound,"SetAltFlashSound")
		.staticFunc(&E11Test::SetAltFiringSound,"SetAltFiringSound")
		.staticFunc(&E11Test::SetAltChargeSound,"SetAltChargeSound")
		.staticFunc(&E11Test::SetAltMuzzleEffect,"SetAltMuzzleEffect")
		.staticFunc(&E11Test::SetAltMissileSound,"SetAltMissileSound")
		.staticFunc(&E11Test::SetWallImpactEffect,"SetWallImpactEffect")
		.staticFunc(&E11Test::SetFleshImpactEffect,"SetFleshImpactEffect")
		.staticFunc(&E11Test::SetDroidImpactEffect,"SetDroidImpactEffect")
		.staticFunc(&E11Test::SetShotEffect,"SetShotEffect")
		.staticFunc(&E11Test::SetAltMissileHitSound,"SetAltMissileHitSound")
		.staticFunc(&E11Test::SetMissileModel,"SetMissileModel")
		.staticFunc(&E11Test::SetAltMissileModel,"SetAltMissileModel")
		.staticFunc(&E11Test::SetMissileDLight,"SetMissileDLight")
		.staticFunc(&E11Test::SetAltMissileDLight,"SetAltMissileDLight");*/

	RootTable().Bind("Effect", Table()
		.Func("Register", &EffectManager::Register)
	);
}

void CloseSquirrel(void)
{
	sq_close(vm);
}

void RunScript(const char* file)
{
	/*try
	{
		char gamepath[1024];
		char path[1024];
		trap_Cvar_VariableStringBuffer("fs_game", gamepath, sizeof(gamepath));
		strcpy(path,va("%s\\%s",gamepath,file));
		/*char files[1024];

		int fileCnt = trap_FS_GetFileList("", "/", files, sizeof(files) );

		fileHandle_t f;
		char *tempReadBuffer = (char *)BG_TempAlloc(1024);
		int len = trap_FS_FOpenFile(file, &f, FS_READ);

		trap_FS_Read(tempReadBuffer, len, f);
		tempReadBuffer[len] = 0;

		trap_FS_FCloseFile(f);*/
		
		/*SquirrelObject sqFile = SquirrelVM::CompileScript(path);
		SquirrelVM::RunScript(sqFile);
	}
	catch(SquirrelError&e)
	{
		CG_Printf("Squirrel Error: %s\n",e.desc);
	}*/
}

void RunFunction(const char* funcName)
{
	Function func(RootTable(vm), funcName);
	if(func.IsNull()) {
		CG_Printf("Squirrel Error: Problem loading func %s\n", funcName);
		return;
	}
	
	func.Execute();
	/*try
	{
		SquirrelFunction<void> startFunc = SquirrelFunction<void>(func);
		startFunc();
	}
	catch(SquirrelError&e)
	{
		CG_Printf("Squirrel Error: %s\n",e.desc);
	}*/
}

//Add RegisterSound,RegisterEffect,RegisterModel, couple different NULL_'s, and several FX_ functions