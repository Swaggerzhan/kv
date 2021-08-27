//
// Created by Swagger on 2021/8/27.
//

#include "../include/timestamp.h"

TimeStamp::TimeStamp() {

}


TimeStamp::~TimeStamp() {

}


// TODO:impl now
TimeStamp TimeStamp::now() {
    TimeStamp* t = new TimeStamp();
    return *t;
}
