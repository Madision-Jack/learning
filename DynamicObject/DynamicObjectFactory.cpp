#include "DynamicObjectFactory.h"

DynamicObjectFactory *DynamicObjectFactory::Instance() {
    static DynamicObjectFactory Ins;

    return &Ins;
}

std::unique_ptr<DynamicObjectBase> DynamicObjectFactory::CreateObject(const std::string &ObjectName) {
    if (mCreateDynamicObjectFuncMap.find(ObjectName) != mCreateDynamicObjectFuncMap.end()) {
        DynamicCreateObject Func = mCreateDynamicObjectFuncMap[ObjectName];
        return Func();
    }
    return nullptr;
}

void DynamicObjectFactory::Register(const std::string &ObjectName, DynamicCreateObject Func) {
    if (mCreateDynamicObjectFuncMap.find(ObjectName) == mCreateDynamicObjectFuncMap.end()) {
        mCreateDynamicObjectFuncMap[ObjectName] = Func;
    }
}

void DynamicObjectFactory::UnRegister(const std::string &ObjectName) {
    if (mCreateDynamicObjectFuncMap.find(ObjectName) != mCreateDynamicObjectFuncMap.end()) {
        mCreateDynamicObjectFuncMap.erase(ObjectName);
    }
}
