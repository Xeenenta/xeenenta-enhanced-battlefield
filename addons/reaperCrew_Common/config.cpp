class CfgPatches
{
	class ReaperCrew_Common
	{
		units[] = {"reaperCrew_moduleGarrison", "reaperCrew_moduleDisarmPlayers", "reaperCrew_moduleScanArea", "reaperCrew_moduleResupplyPoint", "reaperCrew_modulePrimaryFix"};
		weapons[]={};
		requiredVersion=1;
		requiredAddons[]=
		{};
	};
};
class CfgMods
{
	class Mod_Base;
	class ReaperCrew_Common: Mod_Base
	{
		logo="reaperCrew_Common\data\reaperLogo.paa";
	};
	author="Reaper Crew";
	timepacked="1618105293";
};
class UniformSlotInfo
{
	slotType=0;
	linkProxy="-";
};
class cfgFactionClasses
{
	class NO_CATEGORY;
    class reaperCrew //Faction Calling Name
    {
     displayName = "Reaper Crew"; //Faction name in-game
     icon = "reaperCrew_Common\data\reaperLogo.paa"; //Path to texture next to the faction name in editor "PBOname\filename.paa"
     priority = 1; //How far down it is on the menu
     side = 1; // 1 Blufor 2 opfor 3 independant i think.
     scope = 2;
	 scopeCurator = 2;
    };
	class reaperCrew_ModulesLogistics: NO_CATEGORY
	{
		displayName = "Reaper Crew - Logistics";
		scope = 2;
		scopeCurator = 2;
	};
	class reaperCrew_ModulesAI: NO_CATEGORY
	{
		displayName = "Reaper Crew - AI";
		scope = 2;
		scopeCurator = 2;
	};
	class reaperCrew_ModulesPlayers: NO_CATEGORY
	{
		displayName = "Reaper Crew - Players";
		scope = 2;
		scopeCurator = 2;
	};
};
class CfgEditorCategories
{
	class NO_CATEGORY;
	class reaperCrew // Category class, you point to it in editorCategory property
	{
		displayName = "Reaper Crew"; // Name visible in the list
		scope = 2;
		scopeCurator = 2;
	};
	class reaperCrew_ModulesLogistics: NO_CATEGORY
	{
		displayName = "Reaper Crew - Logistics";
		scope = 2;
		scopeCurator = 2;
	};
	class reaperCrew_ModulesAI: NO_CATEGORY
	{
		displayName = "Reaper Crew - AI";
		scope = 2;
		scopeCurator = 2;
	};
	class reaperCrew_ModulesPlayers: NO_CATEGORY
	{
		displayName = "Reaper Crew - Players";
		scope = 2;
		scopeCurator = 2;
	};
};
class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class AttributesBase
		{
			class Default;
			class Edit;					// Default edit box (i.e., text input field)
			class Combo;				// Default combo box (i.e., drop-down menu)
			class Checkbox;				// Default checkbox (returned value is Bool)
			class CheckboxNumber;		// Default checkbox (returned value is Number)
			class ModuleDescription;	// Module description
			class Units;				// Selection of units on which the module is applied
		};
		class ModuleDescription
		{
			class AnyBrain;
		};
	};
	class reaperCrew_module_base: Module_F
	{	
		icon = "\reaperCrew_Common\data\insignia.paa";
		isGlobal = 0;
		isTriggerActivated = 0;
		isDisposable = 1;
		is3DEN = 0;	
		curatorCanAttach = 1;
		scope = 1;
		scopeCurator = 1;
		functionPriority = 1;
	};
	class reaperCrew_moduleDisarmPlayers: reaperCrew_module_base
	{
		displayName = "Disarm all players";
		function = "reaperCrew_fnc_disarmModuleInit";
		category = "reaperCrew_ModulesPlayers";
		scope = 1;
		scopeCurator = 2;
		isGlobal = 0;
	};
	// class reaperCrew_moduleScanArea: reaperCrew_module_base
	// {
	// 	displayName = "Scan area";
	// 	function = "reaperCrew_fnc_scanAreaModuleInit";
	// 	category = "reaperCrew_ModulesAI";
	// 	scope = 1;
	// 	scopeCurator = 2;
	// 	isGlobal = 1;
	// 	isTriggerActivated = 0;
	// 	curatorCanAttach = 1;
	// };
	// class reaperCrew_moduleGarrison: reaperCrew_module_base
	// {
	// 	displayName = "Garrison Area (5 per building, 50m radius)";
	// 	function = "reaperCrew_fnc_garrisonModuleInit";
	// 	category = "reaperCrew_ModulesAI";
	// 	scope = 1;
	// 	scopeCurator = 2;
	// };
	// class reaperCrew_modulePrimaryFix: reaperCrew_module_base
	// {
	// 	displayName = "Primary Weapon Fix";
	// 	function = "reaperCrew_fnc_primaryWeaponFix";
	// 	category = "reaperCrew_ModulesAI";
	// 	scope = 2;
	// 	scopeCurator = 2;
	// 	isGlobal = 1;
	// 	isTriggerActivated = 0;
	// 	curatorCanAttach = 1;
	// };
};
class CfgFunctions
{
	class reapercrew_common
	{
		class Effects
		{
			file = "\reaperCrew_Common\functions";
			class CoverMap{};
			class setACRESettings{
				preInit = 1;
				postInit = 1;
				preStart = 1;
			};
			class setPersonalACRESettingsLocal{};
			class setPersonalACRESettingsServer{
				postInit = 1;
			};
			class setUnitInsigniaGlobal{
				postInit = 1;
			};
			class setUnitInsigniaLocal{};
		};
	};
};