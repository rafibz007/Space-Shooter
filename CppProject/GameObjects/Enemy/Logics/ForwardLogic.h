//
// Created by rafibz007 on 19.05.22.
//

#ifndef CPPPROJECT_FORWARDLOGIC_H
#define CPPPROJECT_FORWARDLOGIC_H


#include "EnemyLogic.h"

class ForwardLogic: public EnemyLogic {
public:
    ForwardLogic(): EnemyLogic(-150, 0, 0, 0, 0.5) {}

};


#endif //CPPPROJECT_FORWARDLOGIC_H
