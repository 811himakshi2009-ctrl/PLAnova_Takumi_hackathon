/*-- ASDA meal deal (sandwich) --*/

#include Library_Edible

protected func Hit()
{
	Sound("Hits::GeneralHit?");
}

public func NutritionalValue() { return 55; }
public func IsKitchenProduct() { return true; }
public func GetFuelNeed() { return 50; }

local Name = "$Name$";
local Description = "$Description$";
local Collectible = 1;
local Components = {Bread = 1, Sproutberry = 1};
