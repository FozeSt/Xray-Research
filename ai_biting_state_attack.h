 #pragma once
 
 class CEntityAlive;
 
 class CBitingAttack : public IState {
     typedef IState inherited;
     CAI_Biting  *pMonster;
 
     enum {
         ACTION_RUN,
         ACTION_ATTACK_MELEE,
         ACTION_FIND_ENEMY,
         ACTION_STEAL,
         ACTION_THREATEN,
         ACTION_ENEMY_POSITION_APPROACH,
         ACTION_ENEMY_WALK_AWAY,
         ACTION_ROTATION_JUMP,
         ACTION_ATTACK_RUN,
         ACTION_PSI_ATTACK,
     } m_tAction,m_tPrevAction;
 
     const CEntityAlive *enemy;
 
     float           m_fDistMin;                     
     float           m_fDistMax;                     
     float           dist;                           // текущая дистанция
 
     TTime           m_dwFaceEnemyLastTime;          // время последней установки target.yaw при развороте лицом к противнику 
 
     bool            bCanThreaten;                   // может пугать
     TTime           ThreatenTimeStarted;            // время начала Threaten
     TTime           ThreatenMinDelay;
     
     bool            bEnableBackAttack;              // можно использовать BackAttack 
 
     TTime           LastTimeRebuild;                // время последнего обновления пути
 
     Flags32         init_flags;
     Flags32         frame_flags;
     Flags32         flags;
 
     bool            b_in_threaten;
 
     CJumping        *pJumping;
 
     TTime           next_rot_jump_enabled;
     TTime           time_start_walk_away;           // время начала состояния ACTION_ENEMY_WALK_AWAY (монстр не может добраться до жертвы)
     
     TTime           time_next_attack_run;
     TTime           time_next_psi_attack;
 
 public: 
                     CBitingAttack       (CAI_Biting *p);
 
     virtual void    Init                ();
     virtual void    Run                 ();
     virtual void    Done                ();
     
     virtual bool    CheckCompletion     ();
 
             bool    CheckStartThreaten  ();
             bool    CheckEndThreaten    ();
             bool    CheckThreaten       ();
 
             bool    CheckSteal          ();
             Fvector RandomPos           (Fvector pos, float R);
 
             bool    CanAttackFromBack   ();
 
             void    UpdateInitFlags     (); 
             void    UpdateFrameFlags    (); 
 
             bool    CheckRotationJump   ();
 
             bool    CanAttackRun        ();
 
             bool    CheckPsiAttack      ();
 
 
     virtual bool    GetStateAggressiveness  (){return true;}
 };




