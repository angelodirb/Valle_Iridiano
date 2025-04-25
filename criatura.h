//
// Created by HOME on 21/04/2025.
//

#ifndef CRIATURA_H
#define CRIATURA_H



class criatura {
public:
    virtual void actuar() = 0;
    virtual void reproducirse() = 0;
    virtual void moverse() = 0;
    virtual void morir() = 0;
    virtual ~criatura();
};



#endif //CRIATURA_H
