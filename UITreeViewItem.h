 //=============================================================================
 //  Filename:   UITreeViewItem.h
 //  Created by Roman E. Marchenko, vortex@gsc-game.kiev.ua
 //  Copyright 2004. GSC Game World
 //  ---------------------------------------------------------------------------
 //  TreeView Item class
 //=============================================================================
 
 #ifndef UI_TREE_VIEW_ITEM_H_
 #define UI_TREE_VIEW_ITEM_H_
 
 #pragma once
 
 #include "UIListItem.h"
 
 class CUIListWnd;
 
 class CUITreeViewItem: public CUIListItem
 {
     typedef CUIListItem inherited;
     // Являемся ли мы началом подыерархии
     bool            isRoot;
     // Если мы рут, то этот флаг показывает открыта наша подыерархия или нет
     bool            isOpened;
     // Смещение в пробелах
     int             iTextShift;
     // Кому мы пренадлежим
     CUITreeViewItem *pOwner;
 public:
     void            SetRoot(bool set);
     bool            IsRoot() const                      { return isRoot; }
 
     // Устанавливаем смещение текста
     void            SetTextShift(int delta)             { iTextShift += delta; }
 
     // Владелец
     CUITreeViewItem * GetOwner() const                  { return pOwner; }
     void            SetOwner(CUITreeViewItem *owner)    { pOwner = owner; }
 protected:
     // Функция вызываемая при изменении свойства рута
     // для изменения визуального представления себя
     virtual void    OnRootChanged();
 public:
     // Раксрыть/свернуть локальнцю иерархию
     void            Open();
     void            Close();
     bool            IsOpened() const                    { return isOpened; }
 protected:
     // Функция вызываемая при изменении cостояния открыто/закрыто 
     // для изменения визуального представления себя
     virtual void    OnOpenClose();
 public:
     
     // Список элементов, которые уровнем ниже нас
     typedef         xr_vector<CUITreeViewItem*>     SubItems;
     typedef         SubItems::iterator              SubItems_it;
     SubItems        vSubItems;
 
     CUIStatic       UIBkg;
 
     // Добавить элемент
     void AddItem(CUITreeViewItem *pItem);
     // Удалить все
     void DeleteAllSubItems();
     // Найти элемент с заданным именем
     // Return:  указатель на элемент, если нашли, либо NULL в противном случае
     CUITreeViewItem * Find(LPCSTR text) const;
     // Найти заданный элемент
     // Return:  указатель на элемент, если нашли, либо NULL в противном случае
     CUITreeViewItem * Find(CUITreeViewItem *pItem) const;
     // Вернуть иерархию от верха до текущего элемента в виде строки-пути
     // Рутовые элементы заканчиваются символом "/"
     std::string GetHierarchyAsText();
 
     // Redefine some stuff
     // ATTENTION! Для корректного функционирования значков [+-] вызов SetText
     // Должен предшествовать SetRoot
     virtual void SetText(LPCSTR str);
     virtual void SendMessage(CUIWindow* pWnd, s16 msg, void* pData);
 
     // Ctor and Dtor
     CUITreeViewItem();
     ~CUITreeViewItem();
 };
 
 //  Function for automatic tree hierarchy creation
 
 DEF_VECTOR(GroupTree, shared_str);
 
 
 void CreateTreeBranch(shared_str nestingTree, shared_str leafName, CUIListWnd *pListToAdd, int leafProperty,
                       CGameFont *pRootFont, u32 rootColor, CGameFont *pLeafFont, u32 leafColor);
 
 #endif  //UI_TREE_VIEW_ITEM_H_




