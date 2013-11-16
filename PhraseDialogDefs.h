 
 // PhraseDialogDefs.h
 // общие объявления для классов работающих с диалогом
 
 #pragma once
 
 #include "boost/shared_ptr.hpp"
 
 //умный указатель для диалога, так как он может 
 //совмесно использоваться несколькими объектами ()
 class CPhraseDialog;
 typedef boost::shared_ptr<CPhraseDialog> DIALOG_SHARED_PTR;
 
 
 
 //возможные типы диалогов
 typedef enum {
     eDialogTypePDA,
     eDialogTypeScenery,
     eDialogTypeStandart,
     eDialogTypeMax
 } EDialogType;
 
 //тип id фразы
 typedef int PHRASE_ID;
 
 typedef shared_str  PHRASE_DIALOG_ID;
 typedef int     PHRASE_DIALOG_INDEX;
 
 DEFINE_VECTOR(PHRASE_DIALOG_ID,     DIALOG_ID_VECTOR,       DIALOG_ID_IT);
 DEFINE_VECTOR(PHRASE_DIALOG_INDEX,  DIALOG_INDEX_VECTOR,    DIALOG_INDEX_IT);
 
 #define  NO_PHRASE_DIALOG   PHRASE_DIALOG_INDEX(-1)
 
 #define  NO_PHRASE              -1
 #define  START_PHRASE           0
 #define  START_PHRASE_STR       "0"




