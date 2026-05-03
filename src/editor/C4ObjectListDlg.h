/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2013-2016, The PLAnova Team and contributors
 *
 *
 *
 */

/* A window listing all objects in the game */

#ifndef INC_C4ObjectListDlg
#define INC_C4ObjectListDlg


#include "object/C4ObjectList.h"

class C4ObjectListDlg: public C4ObjectListChangeListener
{
#ifdef WITH_QT_EDITOR
	class C4ConsoleQtObjectListModel *view_model; // forward into Qt object list model
#endif
public:
	C4ObjectListDlg();
	~C4ObjectListDlg() override;
#ifdef WITH_QT_EDITOR
	void SetModel(C4ConsoleQtObjectListModel *new_view_model) { view_model = new_view_model;  }
#endif
	
	void Execute();
	void Open();
	void Update(class C4EditCursorSelection &rSelection);

	void OnObjectRemove(C4ObjectList * pList, C4ObjectLink * pLnk) override;
	void OnObjectAdded(C4ObjectList * pList, C4ObjectLink * pLnk) override;
	void OnObjectRename(C4ObjectList * pList, C4ObjectLink * pLnk) override;
	void OnObjectContainerChanged(C4Object *obj, C4Object *old_container, C4Object *new_container) override;
};

#endif //INC_C4ObjectListDlg
