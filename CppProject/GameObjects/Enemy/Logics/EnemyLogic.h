//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_ENEMYLOGIC_H
#define CPPPROJECT_ENEMYLOGIC_H


class EnemyLogic {
public:
    EnemyLogic(float _speedX, float _speedY, float _accX, float _accY, float _shootLikelyHood)
        :speedX{_speedX}, speedY{_speedY}, accX{_accX}, accY{_accY}{}
    ~EnemyLogic() = default;

    virtual void Update();
    virtual float dx();
    virtual float dy();
    virtual bool willShoot();

private:
    float speedX;
    float speedY;
    float accX;
    float accY;
};


#endif //CPPPROJECT_ENEMYLOGIC_H
