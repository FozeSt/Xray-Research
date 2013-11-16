 #pragma once
 
 #include "telekinetic_object.h"
 #include "../PHObject.h"
 
 
 
 
 class CTelekinesis : public CPHUpdateObject {
     
     DEFINE_VECTOR(CTelekineticObject*,TELE_OBJECTS,TELE_OBJECTS_IT);
     TELE_OBJECTS            objects;
     bool                    active;
 
 public:
                 CTelekinesis            (){active=false;}
     virtual ~CTelekinesis           (){}
 
             // allocates relevant TelekineticObject
 
 
             // активировать объект
             void    activate            (CPhysicsShellHolder *obj, float strength, float height, u32 max_time_keep);
 
             // деактивировать все объекты
             void    deactivate          ();
 
             //clear objects (does not call release, but call switch to TS_None)
             void    clear_deactivate    ();
             // clear 
 virtual     void    clear               ();
             // деактивировать объект
             void    deactivate          (CPhysicsShellHolder *obj);
             void    remove_object       (TELE_OBJECTS_IT it);
             void    remove_object       (CPhysicsShellHolder *obj);
             // бросить объект 'obj' в позицию 'target'
             void    fire                (CPhysicsShellHolder *obj, const Fvector &target);
     
             // бросить все объекты в позицию 'target'
             void    fire                (const Fvector &target);
             
             // бросить объект 'obj' в позицию 'target' с учетом коэф силы 
             void    fire                (CPhysicsShellHolder *obj, const Fvector &target, float power);
 
             // вернуть активность телекинеза
             bool    is_active           () {return active;}
 
             // вернуть активность объекта       
             bool    is_active_object    (CPhysicsShellHolder *obj);
 
             // вернуть количество кониролируемых объектов
             u32     get_objects_count   ();
             
             // вернуть объект по индексу в массиве
             // a    copy of the object!
 CTelekineticObject  get_object_by_index (u32 index) {VERIFY(objects.size() > index); return *objects[index];}
                     
             // обновить состоняие на shedule_Update         
             void    schedule_update     ();
 protected:
     virtual CTelekineticObject* alloc_tele_object(){return xr_new<CTelekineticObject>();}
 private:
 
     // обновление на шагах физики
     virtual void    PhDataUpdate        (dReal step);
     virtual void    PhTune              (dReal step);
     
 
 };
 




