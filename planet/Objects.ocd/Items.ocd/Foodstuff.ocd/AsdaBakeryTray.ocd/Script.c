/*-- ASDA bakery tray (treat selection) --*/

#include Library_Edible

protected func Hit()
{
	Sound("Hits::GeneralHit?");
}

public func NutritionalValue() { return 42; }
public func IsKitchenProduct() { return true; }
public func GetFuelNeed() { return 45; }

local Name = "$Name$";
local Description = "$Description$";
local Collectible = 1;
local Components = {Flour = 1, Sproutberry = 2};
