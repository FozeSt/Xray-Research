 // UICarBodyWnd.h:  диалог переложения вещей из багажника и с трупа 
 //                  себе в инвентарь
 
 #pragma once
 
 #pragma once
 
 
 class CInventory;
 
 #include "UIDialogWnd.h"
 #include "UIStatic.h"
 #include "UIButton.h"
 #include "UIDragDropItem.h"
 #include "UIDragDropList.h"
 #include "UIProgressBar.h"
 #include "UIPropertiesBox.h"
 
 #include "UIEditBox.h"
 #include "UIListWnd.h"
 #include "UIMessageBox.h"
 
 #include "UICharacterInfo.h"
 #include "UIItemInfo.h"
 
 
 class CUICarBodyWnd: public CUIDialogWnd
 {
 private:
     typedef CUIDialogWnd inherited;
 public:
     CUICarBodyWnd();
     virtual ~CUICarBodyWnd();
 
     virtual void Init();
 
     virtual void SendMessage(CUIWindow *pWnd, s16 msg, void *pData);
 
     void InitCarBody(CInventory* pOurInv,    CGameObject* pOurObject,
                      CInventory* pOthersInv, CGameObject* pOthersObject);
     
     virtual void Draw();
     virtual void Update();
         
     virtual void Show();
 
     void DisableAll();
     void EnableAll();
 
     //указатели на инвентари
     CInventory*     m_pInv;
     CInventory*     m_pOthersInv;
     CGameObject*    m_pOurObject;
     CGameObject*    m_pOthersObject;
 
 protected:
     CUIStatic           UIStaticTop;
     CUIStatic           UIStaticBottom;
 
     //информация о предмете
     CUIFrameWindow      UIDescWnd;
     CUIStatic           UIStaticDesc;
     CUIItemInfo         UIItemInfo;
 
     CUIStatic           UIOurBagWnd;
     CUIStatic           UIOthersBagWnd;
     CUIDragDropList     UIOurBagList;
     CUIDragDropList     UIOthersBagList;
 
     //информация о персонажах 
     CUIStatic           UIOurIcon;
     CUIStatic           UIOthersIcon;
     CUICharacterInfo    UICharacterInfoLeft;
     CUICharacterInfo    UICharacterInfoRight;
 
     // Кнопка "взять всё"
     CUIButton           UITakeAll;
 
     //функции, выполняющие согласование отображаемых окошек
     //с реальным инвентарем
     static bool OurBagProc(CUIDragDropItem* pItem, CUIDragDropList* pList);
     static bool OthersBagProc(CUIDragDropItem* pItem, CUIDragDropList* pList);
 
     bool ToOurBag();
     bool ToOthersBag();
     
     //произвести торговлю
     void UpdateLists();
 
     //pop-up меню вызываемое по нажатию правой кнопки
     CUIPropertiesBox UIPropertiesBox;
     //окно с сообщением
     CUIMessageBox    UIMessageBox;
 
     DD_ITEMS_VECTOR m_vDragDropItems;
 
     //для сортировки вещей
     TIItemList ruck_list;
 
     //элемент с которым работают в текущий момент
     PIItem m_pCurrentItem;
     CUIDragDropItem* m_pCurrentDragDropItem;
 
     //устанавливает текущий предмет
     void        SetCurrentItem(CInventoryItem* pItem);
 
     // Взять все
     void        TakeAll();
 };




