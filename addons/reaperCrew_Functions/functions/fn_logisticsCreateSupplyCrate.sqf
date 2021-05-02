/*
 * Author: Xeenenta
 * Create a standard ammo crate
 *
 * Arguments:
 * 0: Object <OBJECT> 
 *
 * Return Value:
 * None
 *
 * Example:
 * [_object] call reapercrew_fnc_logisticsCreateSupplyCrate
 *
 * Public: No
 */

params ["_resupplyObject", "_crateType"];

_classname = "";

switch (_crateType) do {
	case "smallArms": {
		_classname = "ReaperCrew_PlatoonAmmo_Base";
	};
	case "medical": {
		_classname = "ReaperCrew_PlasticCase_Medical";
	};
	case "82Mortar": {
		_classname = "ReaperCrew_Shells82";
	};
};

// Crate Variables
_supplyCrate = _classname createVehicle position player;
[_supplyCrate, 8] call ace_cargo_fnc_setSize;
[_resupplyObject, _supplyCrate, [([-10,10] call BIS_fnc_randomInt), -3, 0], 0] call BIS_fnc_relPosObject;
_supplyCrate enableSimulationGlobal true;

if (_crateType == "smallArms") then {
	[_supplyCrate] call reapercrew_fnc_logisticsPopulateSupplyCrate;
};