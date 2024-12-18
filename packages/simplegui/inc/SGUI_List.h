#ifndef __INCLUDE_SGUI_List_H__
#define __INCLUDE_SGUI_List_H__
#include "SGUI_Common.h"
#include "SGUI_Basic.h"
#include "SGUI_Text.h"
#include "SGUI_ScrollBar.h"
#include "SGUI_ItemsBase.h"

#ifdef __cplusplus
extern "C"{
#endif
typedef struct
{
    SGUI_RECT                   stLayout;
    SGUI_ITEMS_BASE             stItems;
    SGUI_CSZSTR                 szTitle;
    SGUI_SCROLLBAR_STRUCT       stScrollBar;
    const SGUI_FONT_RES*        pstFontRes;
}SGUI_LIST;
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
#endif
void                    SGUI_List_Initialize(SGUI_LIST* pstObj, const SGUI_RECT* cpstLayout, const SGUI_FONT_RES* pstFontRes, SGUI_CSZSTR cszTitle, SGUI_ITEMS_ITEM* pstItemsData, SGUI_INT iItemsCount);
void                    SGUI_List_Repaint(SGUI_SCR_DEV* pstDeviceIF, SGUI_LIST* pstObj);
void                    SGUI_List_RepaintItems(SGUI_SCR_DEV* pstDeviceIF, SGUI_LIST* pstObj);
void                    SGUI_List_Resize(SGUI_LIST* pstObj, const SGUI_RECT* pstNewLayout);
SGUI_ITEMS_ITEM*        SGUI_List_RemoveItem(SGUI_LIST* pstObj, SGUI_INT iRemoveIndex);
SGUI_ITEMS_ITEM*        SGUI_List_InsertItem(SGUI_LIST* pstObj, SGUI_ITEMS_ITEM* pstNewItem, SGUI_INT iIndex);
#ifdef __cplusplus
}
#endif

#define                 SGUI_List_Count(/* SGUI_LIST */OBJ) \
                            (SGUI_ItemsBase_Count(&((OBJ)->stItems)))
#define                 SGUI_List_Selecte(/* SGUI_LIST */OBJ, /* SGUI_INT */IDX) \
                            (SGUI_ItemsBase_Selecte(&((OBJ)->stItems), IDX))
#define                 SGUI_List_SelecteFirst(/* SGUI_LIST */OBJ) \
                            {SGUI_ItemsBase_SelecteFirst(&((OBJ)->stItems))}
#define                 SGUI_List_SelecteLast(/* SGUI_LIST */OBJ) \
                            {SGUI_ItemsBase_SelecteLast(&((OBJ)->stItems))}
#define                 SGUI_List_GetSelection(/* SGUI_LIST */OBJ) \
                            (SGUI_ItemsBase_GetSelection(&((OBJ)->stItems)))

#endif // __INCLUDE_SGUI_List_H__
