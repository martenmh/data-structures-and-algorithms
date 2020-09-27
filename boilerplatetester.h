//
// Created by marten on 30-08-20.
//

#ifndef DATA_STRUCTURES_BOILERPLATETESTER_H
#define DATA_STRUCTURES_BOILERPLATETESTER_H

#include <cassert>
struct verify;
class tester {
    friend verify;
    static int livecount;
    const tester* self;
public:
    tester() :self(this) {++livecount;}
    tester(const tester&) :self(this) {++livecount;}
    ~tester() {assert(self==this);--livecount;}
    tester& operator=(const tester& b) {
        assert(self==this && b.self == &b);
        return *this;
    }
    void cfunction() const {assert(self==this);}
    void mfunction() {assert(self==this);}
};
int tester::livecount=0;
struct verify {
    ~verify() {assert(tester::livecount==0);}
}verifier;

#endif //DATA_STRUCTURES_BOILERPLATETESTER_H
