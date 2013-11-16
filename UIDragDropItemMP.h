 //=============================================================================
 //  Filename:   UIDragDropItemMP.h
 //  Created by Roman E. Marchenko, vortex@gsc-game.kiev.ua
 //  Copyright 2004. GSC Game World
 //  ---------------------------------------------------------------------------
 //  Визуальная репрезентация вещи в меню покупки оружия в мультиплейере.
 //  От синглплейерной ее отличает множество дополнительных свойств
 //=============================================================================
 
 #ifndef UI_DRAG_DROP_ITEM_MP_H_
 #define UI_DRAG_DROP_ITEM_MP_H_
 
 #pragma once
 
 #include "UIDragDropItem.h"
 #include "UIDragDropList.h"
 
 class CUIBuyWeaponWnd;
 
 class CUIDragDropItemMP: public CUIDragDropItem
 {
     friend class CUIBuyWeaponWnd;
 
     typedef CUIDragDropItem inherited;
     // возможность хранения номера слота
     // в который можно переместить данную вещь
     u32             slotNum;
     // хранение номера секции оружия
     u32             sectionNum;
     // xранение порядкового номера оружия в секции
     u32             posInSection;
     // Имя секции оружия
     string128       strName;
     // Запоминаем адрес "хозяина"
     CUIDragDropList *m_pOwner;
     // Игровая стоимость вещи
     int             cost;
 public:
     CUIDragDropItemMP():    slotNum                     (0),
                             sectionNum                  (0),
                             bAddonsAvailable            (false),
                             cost                        (0),
                             m_bAlreadyPaid              (false),
                             m_bHasRealRepresentation    (false)
     {
         std::strcpy(m_strAddonTypeNames[0], "Silencer");
         std::strcpy(m_strAddonTypeNames[1], "Grenade Launcher");
         std::strcpy(m_strAddonTypeNames[2], "Scope");
 
         for (u8 i = 0; i < NUM_OF_ADDONS; ++i)
             m_pAddon[i] = NULL;
     }
     // Для слота
     void SetSlot(int slot);
     u32  GetSlot()                              { return slotNum; }
     // Получаем номер группы секций (нож - 0, пистолы - 1, et cetera)
     void SetSectionGroupID(u32 section)         { sectionNum = section; }
     u32  GetSectionGroupID()                    { return sectionNum; }
     // Функции для запоминания/возвращения имени секции в .ltx файле, этой вещи
     void SetSectionName(const char *pData)      { std::strcpy(strName, pData); }
     const char * GetSectionName() const         { return strName; }
     // Запоминаем/возвращеаем указатель на CUIDragDropList которому изначально пренадлежит
     // вещь
     void SetOwner(CUIDragDropList *pOwner)      { R_ASSERT(pOwner); m_pOwner = pOwner; }
     CUIDragDropList * GetOwner()                { return m_pOwner; }
     // Номер элемента в группе секций
     void SetPosInSectionsGroup(const u32 pos)   { posInSection = pos; }
     u32 GetPosInSectionsGroup() const           { return posInSection; }
 
     //-----------------------------------------------------------------------------/
     //  Работа с аддонами. Средствами переопределения CWeapon нужную функциональность
     //  получить не удалось
     //-----------------------------------------------------------------------------/
 
     // Структура информации о аддоне
     typedef struct tAddonInfo
     {
         // Имя секции для аддона
         std::string         strAddonName;
         // -1 - вообще нельзя приаттачить, 0 - не приаттачен, 1 - приаттачен
         int                 iAttachStatus;
         // Координаты смещения относительно иконки оружия
         int                 x, y;
         // Constructor
         tAddonInfo():       iAttachStatus(-1), x(-1), y(-1) {}
     } AddonInfo;
 
     // У каждого оружия максимум 3 аддона. Будем считать, что в массиве они идут в таком поряке:
     // Silencer, Grenade Launcher, Scope.
     static const u8     NUM_OF_ADDONS = 3;
     enum  AddonIDs      { ID_NONE = -1, ID_SILENCER = 0, ID_GRENADE_LAUNCHER, ID_SCOPE };
     AddonInfo           m_AddonInfo[NUM_OF_ADDONS];
     // Если у вещи вообще нет аддонов, то поднимаем этот флажек, для ускорения проверок
     bool                bAddonsAvailable;
     // Список название типов аддонов
     char                m_strAddonTypeNames[NUM_OF_ADDONS][25];
 
     // Аттачим/детачим аддоны
     void                AttachDetachAddon(AddonIDs iAddonIndex, bool bAttach, bool bRealRepresentationSet = false);
     void                AttachDetachAddon(CUIDragDropItemMP *pPossibleAddon, bool bAttach, bool bRealRepresentationSet = false);
     void                AttachDetachAllAddons(bool bAttach);
     bool                IsAddonAttached(int iAddonIndex) { return m_AddonInfo[iAddonIndex].iAttachStatus == 1; }
     // Проверяем а наш ли это аддон?
     AddonIDs            IsOurAddon(CUIDragDropItemMP * pPossibleAddon);
     // Переопределяем некоторые функции, которые нам нужны для коректной отрисовки оружия с аддонами
     virtual void        ClipperOn();
     virtual void        ClipperOff();
     virtual void        Draw();
     // Здесь мы храним указатели на вещи-аддоны
     CUIDragDropItemMP   *m_pAddon[NUM_OF_ADDONS];
 
     // Работа с деньгами
     void                SetCost(const int c)    { cost = c; }
     int                 GetCost()   const       { return cost; }
     // Поднимаем флаг, если уже заплачено. Нужно для правильного подсчета денег при 
     // перемещени между слотами и поясом
     bool                m_bAlreadyPaid;
     // Флаг для обозначения, что данная drag drop вещь уже имеет раельную игровую репрезентацию
     bool                m_bHasRealRepresentation;
 
     // Массив дополнительных полей которые могут быть специфичны для определенных типов вещей,
     // например для арморов храним координаты иконки в общей текстуре его представляющей
     xr_vector<float>    m_fAdditionalInfo;
 };
 
 #endif  //UI_DRAG_DROP_ITEM_MP_H_




