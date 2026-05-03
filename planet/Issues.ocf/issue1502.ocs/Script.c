/*	
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2015, The PLAnova Team and contributors
 */

/* Issue #1502: Translate() does not fall back when a string has no translation in the current object */

func Initialize()
{
	// Setup testing environment
	var obj = CreateObject(Dummy, 100, 100, NO_OWNER);
	obj->SetName("obj");

	TEST("Translate() outside of object context should return translations from the containing script");
	EXPECT_EQ("Translation1", Translate("Original1"));
	EXPECT_EQ("Translation2", Translate("Original2"));

	TEST("Translate() in object context should return translations from the object");
	EXPECT_EQ("Dummy", obj->Translate("Name"));

	TEST("Translate() in object context should return translations from the containing script if no translation exists inside the object");
	EXPECT_EQ("Translation1", obj->Translate("Original1"));

	TEST("Translate() outside of object context should return the original string if no translation exists in the containing script");
	EXPECT_EQ("Original3", Translate("Original3"));

	END_TEST();
	GameOver();
}
