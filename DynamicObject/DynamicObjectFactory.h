#pragma once


#include "map"
#include "string"
#include "memory"
#include "functional"
#include "DynamicObjectBase.h"

class DynamicObjectFactory {
    using DynamicCreateObject = std::function<std::unique_ptr<DynamicObjectBase> ()>;
public:
    static DynamicObjectFactory *Instance();

    std::unique_ptr<DynamicObjectBase> CreateObject(const std::string &ObjectName);

    void Register(const std::string &ObjectName, DynamicCreateObject Func);

    void UnRegister(const std::string &ObjectName);

protected:
    DynamicObjectFactory() = default;

    ~DynamicObjectFactory() = default;

    std::map<std::string, DynamicCreateObject> mCreateDynamicObjectFuncMap;
};


