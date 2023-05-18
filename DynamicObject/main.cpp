#include "Register.h"
#include "DynamicObjectBase.h"
#include "DynamicObjectFactory.h"
#include "iostream"

class TestDynamicObject : public DynamicObjectBase {
public:
    TestDynamicObject() { std::cout << __func__ << std::endl; }

    ~TestDynamicObject() override { std::cout << __func__ << std::endl; }

    void Initialise() override;

    void Release() override;
};

REGISTER_DYNAMICOBJECT(TestDynamicObject)


void TestDynamicObject::Initialise() {
    printf("TestDynamicObject Initialise\n");
}

void TestDynamicObject::Release() {
    printf("TestDynamicObject Release\n");
}


class TestDynamicObject1 : public DynamicObjectBase {
public:
    TestDynamicObject1() { std::cout << __func__ << std::endl; }

    ~TestDynamicObject1() override { std::cout << __func__ << std::endl; }

    void Initialise() override;

    void Release() override;
};

REGISTER_DYNAMICOBJECT(TestDynamicObject1)


void TestDynamicObject1::Initialise() {
    printf("TestDynamicObject1 Initialise\n");
}

void TestDynamicObject1::Release() {
    printf("TestDynamicObject1 Release\n");
}


class TestDynamicObject2 : public DynamicObjectBase {
public:
    TestDynamicObject2() { std::cout << __func__ << std::endl; }

    ~TestDynamicObject2() override { std::cout << __func__ << std::endl; }

    void Initialise() override;

    void Release() override;

};

REGISTER_DYNAMICOBJECT(TestDynamicObject2)


void TestDynamicObject2::Initialise() {
    printf("TestDynamicObject2 Initialise\n");
}

void TestDynamicObject2::Release() {
    printf("TestDynamicObject2 Release\n");
}


int main() {
    std::unique_ptr<DynamicObjectBase> Obj = DynamicObjectFactory::Instance()->CreateObject("TestDynamicObject");

    Obj->Initialise();
    Obj->Release();

    std::unique_ptr<DynamicObjectBase> Obj1 = DynamicObjectFactory::Instance()->CreateObject("TestDynamicObject1");

    Obj1->Initialise();
    Obj1->Release();

    std::unique_ptr<DynamicObjectBase> Obj2 = DynamicObjectFactory::Instance()->CreateObject("TestDynamicObject2");

    Obj2->Initialise();
    Obj2->Release();

    return 0;
}
